#include "client_hole.h"


Client_hole_destroyer::~Client_hole_destroyer(){
    delete p_instance;
}
void Client_hole_destroyer::initialize(Client_hole *p){
    p_instance = p;
}
Client_hole& Client_hole::get_instance(){
    if(!p_instance){
        p_instance = new Client_hole();
        destroyer.initialize(p_instance);
    }
    return *p_instance;
}

Client_hole::Client_hole(){
    socket = new QTcpSocket;
    socket->connectToHost("127.0.0.1",2323);
    nextBlockSize = 0;
}


void Client_hole::SendToServer(QString str)
{
    /*
    Data.clear();
    QDataStream out(&Data,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_DefaultCompiledVersion);
    out<<qint16(0)<<QTime::currentTime()<<str;
    out.device()->seek(0);
    out<<qint16(Data.size()-sizeof(qint16));
    */
    socket->write(str.toUtf8());
    //ui->lineEdit->clear();
    /*
    for(int i=0;i<Sockets.size();i++){
        Sockets[i]->write(Data);
    }
    */
}
void Client_hole::slotsReadyRead()
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
            qDebug()<<str;
            nextBlockSize=0;
            //this->parse_for_client(str);



            //ui->textBrowser->append(time.toString()+" " + str);
        }
    }
    else{
        //ui->textBrowser->append("read error");
    }
}


Client_hole * Client_hole::p_instance = 0;
Client_hole_destroyer Client_hole::destroyer;
