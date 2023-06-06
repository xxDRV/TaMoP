#include<QString>
#include<QList>
#include<iostream>
#include<QTextStream>
#include <cmath>
#include <vector>
#include<string>
#include <algorithm>
#include<cmath>
#include"authform.h"
#include <QtCore/QCoreApplication>


QString parsing(QString data, QString id_conn)
{
    QList<QString> parametrs = data.split("+");
    if(parametrs[0] == "auth" and parametrs[1]=="ok\r\n"){
        //change_form_main();
        return "auth+ok";
    }
    if(parametrs[0] == "check"){
        if(parametrs[1]=="ok")
            return "check+correct";
        else
            return "check+incorrect";
    }
    if(parametrs[0] == "reg" and parametrs[1]=="ok\r\n"){
        //change_form_main();
        return "reg+ok";
    }
    //return "auth+none";

}
