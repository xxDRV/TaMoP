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
/**
 * @brief The MainWindow class
 * Класс для главного окна с выбором задач
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /**
     * @brief on_pushButton_3_clicked слот, реагирующий на нажатие кнопки выхода.
     */
    void on_pushButton_3_clicked();
    /**
     * @brief on_action_6_triggered слот, реагирующий на нажатие кнопки выхода через меню.
     */
    void on_action_6_triggered();
    /**
     * @brief on_task1_clicked  слот, реагирующий на нажатие кнопки task1.
     */
    void on_task1_clicked();
    /**
     * @brief on_action_1_triggered слот, реагирующий на нажатие кнопки task1 через меню.
     */
    void on_action_1_triggered();
    /**
     * @brief slot_show слот, отвечающий за отображение логина пользователя.
     * @param log логин.
     */
    void slot_show(QString log);
    /**
     * @brief on_task2_clicked слот, реагирующий на нажатие кнопки task2.
     */
    void on_task2_clicked();
    /**
     * @brief on_action_2_triggered слот, реагирующий на нажатие кнопки task2 через меню.
     */
    void on_action_2_triggered();
    /**
     * @brief on_task3_clicked слот, реагирующий на нажатие кнопки task3.
     */
    void on_task3_clicked();
    /**
     * @brief on_action_3_triggered слот, реагирующий на нажатие кнопки task3 через меню.
     */
    void on_action_3_triggered();
    /**
     * @brief on_task4_clicked слот, реагирующий на нажатие кнопки task4.
     */
    void on_task4_clicked();
    /**
     * @brief on_action_4_triggered слот, реагирующий на нажатие кнопки task4 через меню.
     */
    void on_action_4_triggered();
    /**
     * @brief on_task5_clicked  слот, реагирующий на нажатие кнопки task5.
     */
    void on_task5_clicked();
    /**
     * @brief on_action_5_triggered слот, реагирующий на нажатие кнопки task5 через меню.
     */
    void on_action_5_triggered();

private:
    Ui::MainWindow *ui;
    AuthForm *ui_auth;
    TaskForm *ui_task;
    QTcpSocket *socket;
    QByteArray Data;
    /**
     * @brief SendToServer Функция, отвечающая за отправку сообщения на сервер.
     * @param str сообщение, отправляемое на сервер.
     */
    void SendToServer(QString str);
    qint16 nextBlockSize;
public slots:
    /**
     * @brief slotsReadyRead  слот, отвечающий за готовность клиента принять сообщение от сервера.
     */
    void slotsReadyRead();
};
#endif // MAINWINDOW_H
