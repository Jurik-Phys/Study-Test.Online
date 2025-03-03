// Begin appDataManager.h
#ifndef QDATAMANAGER_H
#define QDATAMANAGER_H 1

#include <QFile>
#include <QString>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonObject>

class DataManager {
    public:
        ~DataManager();
        // Pattern singletone
        static DataManager* getInstance();

        QJsonArray  getAllSessions();
        QJsonObject getSession(const QString&);
        QJsonArray  getAllQuestions();
        QJsonObject getQuestion(const QString&, bool hideAnswer = false);
        QJsonArray getAllChallenges();
        QJsonArray getAllChallenges(const QString&);
        QJsonArray getAllSessionsAnswers();
        QJsonArray getSessionAnswers(const QString&);
        bool       addChallengeToFile(const QJsonObject&);
        bool       delChallengeFromFile(const QString&);
        bool       addSessionToFile(const QJsonObject&);
        bool       putAllSessionsToFile(const QJsonObject&);
        bool       addAnswerToFile(const QJsonObject&);

    private:
        // Pattern singletone
        static DataManager* p_instance;
        DataManager();

        QString mChallengesJsonName;
        QFile   mChallengesJsonFile;

        QString mSessionsJsonName;
        QFile   mSessionsJsonFile;

        QString mQuestionsJsonName;
        QFile   mQuestionsJsonFile;

        QString mAnswersJsonName;
        QFile   mAnswersJsonFile;

        bool isAnswerSessionExists(const QString&);
        QJsonObject prepareAnswerToWrite(const QJsonObject&);
};

#endif
// End appDataManager.h
