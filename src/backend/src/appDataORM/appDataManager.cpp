// Begin file appDataManager.cpp

#include "appDataManager.h"
#include <QDebug>

DataManager::DataManager(){
    qDebug() << "[*] DataManager was created";
    mChallengesJsonName = "challengs.json";
    mChallengesJsonFile.setFileName(mChallengesJsonName);

    mSessionsJsonName = "fsessions.json";
    mSessionsJsonFile.setFileName(mSessionsJsonName);

    mQuestionsJsonName = "questions.json";
    mQuestionsJsonFile.setFileName(mQuestionsJsonName);
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

    // Output json after "id filter"
    for (QJsonArray::iterator it = jsonArrayData.begin(); it !=  jsonArrayData.end(); it++){
        QJsonObject tmpJsonObject = it->toObject();
        if (tmpJsonObject.value("id").toString().toLower() == challengeGID.toLower()){
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

bool DataManager::delChallengeFromFile(const QString& rmID){
    bool res = false;
    QJsonDocument   jsonData;
    QJsonObject     updJsonObj;
    QJsonParseError jsonParseError;
    QJsonArray      outJsonArrayData;

    if (mChallengesJsonFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        jsonData = QJsonDocument::fromJson(QByteArray(mChallengesJsonFile.readAll()), &jsonParseError);
        mChallengesJsonFile.close();

        if (jsonParseError.error == QJsonParseError::NoError){
            QJsonArray jsonArrayData = QJsonValue(jsonData.object().value("Challenges")).toArray();
            for (QJsonArray::iterator it = jsonArrayData.begin(); it !=  jsonArrayData.end(); it++){
                QJsonObject tmpJsonObject = it->toObject();
                if (tmpJsonObject.value("id").toString().toLower() != rmID.toLower()){
                    outJsonArrayData.append(QJsonValue(tmpJsonObject));
                }
                else{
                    res = true;
                }
            }
            updJsonObj["Challenges"] = outJsonArrayData;
            jsonData = QJsonDocument(updJsonObj);

            if (mChallengesJsonFile.open(QIODevice::WriteOnly | QIODevice::Text)){
                if (jsonParseError.error == QJsonParseError::NoError){
                    mChallengesJsonFile.write(jsonData.toJson());
                    mChallengesJsonFile.close();
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

bool DataManager::addSessionToFile(const QJsonObject& newSessionJSON){
    QJsonDocument   jsonData;
    QJsonObject     updJsonObj;
    QJsonParseError jsonParseError;
    bool            res = false;

    if (mSessionsJsonFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        jsonData = QJsonDocument::fromJson(QByteArray(mSessionsJsonFile.readAll()), &jsonParseError);
        mSessionsJsonFile.close();

        if (jsonParseError.error == QJsonParseError::NoError){
            QJsonArray jsonArrayData = QJsonValue(jsonData.object().value("Sessions")).toArray();
            jsonArrayData.append(QJsonValue(newSessionJSON));
            updJsonObj["Sessions"] = jsonArrayData;
            jsonData = QJsonDocument(updJsonObj);

            if (mSessionsJsonFile.open(QIODevice::WriteOnly | QIODevice::Text)){
                if (jsonParseError.error == QJsonParseError::NoError){
                    mSessionsJsonFile.write(jsonData.toJson());
                    mSessionsJsonFile.close();
                    res = true;
                }
            }
            else {
                qDebug() << "[*] При записи файла " << mSessionsJsonName << "возникла ошибка" << jsonParseError.errorString();
            }
        }
        else {
            qDebug() << "[*] Парсинг файла" << mSessionsJsonName << "вызвал ошибку" << jsonParseError.errorString();
        }
    }
    else{
        qDebug() << "[*] Ошибка чтения файла данных" << mSessionsJsonName;
        // Create new file and write new session data
        QJsonArray jsonArrayData;
        jsonArrayData.append(QJsonValue(newSessionJSON));
        updJsonObj["Sessions"] = jsonArrayData;
        if (mSessionsJsonFile.open(QIODevice::WriteOnly | QIODevice::Text)){
            if (jsonParseError.error == QJsonParseError::NoError){
                mSessionsJsonFile.write(QJsonDocument(updJsonObj).toJson());
                mSessionsJsonFile.close();
                res = true;
            }
        }
        else {
            qDebug() << "[*] При записи файла " << mSessionsJsonName << "возникла ошибка" << jsonParseError.errorString();
        }
    }
    return res;
}

QJsonObject DataManager::getSession(const QString& sessionId){
    QJsonDocument   jsonData;
    QJsonParseError jsonParseError;
    QJsonArray      jsonArrayData;
    QJsonObject     outJsonData;

    if (mSessionsJsonFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        jsonData = QJsonDocument::fromJson(QByteArray(mSessionsJsonFile.readAll()), &jsonParseError);
        mSessionsJsonFile.close();

        if (jsonParseError.error == QJsonParseError::NoError){
            jsonArrayData = QJsonValue(jsonData.object().value("Sessions")).toArray();
        }
        else {
            qDebug() << "[*] Парсинг файла" << mSessionsJsonName << "вызвал ошибку" << jsonParseError.errorString();
            jsonArrayData = QJsonArray();
        }
    }
    else{
        qDebug() << "[*] Ошибка чтения файла данных" << mSessionsJsonName;
        jsonArrayData = QJsonArray();
    }

    // Output json after "id filter"
    for (QJsonArray::iterator it = jsonArrayData.begin(); it !=  jsonArrayData.end(); it++){
        QJsonObject tmpJsonObject = it->toObject();
        if (tmpJsonObject.value("id").toString().toLower() == sessionId.toLower()){
            outJsonData = tmpJsonObject;
        }
    }

    return outJsonData;
}

QJsonObject DataManager::getQuestion(const QString& questionId){
    QJsonDocument   jsonData;
    QJsonParseError jsonParseError;
    QJsonArray      jsonArrayData;
    QJsonObject     outJsonData;

    if (mQuestionsJsonFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        jsonData = QJsonDocument::fromJson(QByteArray(mQuestionsJsonFile.readAll()), &jsonParseError);
        mQuestionsJsonFile.close();

        if (jsonParseError.error == QJsonParseError::NoError){
            jsonArrayData = QJsonValue(jsonData.object().value("Questions")).toArray();
        }
        else {
            qDebug() << "[*] Парсинг файла" << mQuestionsJsonName << "вызвал ошибку" << jsonParseError.errorString();
            jsonArrayData = QJsonArray();
        }
    }
    else{
        qDebug() << "[*] Ошибка чтения файла данных" << mQuestionsJsonName;
        jsonArrayData = QJsonArray();
    }

    // Output json after "id filter"
    for (QJsonArray::iterator it = jsonArrayData.begin(); it !=  jsonArrayData.end(); it++){
        QJsonObject tmpJsonObject = it->toObject();

        // qDebug() << QString::fromUtf8(QJsonDocument(tmpJsonObject).toJson());

        if (tmpJsonObject.value("id").toString().toLower() == questionId.toLower()){
            outJsonData = tmpJsonObject;
        }
    }

    return outJsonData;
}

// Pattern singletone
DataManager* DataManager::getInstance(){
    if(!p_instance){
        p_instance = new DataManager();
    }
    return p_instance;
}

DataManager* DataManager::p_instance = nullptr;
// End file appDataManager.cpp
