// Begin file backAppQtTest.cpp

#include <QtDebug>
#include "backAppQtTest.h"

void BackAppQtTest::testOne(){
    qDebug() << "[Test One]";
    double a = 5.0;
    double b = 5.0;

    QCOMPARE(a, b);
}

void BackAppQtTest::testTwo(){
    qDebug() << "[Test Two]";
    double x = 15.0;
    double y = 14.0;

    QCOMPARE(x, y);
}

void BackAppQtTest::testThree(){
    qDebug() << "[Test Three]";
    double n = 15.0;
    double m = 14.0;

    QCOMPARE( n - m, 1.0);
}

QTEST_MAIN(BackAppQtTest);
// End file backAppQtTest.cpp
