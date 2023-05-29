#include "testgazaryan.h"
#include "func.h"
#include "server.h"

testgazaryan::testgazaryan(QObject *parent)
    : QObject{parent}
{

}

void testgazaryan::test_case1()
{
    QString params1 = 0,2,3;
    QCOMPARE(isMonotonic(params1),false);
}

void testgazaryan::test_case2()
{
    QStringList params2 = 2,3,5,7;
    (isMonotonic(params2),false)
}

void testgazaryan::test_case3()
{
    QStringList params3 = 2,3,6,7;
    (isMonotonic(params3),true)
}

void testgazaryan::test_case4()
{
    QStringList params4 = 0,1,2,3;
    (isMonotonic(params5),true)
}

QTEST_MAIN(testgazaryan)
