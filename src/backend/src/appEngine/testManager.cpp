// Begin file testManager.cpp

#include "testManager.h"
#include <QDebug>
#include <QRandomGenerator>

TestManager::TestManager(){
    // Constructor stub
    // qDebug() << "[*] TestManager was created";
    mDataManager = DataManager::getInstance();
    QRandomGenerator::system()->generate();
}

TestManager::~TestManager(){
    // Destructor stub
}

QString TestManager::createSession(const QString& challengeId){
    // OpenAPI::OAISession pubSessionInfo;
    QJsonObject testSessionInfo;

    QString sessionId;
    QJsonArray jsonArray = mDataManager->getAllChallenges(challengeId);
    QJsonDocument challengeJsonDoc(jsonArray[0].toObject());
    if (jsonArray.size() > 0){

        sessionId = QUuid::createUuid().toString(QUuid::WithoutBraces);
        testSessionInfo["id"]     = sessionId;
        testSessionInfo["status"] = "Pending";
        testSessionInfo["beginAt"] = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        testSessionInfo["endAt"]   = "";
        testSessionInfo["result"]  = "";

        QJsonObject userInfo;
        userInfo["id"]    = "00000000-0000-0000-0000-000000000001";
        userInfo["name"]  = "Petrov I.D.";
        userInfo["group"] = "Some group of people";
        testSessionInfo["userInfo"] = userInfo;

        QJsonObject testInfo;
        testInfo["totalQuestions"]  = challengeJsonDoc["qIDs"].toArray().size();
        testInfo["testType"]        = challengeJsonDoc["testType"];
        testInfo["section"]         = challengeJsonDoc["section"];
        testInfo["subsection"]      = challengeJsonDoc["subsection"];
        testInfo["testAnnotation"]  = challengeJsonDoc["testAnnotation"];
        testInfo["doneQuestions"]   = 0;
        testSessionInfo["testInfo"] = testInfo;

        // Session private data
        testSessionInfo["nextQuestionsId"] = challengeJsonDoc["qIDs"];
        testSessionInfo["prevQuestionsId"] = QJsonArray();

        // Write data to file
        mDataManager->addSessionToFile(testSessionInfo);

        // qDebug() << "SessionInfo Debug";
        // qDebug() << testSessionInfo;
    }
    else {
        qDebug() << "Challenge" << challengeId << "does not exist!";
        sessionId = "n/a";
    }
    return sessionId;
}

OpenAPI::OAIQuestion TestManager::getNextQuestion(const QString& sessionId, bool hideAnswer){
    QJsonObject sessionJsonData = mDataManager->getSession(sessionId);
    if (sessionJsonData.isEmpty() or sessionJsonData["status"].toString() == "Completed"){
        OpenAPI::OAIQuestion res;
        qDebug() << "[EE] No questions for session" << sessionId;
        return res;
    }

    // size -> random index -> value by random index -> OAIQuestion object
    int nextQuestionArraySize = sessionJsonData["nextQuestionsId"].toArray().size();
    int randomQuestionId = QRandomGenerator::system()->bounded(nextQuestionArraySize);
    QString nextQuestionsGid = sessionJsonData["nextQuestionsId"].toArray()[randomQuestionId].toString();
    QJsonObject nextQuestionData = mDataManager->getQuestion(nextQuestionsGid, hideAnswer);

    OpenAPI::OAIQuestion res;
    res.fromJsonObject(nextQuestionData);

    return res;
}

bool TestManager::isSessionExtists(const QString& session_id){
    bool res = false;
    QJsonObject sessionData(mDataManager->getSession(session_id));

    if (!sessionData.isEmpty()){
        res = true;
    }

    return res;
}

bool TestManager::isSessionPending(const QString& session_id){
    bool res = false;
    QJsonObject sessionData(mDataManager->getSession(session_id));

    if (sessionData["status"].toString() == "Pending" ){
        res = true;
    }

    return res;
}

