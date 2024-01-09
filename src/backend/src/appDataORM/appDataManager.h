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

        QJsonArray getAllChallenges();
        QJsonArray getAllChallenges(const QString&);
        bool       addChallengeToFile(const QJsonObject&);
        bool       delChallengeFromFile(const QString&);
        bool       addSessionToFile(const QJsonObject&);

    private:
        // Pattern singletone
        static DataManager* p_instance;
        DataManager();

        QString mChallengesJsonName;
        QFile   mChallengesJsonFile;
        QString mSessionsJsonName;
        QFile   mSessionsJsonFile;
};

#endif
// End appDataManager.h
