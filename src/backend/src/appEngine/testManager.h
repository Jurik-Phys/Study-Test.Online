// Begin testManager.h
#ifndef QTESTMANAGER_H
#define QTESTMANAGER_H 1

#include "./../models/OAISession.h"
#include "./../models/OAIQuestion.h"
#include "./../appDataORM/appDataManager.h"
#include <QString>
#include <QUuid>
#include <QDateTime>

class TestManager {
    public:
        ~TestManager();
        // Pattern singletone
        static TestManager* getInstance();

        // Admin/teacher/ creates specific challenge
        // [*] testInfo:
        //      > testType   - area of knowledge (education|psychology|funny)
        //      > section    - name of discipline or knowledge area
        //      > subsection - subsection of discipline or knowledge area
        void createChallenge();

        // section
        // subsection
        void runSession();
        QString createSession(const QString&);
        OpenAPI::OAIQuestion getNextQuestion(const QString&, bool hideAnswer = false);

        bool checkAnswer(const QJsonObject);
        bool markQuestionAsDone(const QJsonObject);

    private:
        // Pattern singletone
        static TestManager* p_instance;
        TestManager();
        DataManager* mDataManager;

        bool isSessionExtists(const QString&);
        bool isSessionPending(const QString&);

        QJsonValue getTestResults(const QJsonValue&, const QJsonArray&);
        double checkSingleChoiceQuestion(const QJsonObject&, const QJsonObject&);
        double checkMultipleChoiceQuestion(const QJsonObject&, const QJsonObject&);
};



#endif
// End testManager.h
