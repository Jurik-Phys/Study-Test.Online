// Begin file testManager.cpp

#include "testManager.h"
#include <QDebug>

TestManager::TestManager(){
    // Constructor stub
    qDebug() << "[*] TestManager was created";
    mDataManager = DataManager::getInstance();
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
        qDebug() << challengeJsonDoc;

        sessionId = QUuid::createUuid().toString();
        testSessionInfo["gid"]     = sessionId;
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

// Pattern singletone
TestManager* TestManager::getInstance(){
    if(!p_instance){
        p_instance = new TestManager();
    }
    return p_instance;
}

TestManager* TestManager::p_instance = nullptr;
// End file testManager.cpp
