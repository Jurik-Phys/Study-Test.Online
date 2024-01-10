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

#include "OAIChallenge.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIChallenge::OAIChallenge(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIChallenge::OAIChallenge() {
    this->initializeModel();
}

OAIChallenge::~OAIChallenge() {}

void OAIChallenge::initializeModel() {

    m_id_isSet = false;
    m_id_isValid = false;

    m_total_questions_isSet = false;
    m_total_questions_isValid = false;

    m_max_time_isSet = false;
    m_max_time_isValid = false;

    m_test_type_isSet = false;
    m_test_type_isValid = false;

    m_section_isSet = false;
    m_section_isValid = false;

    m_subsection_isSet = false;
    m_subsection_isValid = false;

    m_annotation_isSet = false;
    m_annotation_isValid = false;

    m_q_ids_isSet = false;
    m_q_ids_isValid = false;
}

void OAIChallenge::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIChallenge::fromJsonObject(QJsonObject json) {

    m_id_isValid = ::OpenAPI::fromJsonValue(id, json[QString("id")]);
    m_id_isSet = !json[QString("id")].isNull() && m_id_isValid;

    m_total_questions_isValid = ::OpenAPI::fromJsonValue(total_questions, json[QString("totalQuestions")]);
    m_total_questions_isSet = !json[QString("totalQuestions")].isNull() && m_total_questions_isValid;

    m_max_time_isValid = ::OpenAPI::fromJsonValue(max_time, json[QString("maxTime")]);
    m_max_time_isSet = !json[QString("maxTime")].isNull() && m_max_time_isValid;

    m_test_type_isValid = ::OpenAPI::fromJsonValue(test_type, json[QString("testType")]);
    m_test_type_isSet = !json[QString("testType")].isNull() && m_test_type_isValid;

    m_section_isValid = ::OpenAPI::fromJsonValue(section, json[QString("section")]);
    m_section_isSet = !json[QString("section")].isNull() && m_section_isValid;

    m_subsection_isValid = ::OpenAPI::fromJsonValue(subsection, json[QString("subsection")]);
    m_subsection_isSet = !json[QString("subsection")].isNull() && m_subsection_isValid;

    m_annotation_isValid = ::OpenAPI::fromJsonValue(annotation, json[QString("annotation")]);
    m_annotation_isSet = !json[QString("annotation")].isNull() && m_annotation_isValid;

    m_q_ids_isValid = ::OpenAPI::fromJsonValue(q_ids, json[QString("qIDs")]);
    m_q_ids_isSet = !json[QString("qIDs")].isNull() && m_q_ids_isValid;
}

QString OAIChallenge::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIChallenge::asJsonObject() const {
    QJsonObject obj;
    if (m_id_isSet) {
        obj.insert(QString("id"), ::OpenAPI::toJsonValue(id));
    }
    if (m_total_questions_isSet) {
        obj.insert(QString("totalQuestions"), ::OpenAPI::toJsonValue(total_questions));
    }
    if (m_max_time_isSet) {
        obj.insert(QString("maxTime"), ::OpenAPI::toJsonValue(max_time));
    }
    if (m_test_type_isSet) {
        obj.insert(QString("testType"), ::OpenAPI::toJsonValue(test_type));
    }
    if (m_section_isSet) {
        obj.insert(QString("section"), ::OpenAPI::toJsonValue(section));
    }
    if (subsection.size() > 0) {
        obj.insert(QString("subsection"), ::OpenAPI::toJsonValue(subsection));
    }
    if (m_annotation_isSet) {
        obj.insert(QString("annotation"), ::OpenAPI::toJsonValue(annotation));
    }
    if (q_ids.size() > 0) {
        obj.insert(QString("qIDs"), ::OpenAPI::toJsonValue(q_ids));
    }
    return obj;
}

QString OAIChallenge::getId() const {
    return id;
}
void OAIChallenge::setId(const QString &id) {
    this->id = id;
    this->m_id_isSet = true;
}

bool OAIChallenge::is_id_Set() const{
    return m_id_isSet;
}

bool OAIChallenge::is_id_Valid() const{
    return m_id_isValid;
}

double OAIChallenge::getTotalQuestions() const {
    return total_questions;
}
void OAIChallenge::setTotalQuestions(const double &total_questions) {
    this->total_questions = total_questions;
    this->m_total_questions_isSet = true;
}

bool OAIChallenge::is_total_questions_Set() const{
    return m_total_questions_isSet;
}

bool OAIChallenge::is_total_questions_Valid() const{
    return m_total_questions_isValid;
}

double OAIChallenge::getMaxTime() const {
    return max_time;
}
void OAIChallenge::setMaxTime(const double &max_time) {
    this->max_time = max_time;
    this->m_max_time_isSet = true;
}

bool OAIChallenge::is_max_time_Set() const{
    return m_max_time_isSet;
}

bool OAIChallenge::is_max_time_Valid() const{
    return m_max_time_isValid;
}

QString OAIChallenge::getTestType() const {
    return test_type;
}
void OAIChallenge::setTestType(const QString &test_type) {
    this->test_type = test_type;
    this->m_test_type_isSet = true;
}

bool OAIChallenge::is_test_type_Set() const{
    return m_test_type_isSet;
}

bool OAIChallenge::is_test_type_Valid() const{
    return m_test_type_isValid;
}

QString OAIChallenge::getSection() const {
    return section;
}
void OAIChallenge::setSection(const QString &section) {
    this->section = section;
    this->m_section_isSet = true;
}

bool OAIChallenge::is_section_Set() const{
    return m_section_isSet;
}

bool OAIChallenge::is_section_Valid() const{
    return m_section_isValid;
}

QList<QString> OAIChallenge::getSubsection() const {
    return subsection;
}
void OAIChallenge::setSubsection(const QList<QString> &subsection) {
    this->subsection = subsection;
    this->m_subsection_isSet = true;
}

bool OAIChallenge::is_subsection_Set() const{
    return m_subsection_isSet;
}

bool OAIChallenge::is_subsection_Valid() const{
    return m_subsection_isValid;
}

QString OAIChallenge::getAnnotation() const {
    return annotation;
}
void OAIChallenge::setAnnotation(const QString &annotation) {
    this->annotation = annotation;
    this->m_annotation_isSet = true;
}

bool OAIChallenge::is_annotation_Set() const{
    return m_annotation_isSet;
}

bool OAIChallenge::is_annotation_Valid() const{
    return m_annotation_isValid;
}

QList<QString> OAIChallenge::getQIds() const {
    return q_ids;
}
void OAIChallenge::setQIds(const QList<QString> &q_ids) {
    this->q_ids = q_ids;
    this->m_q_ids_isSet = true;
}

bool OAIChallenge::is_q_ids_Set() const{
    return m_q_ids_isSet;
}

bool OAIChallenge::is_q_ids_Valid() const{
    return m_q_ids_isValid;
}

bool OAIChallenge::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (m_id_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_total_questions_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_max_time_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_test_type_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_section_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (subsection.size() > 0) {
            isObjectUpdated = true;
            break;
        }

        if (m_annotation_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (q_ids.size() > 0) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIChallenge::isValid() const {
    // only required properties are required for the object to be considered valid
    return m_id_isValid && m_total_questions_isValid && m_max_time_isValid && m_test_type_isValid && m_section_isValid && m_subsection_isValid && m_annotation_isValid && m_q_ids_isValid && true;
}

} // namespace OpenAPI
