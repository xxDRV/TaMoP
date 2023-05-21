#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDebug>
#include <QMainWindow>
#include <QTcpSocket>
#include<QTime>
#include<QDataStream>
#include "authform.h"
#include "taskform.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_action_6_triggered();

    void on_task1_clicked();

    void on_action_1_triggered();

    void slot_show(QString log);

    void on_task2_clicked();

    void on_action_2_triggered();

    void on_task3_clicked();

    void on_action_3_triggered();

    void on_task4_clicked();

    void on_action_4_triggered();

    void on_task5_clicked();

    void on_action_5_triggered();

private:
    Ui::MainWindow *ui;
    AuthForm *ui_auth;
    TaskForm *ui_task;
    QTcpSocket *socket;
    QByteArray Data;
    void SendToServer(QString str);
    qint16 nextBlockSize;
public slots:
    void slotsReadyRead();
};
#endif // MAINWINDOW_H
