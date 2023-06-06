#ifndef FUNC_H
#define FUNC_H
#include<QString>
#include<iostream>
#include<QTextStream>
#include "db.h"


QString authentication(QString login, QString pass, QString connection_id);


QString registration(QString login, QString pass, QString name, QString last_name, QString patronymic_name, QString role);

bool check_answer(QString ans, int num);

QString check_task(QString connection_id, QString task, QString ans);

QString get_stat(QString connection_id);

void close_session(QString connection_id);

QString parsing(QString data, QString connection_id);



#endif // FUNC_H
