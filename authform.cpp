#include "authform.h"
#include "ui_authform.h"


AuthForm::AuthForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthForm)
{
    //socket = new QTcpSocket(this);
    ui->setupUi(this);
    ui->email_2->setVisible(false);
    ui->email->setVisible(false);
    ui->exit_button->setVisible(false);
    ui->label->setVisible(false);

}
void AuthForm::change_mode(bool mode)
{
    ui->email_2->setVisible(mode);
    ui->email->setVisible(mode);
    ui->exit_button->setVisible(mode);
    ui->enter_button->setVisible(!mode);
    //ui->label->setVisible(mode);
}
void AuthForm::log_pass_error(bool mode){
    ui->label->setVisible(mode);
}

/*void AuthForm::parse_for_client(QString str)
{
    if(str.contains("error")){
        if (str.contains("log_pass")){
            log_pass_error(true);
        }

    }
}*/

AuthForm::~AuthForm()
{
    delete ui;
}


void AuthForm::on_reg_button_clicked()
{
    /*
    if (ui->login_2->text() != nullptr){
        qDebug()<<"login&"+
              ui->login_2->text()+"&"
          +"password&"+
              ui->password_2->text()+"&"
              + "email&"+
              ui->email_2->text()+"&";
        SendToServer("login&"+
                     ui->login_2->text()+"&"
                 +"password&"+
                     ui->password_2->text()+"&"
                     + "email&"+
                     ui->email_2->text()+"&");
    }
    */
    this->change_mode(true);
}

void AuthForm::on_enter_button_clicked()
{
    qDebug()<<"login&"+
              ui->login_2->text()+"&"
          +"password&"+
              ui->password_2->text()+"&";
    if (ui->login_2->text() != nullptr){
        Client_hole::get_instance().SendToServer("login&"+
                     ui->login_2->text()+"&"
                 +"password&"+
                     ui->password_2->text()+"&"
                     + "email&"+
                     ui->email_2->text()+"&");
    }

    /*
    Client_hole hole;
    hole.SendToServer("login&"+
                      ui->login_2->text()+"&"
                  +"password&"+
                      ui->password_2->text()+"&");
                      */
    //this->parse();
    //this->close();
    //emit onClosed(ui->login_2->text());

}


void AuthForm::on_exit_button_clicked()
{
    this->change_mode(false);

}

/*void AuthForm::SendToServer(QString str)
{
    Data.clear();
    QDataStream out(&Data,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_DefaultCompiledVersion);
    out<<qint16(0)<<QTime::currentTime()<<str;
    out.device()->seek(0);
    out<<qint16(Data.size()-sizeof(qint16));
    socket->write(Data);
    //ui->lineEdit->clear();
    /*
    for(int i=0;i<Sockets.size();i++){
        Sockets[i]->write(Data);
    }
    */
//}*/

/*void AuthForm::slotsReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_DefaultCompiledVersion);
    if(in.status()==QDataStream::Ok){
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
            qDebug()<<str;
            nextBlockSize=0;
            this->parse_for_client(str);



            //ui->textBrowser->append(time.toString()+" " + str);
        }
    }
    else{
        //ui->textBrowser->append("read error");
    }
}*/

void AuthForm::on_pushButton_clicked()
{
    Client_hole::get_instance();
}



void AuthForm::on_label_linkActivated(const QString &link)
{

}

