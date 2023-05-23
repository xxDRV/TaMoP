#include "server.h"
#include "func.cpp"

/**
 * @brief Server::Server
 * Здесь будет описание сервера
 *
 *
 *
 *
 * Тут будет что-то еще...
 *
 *
 *
 *
 *
 *
 * И еще что-то.
 */

Server::Server(){
    if(this->listen(QHostAddress::Any,2323)){
        qDebug()<<"Start";
    }
    else{
        qDebug()<<"Error";
    }
    nextBlockSize = 0;
}
void Server::incomingConnection(qintptr socketDescriptor){
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotsReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket);
    qDebug()<<"client connected"<<socketDescriptor;

}

void Server::slotsReadyRead(){
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_DefaultCompiledVersion);
    if(in.status()==QDataStream::Ok){
        qDebug()<<"Read...";
        QString str;
        in >> str;
        qDebug()<<str;
        //SendToClient(str);
        for(;;){
            QString str;
            QTime time;
            in >>time >> str;
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
            in >>time >> str;
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
}

void Server::SendToClient(QString str){
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
    */
//    Sockets[i]->write(str.toUtf8());
}
