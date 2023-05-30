#include "testsinkovskiy.h"
#include "func.h"
#include "server.h"

testSinkovskiy::testSinkovskiy(QObject *parent)
    : QObject{parent}
{

}

void testSinkovskiy::test_case1()
{
    QString params1 = 1;
    QCOMPARE(isSelfDual(params1),true);
}

void testSinkovskiy::test_case2()
{
    QStringList params2 = 1,2,3,4;
    QCOMPARE(isSelfDual(params2),false)
}

void testSinkovskiy::test_case3()
{
    QStringList params3 = 0,1,2,3;
    QCOMPARE(isSelfDual(params3),true)
}


void testSinkovskiy::test_case4()
{
    QStringList params4 = 0,1,2,3,4,5,6,7;
    QCOMPARE(isSelfDual(params4),true)
}

QTEST_MAIN(testSinkovskiy)