bool TestManager::checkAnswer(const QJsonObject answerData){
    bool res = true;
    QJsonArray answersJsonArrayData;

    if (isSessionExtists(answerData["session_id"].toString())){

        if (isSessionPending(answerData["session_id"].toString())){
            res = true;
        }
        else {
            qDebug() << "[EE] Answer Error. Session" << answerData["session_id"] << "completed. Break answer";
            res = false;
        }
    }
    else {
        qDebug() << "[EE] Answer Error.  User session" << answerData["session_id"] << "doesn't exist";
        res = false;
    }

    return res;
}

bool TestManager::markQuestionAsDone(const QJsonObject answer){
    bool res = false;
    QJsonArray allSessionsDataA(mDataManager->getAllSessions());

    for (int sIdx = 0; sIdx < allSessionsDataA.size(); sIdx++){
        QJsonObject tempSessionJsonObject = allSessionsDataA[sIdx].toObject();
        if (tempSessionJsonObject["id"].toString().toLower() == answer["session_id"].toString().toLower()){
            QJsonArray tmpNextQuestionsIdArray(tempSessionJsonObject["nextQuestionsId"].toArray());
            QJsonArray tmpPrevQuestionsIdArray(tempSessionJsonObject["prevQuestionsId"].toArray());

            for (int idx = 0; idx < tmpNextQuestionsIdArray.size(); idx++){
                if (tmpNextQuestionsIdArray[idx] == answer["question_id"]){
                    // Remove question from "Next Questions"
                    tmpNextQuestionsIdArray.removeAt(idx);
                    tempSessionJsonObject["nextQuestionsId"] = tmpNextQuestionsIdArray;

                    // Insert question to "Previous Questions"
                    tmpPrevQuestionsIdArray.append(answer["question_id"]);
                    tempSessionJsonObject["prevQuestionsId"] = tmpPrevQuestionsIdArray;

                    // Increase done questions count
                    QJsonObject tmpTestInfo(tempSessionJsonObject["testInfo"].toObject());
                    tmpTestInfo["doneQuestions"] = tmpTestInfo["doneQuestions"].toInt() + 1;
                    tempSessionJsonObject["testInfo"] = tmpTestInfo;

                    // Check session status. Pending or completed
                    int totalQuestions = tmpTestInfo["totalQuestions"].toInt();
                    int doneQuestions  = tmpTestInfo["doneQuestions"].toInt();
                    if (totalQuestions == doneQuestions){
                        tempSessionJsonObject["status"] = "Completed";

                        // Calculating test result
                        QJsonValue sessionId = answer["session_id"];
                        QJsonArray questionsId = tempSessionJsonObject["prevQuestionsId"].toArray();
                        QJsonValue testResult = getTestResults(sessionId, questionsId);
                        tempSessionJsonObject["result"] = testResult;

                        // Push "end time" to session data
                        QDateTime currentDateTime = QDateTime::currentDateTime();
                        QString strDateTime = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
                        tempSessionJsonObject["endAt"] = QJsonValue(strDateTime);
                    }
                    break;
                }
            }
            allSessionsDataA[sIdx] = tempSessionJsonObject;

            QJsonObject sessionsJsonObj;
            sessionsJsonObj["Sessions"] = allSessionsDataA;

            mDataManager->putAllSessionsToFile(sessionsJsonObj);
            res = true;
            break;
        }
    }
    return res;
}

