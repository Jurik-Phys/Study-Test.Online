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
    QJsonArray jsonArray = mDataManager->getAllChallenges(challengeId);
    QJsonDocument challengeJsonDoc(jsonArray[0].toObject());
    qDebug() << challengeJsonDoc;
    return QString("session-id");
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
