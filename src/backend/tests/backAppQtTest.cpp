// Begin file backAppQtTest.cpp

#include <QtDebug>
#include "backAppQtTest.h"

void BackAppQtTest::testOne(){
    qDebug() << "[Test One]";
    double a = 5.0;
    double b = 5.0;

    QCOMPARE(a, b);
}

void BackAppQtTest::testTwo(){
    qDebug() << "[Test Two]";
    double x = 15.0;
    double y = 15.0;

    QCOMPARE(x, y);
}

void BackAppQtTest::appDataManagerGetSessionQtTest(){
    DataManager* mDataManager =DataManager::getInstance();

    QJsonObject fileSession;
    QJsonObject modlSession;

    fileSession = mDataManager->getSession("973bd374-dc8f-4107-896c-756727a3e54e");

    // Fill model session //
    modlSession["beginAt"] = QJsonValue("2024-01-16 00:20:51");
    modlSession["endAt"] = QJsonValue("");
    modlSession["id"] = QJsonValue("973bd374-dc8f-4107-896c-756727a3e54e");
    QJsonArray nxtQuestionsId;
    nxtQuestionsId.append("b01d1aa0-4af6-4645-a34f-6acdebb2621b");
    nxtQuestionsId.append("d67f42ee-64a7-4209-a3bd-4ea9c69fa254");
    nxtQuestionsId.append("2e19b376-72cc-4895-ab91-a04f0750ea5c");
    QJsonArray prvQuestionsId;
    modlSession["nextQuestionsId"] = nxtQuestionsId;
    modlSession["prevQuestionsId"] = prvQuestionsId;
    modlSession["result"] = QJsonValue("");
    QJsonObject tstInfo;
    tstInfo["section"] = QJsonValue("Безопасность жизнедеятельности");
    QJsonArray subSect;
    subSect.append("Раздел 1. Общие вопросы безопасности жизнедеятельности");
    subSect.append("Раздел 2. Общие вопросы охраны труда");
    subSect.append("Раздел 3. Основы производственной санитарии");
    tstInfo["subsection"] = subSect;
    tstInfo["testType"] = QJsonValue("education");
    tstInfo["totalQuestions"] = QJsonValue(68);
    modlSession["testInfo"] = tstInfo;
    QJsonObject usrInfo;
    usrInfo["group"] = QJsonValue("Some group of people");
    usrInfo["id"] = QJsonValue("00000000-0000-0000-0000-000000000001");
    usrInfo["name"] = QJsonValue("Petrov I.D.");
    modlSession["userInfo"] = usrInfo;

    QCOMPARE( fileSession, modlSession );
}

QTEST_MAIN(BackAppQtTest);
// End file backAppQtTest.cpp
