#include "authform.h"
#include "ui_authform.h"

bool form_mode = false;


AuthForm::AuthForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthForm)
{
    //socket = new QTcpSocket(this);
    ui->setupUi(this);
    ui->surname->setVisible(false);
    ui->surname_2->setVisible(false);
    ui->second_name_2->setVisible(false);
    ui->second_name->setVisible(false);
    ui->firstname_2->setVisible(false);
    ui->firstname->setVisible(false);
    ui->role->setVisible(false);
    ui->student->setVisible(false);
    ui->teacher->setVisible(false);
    ui->exit_button->setVisible(false);
    ui->label->setVisible(false);

}
void AuthForm::change_mode(bool mode)
{
    ui->surname->setVisible(mode);
    ui->surname_2->setVisible(mode);
    ui->second_name_2->setVisible(mode);
    ui->second_name->setVisible(mode);
    ui->role->setVisible(mode);
    ui->student->setVisible(mode);
    ui->teacher->setVisible(mode);
    ui->firstname_2->setVisible(mode);
    ui->firstname->setVisible(mode);
    ui->exit_button->setVisible(mode);
    ui->reg_button->setVisible(!mode);
    if(mode==false){
        ui->surname_2->clear();
        ui->second_name_2->clear();
        ui->firstname_2->clear();
    }
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
/*
void change_form_main(){
    AuthForm::transp();
}

void AuthForm::transp(){
    this->close();
    emit onClosed(ui->login_2->text());
}
*/
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
    form_mode = true;
    this->change_mode(true);

}

QString AuthForm::get_log()
{
    return ui->login_2->text();
}

void AuthForm::on_enter_button_clicked()
{
    /*
    qDebug()<<"login+"+
              ui->login_2->text()+"+"
          +"password+"+
              ui->password_2->text()+"+";
              */
    if (ui->login_2->text() != nullptr && ui->password_2->text()!=nullptr && form_mode==false){

        Client_hole::get_instance()->SendToServer("auth+"+
                     ui->login_2->text()+"+"+
                     ui->password_2->text());
    }
    else{
        AuthForm::log_pass_error(true);
    }
    if (ui->login_2->text() != nullptr && form_mode==true){
        QString role;
        if(ui->student->isChecked()){
            qDebug()<<"enable";
            role = "student";
        }
        else{

            role = "teacher";
        }

        Client_hole::get_instance()->SendToServer("reg+"+
                     ui->login_2->text()+"+"+
                     ui->password_2->text()+"+" + ui->firstname_2->text()+"+"+ui->surname_2->text()+"+"+ui->second_name_2->text()+"+"+role);


    }



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

