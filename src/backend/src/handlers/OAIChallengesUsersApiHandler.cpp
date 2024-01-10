/**
 * Study-Test.Online - сервис проведения тестирования
 * No description provided (generated by Openapi Generator https://github.com/openapitools/openapi-generator)
 *
 * The version of the OpenAPI document: 0.0.1
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QDebug>

#include "OAIChallengesUsersApiHandler.h"
#include "OAIChallengesUsersApiRequest.h"

namespace OpenAPI {

OAIChallengesUsersApiHandler::OAIChallengesUsersApiHandler(){
    mTestManager = TestManager::getInstance();
    mDataManager = DataManager::getInstance();
}

OAIChallengesUsersApiHandler::~OAIChallengesUsersApiHandler(){
    delete mTestManager;
    delete mDataManager;
}

void OAIChallengesUsersApiHandler::getAllChallenges() {
    auto reqObj = qobject_cast<OAIChallengesUsersApiRequest*>(sender());
    if( reqObj != nullptr )
    {
        QList<OAIChallenge> res;
        QJsonArray jsonArray(mDataManager->getAllChallenges());
        for (int i = 0; i < jsonArray.count(); i++){
            QString returnedJSON = QJsonDocument(jsonArray.at(i).toObject()).toJson();
            OpenAPI::OAIChallenge tempChallenge(returnedJSON);
            res.append(tempChallenge);
        }
        reqObj->getAllChallengesResponse(res);
    }
}
void OAIChallengesUsersApiHandler::getChallengeById(QString challenge_id) {
    auto reqObj = qobject_cast<OAIChallengesUsersApiRequest*>(sender());
    if( reqObj != nullptr )
    {
        QList<OAIChallenge> res;
        QJsonArray jsonArray(mDataManager->getAllChallenges(challenge_id));
        for (int i = 0; i < jsonArray.count(); i++){
            QString returnedJSON = QJsonDocument(jsonArray.at(i).toObject()).toJson();
            OpenAPI::OAIChallenge tempChallenge(returnedJSON);
            res.append(tempChallenge);
        }
        reqObj->getAllChallengesResponse(res);
    }
}

}
