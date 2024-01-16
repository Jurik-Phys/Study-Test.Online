// Begin file backAppQtTest.h
#ifndef BACK_APP_QT_TEST_H
#define BACK_APP_QT_TEST_H 1

// #include <QtCore>
#include <QtTest>
#include <QtDebug>

class BackAppQtTest : public QObject
{
    Q_OBJECT

    private slots:
       void testOne();
       void testTwo();
       void testThree();
};

#endif
// End file backAppQtTest.h
