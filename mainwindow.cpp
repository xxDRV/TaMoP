#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief MainWindow::MainWindow конструктор класса MainWindow.
 * @param parent предок класса MainWindow.
 */
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
/**
 * @brief MainWindow::~MainWindow деструктор MainWindow.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::on_pushButton_3_clicked слот, реагирующий на нажатие кнопки выхода.
 */
void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}
/**
 * @brief MainWindow::on_action_6_triggered слот, реагирующий на нажатие кнопки выхода через меню.
 */
void MainWindow::on_action_6_triggered()
{
    this->on_pushButton_3_clicked();
}

/**
 * @brief MainWindow::on_task1_clicked слот, реагирующий на нажатие кнопки task1.
 */
void MainWindow::on_task1_clicked()
{
    qDebug()<<"task1";
    ui_task->set_task_number(1);
    ui_task->show();
}
/**
 * @brief MainWindow::on_action_1_triggered слот, реагирующий на нажатие кнопки task1 через меню.
 */
void MainWindow::on_action_1_triggered()
{
    this->on_task1_clicked();
}
/**
 * @brief MainWindow::slot_show слот, отвечающий за отображение логина пользователя.
 * @param log логин.
 */
void MainWindow::slot_show(QString log)
{
    this->show();
    ui->NameLabel->setText(log);
}
/**
 * @brief MainWindow::on_task2_clicked слот, реагирующий на нажатие кнопки task2.
 */
void MainWindow::on_task2_clicked()
{
    qDebug()<<"task2";
    ui_task->set_task_number(2);
    ui_task->show();
}

/**
 * @brief MainWindow::on_action_2_triggered слот, реагирующий на нажатие кнопки task2 через меню.
 */
void MainWindow::on_action_2_triggered()
{
   this->on_task2_clicked();
}

/**
 * @brief MainWindow::on_task3_clicked слот, реагирующий на нажатие кнопки task3.
 */
void MainWindow::on_task3_clicked()
{
   qDebug()<<"task3";
   ui_task->set_task_number(3);
   ui_task->show();
}

/**
 * @brief MainWindow::on_action_3_triggered слот, реагирующий на нажатие кнопки task3 через меню.
 */
void MainWindow::on_action_3_triggered()
{
    this->on_task3_clicked();
}

/**
 * @brief MainWindow::on_task4_clicked слот, реагирующий на нажатие кнопки task4.
 */
void MainWindow::on_task4_clicked()
{
    qDebug()<<"task4";
    ui_task->set_task_number(4);
    ui_task->show();
}
/**
 * @brief MainWindow::on_action_4_triggered слот, реагирующий на нажатие кнопки task4 через меню.
 */

void MainWindow::on_action_4_triggered()
{
     this->on_task4_clicked();
}

/**
 * @brief MainWindow::on_task5_clicked слот, реагирующий на нажатие кнопки task5.
 */
void MainWindow::on_task5_clicked()
{
    qDebug()<<"task5";
    ui_task->set_task_number(5);
    ui_task->show();
}

/**
 * @brief MainWindow::on_action_5_triggered слот, реагирующий на нажатие кнопки task5 через меню.
 */
void MainWindow::on_action_5_triggered()
{
    this->on_task5_clicked();
}

/**
 * @brief MainWindow::slotsReadyRead слот, отвечающий за готовность клиента принять сообщение от сервера.
 */
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
/**
 * @brief MainWindow::SendToServer Функция, отвечающая за отправку сообщения на сервер.
 * @param str сообщение, отправляемое на сервер.
 */
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
