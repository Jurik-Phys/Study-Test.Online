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

#ifndef OAI_OAIChallengesUsersApiRequest_H
#define OAI_OAIChallengesUsersApiRequest_H

#include <QObject>
#include <QStringList>
#include <QMultiMap>
#include <QNetworkReply>
#include <QSharedPointer>

#include <qhttpengine/socket.h>
#include "OAIChallenge.h"
#include "OAIError.h"
#include <QList>
#include <QString>
#include "OAIChallengesUsersApiHandler.h"

namespace OpenAPI {

class OAIChallengesUsersApiRequest : public QObject
{
    Q_OBJECT

public:
    OAIChallengesUsersApiRequest(QHttpEngine::Socket *s, QSharedPointer<OAIChallengesUsersApiHandler> handler);
    virtual ~OAIChallengesUsersApiRequest();

    void getAllChallengesRequest();
    void getChallengeByIdRequest(const QString& challenge_id);
    

    void getAllChallengesResponse(const QList<OAIChallenge>& res);
    void getChallengeByIdResponse(const OAIChallenge& res);
    

    void getAllChallengesError(const QList<OAIChallenge>& res, QNetworkReply::NetworkError error_type, QString& error_str);
    void getChallengeByIdError(const OAIChallenge& res, QNetworkReply::NetworkError error_type, QString& error_str);
    

    void sendCustomResponse(QByteArray & res, QNetworkReply::NetworkError error_type);

    void sendCustomResponse(QIODevice *res, QNetworkReply::NetworkError error_type);

    QMap<QString, QString> getRequestHeaders() const;

    QHttpEngine::Socket* getRawSocket();

    void setResponseHeaders(const QMultiMap<QString,QString>& headers);

signals:
    void getAllChallenges();
    void getChallengeById(QString challenge_id);
    

private:
    QMap<QString, QString> requestHeaders;
    QMap<QString, QString> responseHeaders;
    QHttpEngine::Socket  *socket;
    QSharedPointer<OAIChallengesUsersApiHandler> handler;

    inline void setSocketResponseHeaders(){
        QHttpEngine::Socket::HeaderMap resHeaders;
        for(auto itr = responseHeaders.begin(); itr != responseHeaders.end(); ++itr) {
            resHeaders.insert(itr.key().toUtf8(), itr.value().toUtf8());
        }
        socket->setHeaders(resHeaders);
    }
};

}

#endif // OAI_OAIChallengesUsersApiRequest_H
