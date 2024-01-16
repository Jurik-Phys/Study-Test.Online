// Begin file backAppQtTest.h
#ifndef BACK_APP_QT_TEST_H
#define BACK_APP_QT_TEST_H 1

#include <QtTest>
#include <QtDebug>
#include "./../src/appDataORM/appDataManager.h"

class BackAppQtTest : public QObject
{
    Q_OBJECT

    private slots:
       void testOne();
       void testTwo();
       void appDataManagerGetSessionQtTest();
};

#endif
// End file backAppQtTest.h
