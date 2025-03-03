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

/*
 * OAIQuestion.h
 *
 * 
 */

#ifndef OAIQuestion_H
#define OAIQuestion_H

#include <QJsonObject>

#include "OAIQuestion_answers_inner.h"
#include <QList>
#include <QString>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIQuestion : public OAIObject {
public:
    OAIQuestion();
    OAIQuestion(QString json);
    ~OAIQuestion() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    QString getId() const;
    void setId(const QString &id);
    bool is_id_Set() const;
    bool is_id_Valid() const;

    QString getType() const;
    void setType(const QString &type);
    bool is_type_Set() const;
    bool is_type_Valid() const;

    QString getBody() const;
    void setBody(const QString &body);
    bool is_body_Set() const;
    bool is_body_Valid() const;

    QList<OAIQuestion_answers_inner> getAnswers() const;
    void setAnswers(const QList<OAIQuestion_answers_inner> &answers);
    bool is_answers_Set() const;
    bool is_answers_Valid() const;

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    QString id;
    bool m_id_isSet;
    bool m_id_isValid;

    QString type;
    bool m_type_isSet;
    bool m_type_isValid;

    QString body;
    bool m_body_isSet;
    bool m_body_isValid;

    QList<OAIQuestion_answers_inner> answers;
    bool m_answers_isSet;
    bool m_answers_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIQuestion)

#endif // OAIQuestion_H
