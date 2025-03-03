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

#ifndef OAI_OAISessionUsersApiHandler_H
#define OAI_OAISessionUsersApiHandler_H

#include <QObject>

#include "OAIChallengeID.h"
#include "OAIError.h"
#include "OAIPushAnswer_request.h"
#include "OAIQuestion.h"
#include "OAISession.h"
#include <QString>

#include "../appEngine/testManager.h"

namespace OpenAPI {

class OAISessionUsersApiHandler : public QObject
{
    Q_OBJECT

public:
    OAISessionUsersApiHandler();
    virtual ~OAISessionUsersApiHandler();


public slots:
    virtual void getQuestionBySessionID(QString session_id);
    virtual void getSessionState(QString session_id);
    virtual void pushAnswer(OAIPushAnswer_request oai_push_answer_request);
    virtual void startTestSession(OAIChallengeID oai_challenge_id);

private:
    TestManager* mTestManager;
    DataManager* mDataManager;
};

}

#endif // OAI_OAISessionUsersApiHandler_H
