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

    private:
        // Pattern singletone
        static DataManager* p_instance;
        DataManager();

        QString mChallengesJsonName;
        QFile   mChallengesJsonFile;
};

#endif
// End appDataManager.h
