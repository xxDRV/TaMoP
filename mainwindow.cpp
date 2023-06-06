#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "taskform.h"
#include "check_error.h"
#include "checking.h"
//#include "client_hole.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_task = new TaskForm;
    ui_auth = new AuthForm;
    ui_checkok = new Checking;
    ui_checkerr = new check_error;
    //socket = new QTcpSocket(this);

    //connect(socket,&QTcpSocket::readyRead,this,&MainWindow::slotsReadyRead);
    //connect(socket,&QTcpSocket::disconnected,socket,&QTcpSocket::deleteLater);
    connect(Client_hole::get_instance(), &Client_hole::onAuth,this, &MainWindow::slot_auth_ok);
    connect(Client_hole::get_instance(), &Client_hole::checking_cor,this, &MainWindow::slot_check_correct);
    connect(Client_hole::get_instance(), &Client_hole::checking_incor,this, &MainWindow::slot_check_incorrect);

    //nextBlockSize = 0;
    ui_auth->show();

}

void MainWindow::slot_check_correct(){
    ui_checkok->show();
    //ui_task->TaskForm_task->setText("ВЕРНО");
 }
void MainWindow::slot_check_incorrect(){
    ui_checkerr->show();
    //ui_task->TaskForm_task->setText("ВЕРНО");
 }
 void MainWindow::slot_auth_ok()
 {
    ui->NameLabel->setText(ui_auth->get_log());
    ui_auth->close();
    this->show();
 }

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}

void MainWindow::on_action_6_triggered()
{
    this->on_pushButton_3_clicked();
}


void MainWindow::on_task1_clicked()
{
    qDebug()<<"task1";
    ui_task->set_task_number(1);
    ui_task->show();
}

void MainWindow::on_action_1_triggered()
{
    this->on_task1_clicked();
}

/*void MainWindow::slot_show(QString log)
{
    this->show();
    /ui->NameLabel->setText(log);
}
*/
void MainWindow::on_task2_clicked()
{
    qDebug()<<"task2";
    ui_task->set_task_number(2);
    ui_task->show();
}


void MainWindow::on_action_2_triggered()
{
   this->on_task2_clicked();
}


void MainWindow::on_task3_clicked()
{
   qDebug()<<"task3";
   ui_task->set_task_number(3);
   ui_task->show();
}


void MainWindow::on_action_3_triggered()
{
    this->on_task3_clicked();
}


void MainWindow::on_task4_clicked()
{
    qDebug()<<"task4";
    ui_task->set_task_number(4);
    ui_task->show();
}


void MainWindow::on_action_4_triggered()
{
     this->on_task4_clicked();
}


void MainWindow::on_task5_clicked()
{
    qDebug()<<"task5";
    ui_task->set_task_number(5);
    ui_task->show();
}


void MainWindow::on_action_5_triggered()
{
    this->on_task5_clicked();
}




