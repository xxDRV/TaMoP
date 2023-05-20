#include<QString>
#include<iostream>
#include<QTextStream>

bool Auth_admin(QString str){
    //str = "login&admin&password&qwerty&email&jeff9352397@gmail.com&";
    QTextStream out(stdout);
    QStringList str2 = str.split('&');
    bool flag = true;
    QString adm = "admin";
    for (int i =1;i<4;i+=2){
        if (str2[i]!=adm){
            flag = false;
            break;
        }
    }
    return flag;
}
