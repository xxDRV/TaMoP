#ifndef TESTTRIFONOVA_H
#define TESTTRIFONOVA_H
#include <QtTest/QtTest>

class testtrifonova : public QObject
{
public:
    explicit testtrifonova(QObject *parent = nullptr);

signals:
private slots:
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();

};

#endif // TESTTRIFONOVA_H
