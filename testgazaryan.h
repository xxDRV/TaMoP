#ifndef TESTGAZARYAN_H
#define TESTGAZARYAN_H
#include <QtTest/QtTest>

class testgazaryan : public QObject
{
public:
    explicit testgazaryan(QObject *parent = nullptr);

signals:

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();



};

#endif // TESTGAZARYAN_H
