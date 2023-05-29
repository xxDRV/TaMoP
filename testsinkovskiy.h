#ifndef TESTSINKOVSKIY_H
#define TESTSINKOVSKIY_H
#include <QtTest/QtTest>

class testSinkovskiy : public QObject
{
public:
    explicit testSinkovskiy(QObject *parent = nullptr);

signals:

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();



};

#endif // TESTSINKOVSKIY_H
