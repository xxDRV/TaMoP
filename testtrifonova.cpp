#include "testtrifonova.h"
#include "func.h"
#include "server.h"

testtrifonova::testtrifonova(QObject *parent)
    : QObject{parent}
{

}

void testtrifonova::test_case1()
{
    QString params1 = 0,1,2,3,4,5,6,7;
    QCOMPARE(Dual(params1),"11111111");
}

void testtrifonova::test_case2()
{
    QStringList params2 = 1;
    QCOMPARE(Dual(params2),"10")
}

void testtrifonova::test_case3()
{
    QStringList params3 = 7,8,9;
    QCOMPARE(Dual(params3),"0000001110000000")
}

void testtrifonova::test_case4()
{
    QStringList params4 = 0,2,5;
    QCOMPARE(Dual(params5),"00100101")
}

QTEST_MAIN(testtrifonova)
