#ifndef FUNC_CLIENT_H
#define FUNC_CLIENT_H
#include<QString>
#include<iostream>
#include<QTextStream>
/**
 * @brief parsing парсинг.
 * @param data данные о пользователе.
 * @param connection_id id подключения.
 * @return строка test (?).
 */
QString parsing(QString data, QString connection_id);


#endif // FUNC_CLIENT_H
