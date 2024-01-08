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


#include "OAIApiRouter.h"
#include "OAIChallengesAdministratorApiRequest.h"
#include "OAIChallengesUsersApiRequest.h"
#include "OAISessionUsersApiRequest.h"


namespace OpenAPI {

OAIApiRouter::OAIApiRouter() {
    createApiHandlers();
}

OAIApiRouter::~OAIApiRouter(){

}

void OAIApiRouter::createApiHandlers() { 
    mOAIChallengesAdministratorApiHandler = QSharedPointer<OAIChallengesAdministratorApiHandler>::create();
    mOAIChallengesUsersApiHandler = QSharedPointer<OAIChallengesUsersApiHandler>::create();
    mOAISessionUsersApiHandler = QSharedPointer<OAISessionUsersApiHandler>::create();
}


void OAIApiRouter::setOAIChallengesAdministratorApiHandler(QSharedPointer<OAIChallengesAdministratorApiHandler> handler){
    mOAIChallengesAdministratorApiHandler = handler;
}
void OAIApiRouter::setOAIChallengesUsersApiHandler(QSharedPointer<OAIChallengesUsersApiHandler> handler){
    mOAIChallengesUsersApiHandler = handler;
}
void OAIApiRouter::setOAISessionUsersApiHandler(QSharedPointer<OAISessionUsersApiHandler> handler){
    mOAISessionUsersApiHandler = handler;
}

void OAIApiRouter::setUpRoutes() {
    
    Routes.insert(QString("%1 %2").arg("POST").arg("/challenges").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIChallengesAdministratorApiRequest(socket, mOAIChallengesAdministratorApiHandler);
            reqObj->addChallengeRequest();
    });
    Routes.insert(QString("%1 %2").arg("GET").arg("/challenges").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIChallengesUsersApiRequest(socket, mOAIChallengesUsersApiHandler);
            reqObj->getAllChallengesRequest();
    });
    Routes.insert(QString("%1 %2").arg("POST").arg("/answers").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAISessionUsersApiRequest(socket, mOAISessionUsersApiHandler);
            reqObj->pushAnswerRequest();
    });
}

void OAIApiRouter::processRequest(QHttpEngine::Socket *socket){
    if( handleRequest(socket) ){
        return;
    }
    if( handleRequestAndExtractPathParam(socket) ){
        return;
    }
    socket->setStatusCode(QHttpEngine::Socket::NotFound);
    if(socket->isOpen()){
        socket->writeHeaders();
        socket->close();
    }
}

bool OAIApiRouter::handleRequest(QHttpEngine::Socket *socket){
    auto reqPath = QString("%1 %2").arg(fromQHttpEngineMethod(socket->method())).arg(socket->path()).toLower();
    if ( Routes.contains(reqPath) ) {
        Routes.value(reqPath).operator()(socket);
        return true;
    }
    return false;
}

bool OAIApiRouter::handleRequestAndExtractPathParam(QHttpEngine::Socket *socket){
    auto reqPath = QString("%1 %2").arg(fromQHttpEngineMethod(socket->method())).arg(socket->path()).toLower();
    {
        auto completePath = QString("%1 %2").arg("DELETE").arg("/chellenges/{challenge_gid}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString challenge_gid = match.captured(QString("challenge_gid").toLower());
                auto reqObj = new OAIChallengesAdministratorApiRequest(socket, mOAIChallengesAdministratorApiHandler);
                reqObj->deleteChallengeByIdRequest(challenge_gid);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("GET").arg("/chellenges/{challenge_gid}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString challenge_gid = match.captured(QString("challenge_gid").toLower());
                auto reqObj = new OAIChallengesUsersApiRequest(socket, mOAIChallengesUsersApiHandler);
                reqObj->getChallengeByIdRequest(challenge_gid);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("GET").arg("/question/{session_gid}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString session_gid = match.captured(QString("session_gid").toLower());
                auto reqObj = new OAISessionUsersApiRequest(socket, mOAISessionUsersApiHandler);
                reqObj->getQuestionBySessionIDRequest(session_gid);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("GET").arg("/session/{session_gid}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString session_gid = match.captured(QString("session_gid").toLower());
                auto reqObj = new OAISessionUsersApiRequest(socket, mOAISessionUsersApiHandler);
                reqObj->getSessionStateRequest(session_gid);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("GET").arg("/session/{challenge_gid}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString challenge_gid = match.captured(QString("challenge_gid").toLower());
                auto reqObj = new OAISessionUsersApiRequest(socket, mOAISessionUsersApiHandler);
                reqObj->startTestSessionRequest(challenge_gid);
                return true;
            }
        }
    }
    return false;
}

}