QJsonValue TestManager::getTestResults(const QJsonValue& sessionId, const QJsonArray& questionsId){
    double res;
    double qCount;
    // five-point scale
    double scaleFactor = 5.0;

    QString sId = sessionId.toString();
    QJsonArray allQuestions;
    QJsonArray doneAnswers;

    allQuestions = mDataManager->getAllQuestions();
    doneAnswers = mDataManager->getSessionAnswers(sId);

    QJsonObject iAnswer, iQuestion;
    for (QJsonArray::iterator itAns = doneAnswers.begin(); itAns != doneAnswers.end(); itAns++){
        iAnswer = itAns->toObject();
        QString answerQuestionId = iAnswer["qId"].toString().toLower();

        // TODO Rewrite over getQuestion(const QString&);
        for (QJsonArray::iterator itQuestion = allQuestions.begin(); itQuestion !=allQuestions.end(); itQuestion++){
            iQuestion = itQuestion->toObject();
            QString qQuestionId = iQuestion["id"].toString().toLower();

            if (answerQuestionId == qQuestionId){
                // Found done question in question db
                QString qType = iQuestion["type"].toString().toLower();

                // Single choice
                if (qType == "single-choice"){
                    res += this->checkSingleChoiceQuestion(iAnswer, iQuestion);
                    break;
                }

                // Multiple choice
                if (qType == "multiple-choice"){
                    res += this->checkMultipleChoiceQuestion(iAnswer, iQuestion);
                    break;
                }
            }
        }
    }

    QJsonObject sessionInfo = mDataManager->getSession(sId);
    qCount = sessionInfo["testInfo"].toObject()["totalQuestions"].toDouble();

    res /= qCount;
    res *= scaleFactor;
    res = std::round(res * 10) / 10;

    return QJsonValue(res);
}

double TestManager::checkSingleChoiceQuestion(const QJsonObject& iAnswer, const QJsonObject& iQuestion){
    double res = 0.0;
    QJsonArray uAnswers = iAnswer["answers"].toArray();
    QJsonArray qAnswers = iQuestion["answers"].toArray();

    // Get ID of first/singe answer for checked question
    QJsonObject fAnswer = uAnswers.begin()->toObject();
    QString fAnswerId = fAnswer["id"].toString().toLower();

    for (QJsonArray::iterator qIt = qAnswers.begin(); qIt != qAnswers.end(); qIt++){
        QJsonObject qAnswer = qIt->toObject();
        QString qAnswerId = qAnswer["id"].toString().toLower();
        if (qAnswerId == fAnswerId){
            if (qAnswer["isRight"].toBool() == true){
                // One ball for right single-choise question
                res = 1.0;
            }
        }
    }
    return res;
}

double TestManager::checkMultipleChoiceQuestion(const QJsonObject& iAnswer, const QJsonObject& iQuestion){
    double res = 0.0;
    int rightAnswerCount = 0;
    QJsonArray uAnswers = iAnswer["answers"].toArray();
    QJsonArray qAnswers = iQuestion["answers"].toArray();

    // Loop over user answers for current question
    for (QJsonArray::iterator uIt = uAnswers.begin(); uIt != uAnswers.end(); uIt++){
        QJsonObject uAnswer = uIt->toObject();
        QString uAnswerId = uAnswer["id"].toString().toLower();

        // Loop over question answers into question database
        for (QJsonArray::iterator qIt = qAnswers.begin(); qIt != qAnswers.end(); qIt++){
            QJsonObject qAnswer = qIt->toObject();
            QString qAnswerId = qAnswer["id"].toString().toLower();
            if (qAnswerId == uAnswerId){
                if (qAnswer["isRight"].toBool() == true){
                    // One ball for right single-choise question
                    res += 1.0;
                    break;
                }
                else {
                    // User select unright answer
                    res -= 1.0;
                    break;
                }
            }
        }
    }

    for (QJsonArray::iterator qIt = qAnswers.begin(); qIt != qAnswers.end(); qIt++){
        QJsonObject qAnswer = qIt->toObject();
        // Calculate all right answers
        if (qAnswer["isRight"].toBool() == true){
            rightAnswerCount += 1;
        }
    }

    if (res < 0){
        res = 0.0;
    }
    else {
        res /= double(rightAnswerCount);
    }

    return res;
}

// Pattern singletone
TestManager* TestManager::getInstance(){
    if(!p_instance){
        p_instance = new TestManager();
    }
    return p_instance;
}

TestManager* TestManager::p_instance = nullptr;
// End file testManager.cpp
