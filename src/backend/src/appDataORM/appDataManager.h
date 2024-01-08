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
        DataManager();
        ~DataManager();

        QJsonArray getAllChallenges();

    private:
        QString mChallengesJsonName;
        QFile   mChallengesJsonFile;
};

#endif
// End appDataManager.h
