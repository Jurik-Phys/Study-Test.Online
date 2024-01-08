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

#include "OAIQuestion.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIQuestion::OAIQuestion(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIQuestion::OAIQuestion() {
    this->initializeModel();
}

OAIQuestion::~OAIQuestion() {}

void OAIQuestion::initializeModel() {

    m_id_isSet = false;
    m_id_isValid = false;

    m_type_isSet = false;
    m_type_isValid = false;

    m_body_isSet = false;
    m_body_isValid = false;

    m_answers_isSet = false;
    m_answers_isValid = false;
}

void OAIQuestion::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIQuestion::fromJsonObject(QJsonObject json) {

    m_id_isValid = ::OpenAPI::fromJsonValue(id, json[QString("id")]);
    m_id_isSet = !json[QString("id")].isNull() && m_id_isValid;

    m_type_isValid = ::OpenAPI::fromJsonValue(type, json[QString("type")]);
    m_type_isSet = !json[QString("type")].isNull() && m_type_isValid;

    m_body_isValid = ::OpenAPI::fromJsonValue(body, json[QString("body")]);
    m_body_isSet = !json[QString("body")].isNull() && m_body_isValid;

    if(json["answers"].isArray()){
        auto arr = json["answers"].toArray();
        m_answers_isValid = true;
        if(arr.count() > 0) {
            for (const QJsonValue jval : arr) {
                QList<QString> item;
                m_answers_isValid &= ::OpenAPI::fromJsonValue(item, jval);
                m_answers_isSet = !jval.isNull() && m_answers_isValid;
                answers.push_back(item);
            }
        }
    }
}

QString OAIQuestion::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIQuestion::asJsonObject() const {
    QJsonObject obj;
    if (m_id_isSet) {
        obj.insert(QString("id"), ::OpenAPI::toJsonValue(id));
    }
    if (m_type_isSet) {
        obj.insert(QString("type"), ::OpenAPI::toJsonValue(type));
    }
    if (m_body_isSet) {
        obj.insert(QString("body"), ::OpenAPI::toJsonValue(body));
    }
    if (answers.size() > 0) {
        
        obj.insert(QString("answers"), toJsonValue(answers));
    }
    return obj;
}

QString OAIQuestion::getId() const {
    return id;
}
void OAIQuestion::setId(const QString &id) {
    this->id = id;
    this->m_id_isSet = true;
}

bool OAIQuestion::is_id_Set() const{
    return m_id_isSet;
}

bool OAIQuestion::is_id_Valid() const{
    return m_id_isValid;
}

QString OAIQuestion::getType() const {
    return type;
}
void OAIQuestion::setType(const QString &type) {
    this->type = type;
    this->m_type_isSet = true;
}

bool OAIQuestion::is_type_Set() const{
    return m_type_isSet;
}

bool OAIQuestion::is_type_Valid() const{
    return m_type_isValid;
}

QString OAIQuestion::getBody() const {
    return body;
}
void OAIQuestion::setBody(const QString &body) {
    this->body = body;
    this->m_body_isSet = true;
}

bool OAIQuestion::is_body_Set() const{
    return m_body_isSet;
}

bool OAIQuestion::is_body_Valid() const{
    return m_body_isValid;
}

QList<QList<QString>> OAIQuestion::getAnswers() const {
    return answers;
}
void OAIQuestion::setAnswers(const QList<QList<QString>> &answers) {
    this->answers = answers;
    this->m_answers_isSet = true;
}

bool OAIQuestion::is_answers_Set() const{
    return m_answers_isSet;
}

bool OAIQuestion::is_answers_Valid() const{
    return m_answers_isValid;
}

bool OAIQuestion::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (m_id_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_type_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_body_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (answers.size() > 0) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIQuestion::isValid() const {
    // only required properties are required for the object to be considered valid
    return m_type_isValid && m_body_isValid && m_answers_isValid && true;
}

} // namespace OpenAPI
