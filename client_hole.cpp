#include "client_hole.h"
#include "func_client.h"
#include"authform.h"


Client_hole_destroyer::~Client_hole_destroyer(){
    delete p_instance;
}
void Client_hole_destroyer::initialize(Client_hole *p){
    p_instance = p;
}
Client_hole* Client_hole::get_instance(){
    if(!p_instance){
        p_instance = new Client_hole();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

Client_hole::Client_hole(){
    socket = new QTcpSocket;
    socket->connectToHost("127.0.0.1",32323);
   // nextBlockSize = 0;
    //this->ui_a = new AuthForm;
    connect(socket, &QTcpSocket::readyRead, this, &Client_hole::slotsReadyRead);
    //connect(ui,&AuthForm::onClosed,this, &Client_hole::change_form);
    //connect(ui_a, &AuthForm::onClosed(), this, &Client_hole::parse);

}


void Client_hole::SendToServer(QString str)
{
    socket->write(str.toUtf8());



}
void Client_hole::slotsReadyRead()
{


   // socket = (QTcpSocket*)sender();
   // QDataStream in(socket);
///////////////////////////////////////////
    QByteArray arr;
    QString str = "";
    QString connection_id = "12345";//QString::number(socket->socketDescriptor());
    while(socket->bytesAvailable()>0)
    {
        arr = socket->readAll();
        str+=arr;
    }
    qDebug()<<"1";
    qDebug()<<str;
    QByteArray output = parsing(str, connection_id).toUtf8();


    qDebug()<<"2";
    //qDebug()<<str;
    qDebug()<<output;
    if(output =="auth+ok")
        emit onAuth();
    if(output == "check+correct")
        emit checking_cor();
    if (output=="check+incorrect")
        emit checking_incor();
    if(output == "reg+ok"){
        emit onAuth();
    }


}

Client_hole * Client_hole::p_instance = 0;
Client_hole_destroyer Client_hole::destroyer;
