#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_task = new TaskForm;
    ui_auth = new AuthForm;
    socket = new QTcpSocket(this);
    connect(ui_auth,&AuthForm::onClosed, this, &MainWindow::slot_show);
    connect(socket,&QTcpSocket::readyRead,this,&MainWindow::slotsReadyRead);
    connect(socket,&QTcpSocket::disconnected,socket,&QTcpSocket::deleteLater);
    nextBlockSize = 0;
    ui_auth->show();

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

void MainWindow::slot_show(QString log)
{
    this->show();
    ui->NameLabel->setText(log);
}

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


void MainWindow::slotsReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_DefaultCompiledVersion);
    if(in.status()==QDataStream::Ok){
        /*QString str;
        in >> str;
        ui->textBrowser->append(str);*/
        for(;;){
            if(nextBlockSize==0){
                if(socket->bytesAvailable()<2){
                    break;
                }
                in >> nextBlockSize;
            }
            if (socket->bytesAvailable()<nextBlockSize){
                break;
            }
            QString str;
            QTime time;
            in >>time >> str;
            nextBlockSize=0;
            //ui->textBrowser->append(time.toString()+" " + str);
        }
    }
    else{
        //ui->textBrowser->append("read error");
    }
}
void MainWindow::SendToServer(QString str)
{
    Data.clear();
    QDataStream out(&Data,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_DefaultCompiledVersion);
    out<<qint16(0)<<QTime::currentTime()<<str;
    out.device()->seek(0);
    out<<qint16(Data.size()-sizeof(qint16));
    socket->write(Data);
    //ui->lineEdit->clear();
}
