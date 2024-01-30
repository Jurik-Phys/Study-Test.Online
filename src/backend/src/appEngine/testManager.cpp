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
        testInfo["totalQuestion"]   = challengeJsonDoc["qIDs"].toArray().size();
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

OpenAPI::OAIQuestion TestManager::getNextQuestion(const QString& sessionId){
    QJsonObject sessionJsonData = mDataManager->getSession(sessionId);

    // size -> random index -> value by random index -> OAIQuestion object
    int nextQuestionArraySize = sessionJsonData["nextQuestionsId"].toArray().size();
    int randomQuestionId = QRandomGenerator::system()->bounded(nextQuestionArraySize);
    QString nextQuestionsGid = sessionJsonData["nextQuestionsId"].toArray()[randomQuestionId].toString();
    QJsonObject nextQuestionData = mDataManager->getQuestion(nextQuestionsGid);

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

    qDebug() << "[II] > markQuestionAsDone > ";

    for (int sIdx = 0; sIdx < allSessionsDataA.size(); sIdx++){
        QJsonObject tempSessionJsonObject = allSessionsDataA[sIdx].toObject();
        if (tempSessionJsonObject["id"].toString().toLower() == answer["session_id"].toString().toLower()){
            QJsonArray tmpNextQuestionsIdArray(tempSessionJsonObject["nextQuestionsId"].toArray());
            QJsonArray tmpPrevQuestionsIdArray(tempSessionJsonObject["prevQuestionsId"].toArray());
            qDebug() << "[II] >> Before changes << ";
            qDebug() << "Session ID: "           << allSessionsDataA[sIdx].toObject()["id"];
            qDebug() << "Next Questions Array: " << allSessionsDataA[sIdx].toObject()["nextQuestionsId"];
            qDebug() << "Prev Questions Array: " << allSessionsDataA[sIdx].toObject()["prevQuestionsId"];
            for (int idx = 0; idx < tmpNextQuestionsIdArray.size(); idx++){
                if (tmpNextQuestionsIdArray[idx] == answer["question_id"]){
                    // remove question from "Next Questions"
                    tmpNextQuestionsIdArray.removeAt(idx);
                    tempSessionJsonObject["nextQuestionsId"] = tmpNextQuestionsIdArray;

                    // insert question to "Previous Questions"
                    tmpPrevQuestionsIdArray.append(answer["question_id"]);
                    tempSessionJsonObject["prevQuestionsId"] = tmpPrevQuestionsIdArray;

                    // Increase done questions count
                    QJsonObject tmpTestInfo(tempSessionJsonObject["testInfo"].toObject());
                    tmpTestInfo["doneQuestions"] = tmpTestInfo["doneQuestions"].toInt() + 1;
                    tempSessionJsonObject["testInfo"] = tmpTestInfo;
                    break;
                }
            }
            allSessionsDataA[sIdx] = tempSessionJsonObject;
            qDebug() << "[II] >> After changes << ";
            qDebug() << "Session ID: "           << allSessionsDataA[sIdx].toObject()["id"];
            qDebug() << "Next Questions Array: " << allSessionsDataA[sIdx].toObject()["nextQuestionsId"];
            qDebug() << "Prev Questions Array: " << allSessionsDataA[sIdx].toObject()["prevQuestionsId"];
            qDebug() << "Session TestInfo:     " << allSessionsDataA[sIdx].toObject()["testInfo"];

            QJsonObject sessionsJsonObj;
            sessionsJsonObj["Sessions"] = allSessionsDataA;
            mDataManager->putAllSessionsToFile(sessionsJsonObj);
            res = true;
            break;
        }
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
