// Begin file appDataManager.cpp

#include "appDataManager.h"
#include <QDebug>

DataManager::DataManager(){
    // Constructor stub
    qDebug() << "[*] DataManager was created into constructor";

    mChallengesJsonName = "challengs.json";
    mChallengesJsonFile.setFileName(mChallengesJsonName);
}

DataManager::~DataManager(){
    // Destructor stub
}

QJsonArray DataManager::getAllChallenges(){
    QJsonDocument   jsonData;
    QJsonArray      jsonArrayData;
    QJsonParseError jsonParseError;

    if (mChallengesJsonFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        jsonData = QJsonDocument::fromJson(QByteArray(mChallengesJsonFile.readAll()), &jsonParseError);
        mChallengesJsonFile.close();

        if (jsonParseError.error == QJsonParseError::NoError){
            jsonArrayData = QJsonValue(jsonData.object().value("Challenges")).toArray();
        }
        else {
            qDebug() << "[*] Парсинг файла" << mChallengesJsonName << "вызвал ошибку" << jsonParseError.errorString();
            jsonArrayData = QJsonArray();
        }
    }
    else{
        qDebug() << "[*] Ошибка чтения файла данных" << mChallengesJsonName;
        jsonArrayData = QJsonArray();
    }

    // Remove from output question ID's
    for (QJsonArray::iterator it = jsonArrayData.begin(); it !=  jsonArrayData.end(); it++){
        QJsonObject tmpJsonObject = it->toObject();
        if (tmpJsonObject.contains("qIDs")){
            tmpJsonObject.remove("qIDs");
            *it = tmpJsonObject;
        }
    }
    return jsonArrayData;
}

QJsonArray DataManager::getAllChallenges(const QString& challengeGID){
    QJsonDocument   jsonData;
    QJsonArray      jsonArrayData;
    QJsonParseError jsonParseError;
    QJsonArray      outJsonArrayData;

    if (mChallengesJsonFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        jsonData = QJsonDocument::fromJson(QByteArray(mChallengesJsonFile.readAll()), &jsonParseError);
        mChallengesJsonFile.close();

        if (jsonParseError.error == QJsonParseError::NoError){
            jsonArrayData = QJsonValue(jsonData.object().value("Challenges")).toArray();
        }
        else {
            qDebug() << "[*] Парсинг файла" << mChallengesJsonName << "вызвал ошибку" << jsonParseError.errorString();
            jsonArrayData = QJsonArray();
        }
    }
    else{
        qDebug() << "[*] Ошибка чтения файла данных" << mChallengesJsonName;
        jsonArrayData = QJsonArray();
    }

    // Output json after "gid filter"
    for (QJsonArray::iterator it = jsonArrayData.begin(); it !=  jsonArrayData.end(); it++){
        QJsonObject tmpJsonObject = it->toObject();
        if (tmpJsonObject.value("gid").toString().toLower() == challengeGID.toLower()){
            outJsonArrayData.append(QJsonValue(tmpJsonObject));
        }
    }

    return outJsonArrayData;
}

bool DataManager::addChallengeToFile(const QJsonObject& newChallengeJSON){
    QJsonDocument   jsonData;
    QJsonObject     updJsonObj;
    QJsonParseError jsonParseError;
    bool            res = false;

    if (mChallengesJsonFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        jsonData = QJsonDocument::fromJson(QByteArray(mChallengesJsonFile.readAll()), &jsonParseError);
        mChallengesJsonFile.close();

        if (jsonParseError.error == QJsonParseError::NoError){
            QJsonArray jsonArrayData = QJsonValue(jsonData.object().value("Challenges")).toArray();
            jsonArrayData.append(QJsonValue(newChallengeJSON));
            updJsonObj["Challenges"] = jsonArrayData;
            jsonData = QJsonDocument(updJsonObj);

            if (mChallengesJsonFile.open(QIODevice::WriteOnly | QIODevice::Text)){
                if (jsonParseError.error == QJsonParseError::NoError){
                    mChallengesJsonFile.write(jsonData.toJson());
                    mChallengesJsonFile.close();
                    res = true;
                }
            }
            else {
                qDebug() << "[*] При записи файла " << mChallengesJsonName << "возникла ошибка" << jsonParseError.errorString();
            }
        }
        else {
            qDebug() << "[*] Парсинг файла" << mChallengesJsonName << "вызвал ошибку" << jsonParseError.errorString();
        }
    }
    else{
        qDebug() << "[*] Ошибка чтения файла данных" << mChallengesJsonName;
    }
    return res;
}
// End file appDataManager.cpp
