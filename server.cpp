#include "server.h"
#include "func.cpp"

/**
 * @brief Server::Server конструктор для сервера.
 */

Server::Server(){
    if(this->listen(QHostAddress::Any,32323)){
        qDebug()<<"Start";
    }
    else{
        qDebug()<<"Error";
    }
    nextBlockSize = 0;
}
/**
 * @brief Server::incomingConnection конструктор для подключения клиента по вкусу.

 * @param socketDescriptor сокет, по которому клиент подключается к серверу по сути.
 */
void Server::incomingConnection(qintptr socketDescriptor){
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotsReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket);
    qDebug()<<"client connected"<<socketDescriptor;

}
/**
 * @brief Server::slotsReadyRead Сервер готов читать.
 */
void Server::slotsReadyRead(){
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
    QByteArray output = parsing(str, connection_id).toUtf8();
    qDebug()<<str;
    qDebug()<<output;
    socket->write(str.toUtf8());
/////////////////////////////////////////////////
/*
    in.setVersion(QDataStream::Qt_DefaultCompiledVersion);
    if(in.status()==QDataStream::Ok){
        qDebug()<<"Read...";
        /*
        QString str;
        in >> str;
        qDebug()<<str;

        //SendToClient(str);
        for(;;){
            QString str;
            QTime time;
            in >> str;

            qDebug()<<str;
            if(nextBlockSize==0){
                qDebug() << "nextBlockSize = 0";
                if(socket->bytesAvailable()<2){
                    qDebug() << "Data < 2, break";
                    break;
                }
                in >> nextBlockSize;
                qDebug() << "nextBlockSize = "<<nextBlockSize;
            }
            if (socket->bytesAvailable()<nextBlockSize){
                qDebug() << "Data not full, break";
                break;
            }
            //QString str;
            //QTime time;
            in >> str;
            nextBlockSize=0;
            qDebug() << str;
            if(Auth_admin(str)){
                //this->SendToClient("1");
                socket->write("1");
                qDebug()<<"1";
            }
            else{
                socket->write("error&log_pass");
                //this->SendToClient("error&log_pass");
                qDebug()<<"error&log_pass";
            }

            break;
        }
    }
    else{
        qDebug()<<"DataStream error";
    }
        */

}
/*
void Server::SendToClient(QString str){
    socket->write(str.toUtf8());

   /* Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_DefaultCompiledVersion);
    out<<qint16(0)<<QTime::currentTime()<<str;
    out.device()->seek(0);
    out<<qint16(Data.size()-sizeof(qint16));
    //out<<str;
    //socket->write(Data);
    for(int i=0;i<Sockets.size();i++){
        Sockets[i]->write(Data);
    }
    qDebug()<<"send__";

//    Sockets[i]->write(str.toUtf8());
}
*/
