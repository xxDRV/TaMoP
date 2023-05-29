#include "client_hole.h"
#include "func.h"

/**
 * @brief Client_hole_destroyer::~Client_hole_destroyer деструктор Client_hole_destroyer.
 */
Client_hole_destroyer::~Client_hole_destroyer(){
    delete p_instance;
}
/**
 * @brief Client_hole_destroyer::initialize Функция, отвечающая за существование единственного клиента (все следующие клиенты уничтожаются).
 * @param p клиент.
 */
void Client_hole_destroyer::initialize(Client_hole *p){
    p_instance = p;
}
/**
 * @brief Client_hole::get_instance если не существует подключения, то создаётся новое.
 * @return подключение.
 */
Client_hole& Client_hole::get_instance(){
    if(!p_instance){
        p_instance = new Client_hole();
        destroyer.initialize(p_instance);
    }
    return *p_instance;
}
/**
 * @brief Client_hole::Client_hole конструктор для клиента.
 */
Client_hole::Client_hole(){
    socket = new QTcpSocket;
    socket->connectToHost("127.0.0.1",32323);
    nextBlockSize = 0;
}

/**
 * @brief Client_hole::SendToServer функция отправки сообщения на сервер.
 * @param str сообщение, отправляемое на сервер.
 */
void Client_hole::SendToServer(QString str)
{
    //qDebug()<<str;
/*
    Data.clear();
    QDataStream out(&Data,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_DefaultCompiledVersion);
    out<<qint16(0)<<QTime::currentTime()<<str;
    out.device()->seek(0);
    qDebug()<<Data.size()-sizeof(qint16);
    out<<qint16(Data.size()-sizeof(qint16));
*/
    //socket->write((QTime::fromMSecsSinceStartOfDay(10*1000).toString("hh:mm:ss")).append(str)).toUtf8());
    //socket->write((QString::fromStdString(QTime::currentTime().toString("HH")).append(str)).toUtf8());
    socket->write(str.toUtf8());
    //ui->lineEdit->clear();
/*
    for(int i=0;i<Sockets.size();i++){
        Sockets[i]->write(Data);
    }
    */

}
/**
 * @brief Client_hole::slotsReadyRead Функция, которая отвечает за то, что клиент готов принимать сообщения.
 */
void Client_hole::slotsReadyRead()
{


    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
///////////////////////////////////////////
    QByteArray arr;
    QString str = "";
    QString connection_id = QString::number(socket->socketDescriptor());
    while(socket->bytesAvailable()>0)
    {
        arr = socket->readAll();
        str+=arr;
    }
    qDebug()<<"1";
    QByteArray output = parsing(str, connection_id).toUtf8();
    qDebug()<<"2";
    //qDebug()<<str;
    qDebug()<<output;

    /*
/////////////////////////////////////////////////
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_DefaultCompiledVersion);
    if(in.status()==QDataStream::Ok){
        /*
        QString str;
        in >> str;
        ui->textBrowser->append(str);

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
            qDebug()<<"1";
            qDebug()<<str;
            nextBlockSize=0;
            QString connection_id = QString::number(socket->socketDescriptor());

            QByteArray output = parsing(str, connection_id).toUtf8();
            //this->parse_for_client(str);



            //ui->textBrowser->append(time.toString()+" " + str);
        }
    }
    else{
        //ui->textBrowser->append("read error");
    }
*/

}

/**
 * @brief Client_hole::p_instance отключенное подключение.
 */
Client_hole * Client_hole::p_instance = 0;
/**
 * @brief Client_hole::destroyer очистка всех данных о подключении.
 */
Client_hole_destroyer Client_hole::destroyer;
