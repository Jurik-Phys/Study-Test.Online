// Begin file testManager.cpp

#include "testManager.h"
#include <QDebug>
#include <QRandomGenerator>

TestManager::TestManager(){
    // Constructor stub
    qDebug() << "[*] TestManager was created";
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
    qDebug() << QString::fromUtf8(QJsonDocument(nextQuestionData).toJson());

    OpenAPI::OAIQuestion res;
    res.fromJsonObject(nextQuestionData);

    // OpenAPI::OAIQuestion res(QString::fromUtf8(QJsonDocument(nextQuestionData).toJson()));
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
