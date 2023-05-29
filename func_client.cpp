#include<QString>
#include<QList>
#include<iostream>
#include<QTextStream>
#include <cmath>
#include <vector>
#include<string>
#include <algorithm>
#include<cmath>

/**
 * @brief parsing парсинг.
 * @param data данные о пользователе.
 * @param connection_id id подключения.
 * @return строка test (?).
 */
QString parsing(QString data, QString connection_id)
{
    QList<QString> parametrs = data.split("+");
    return "test";

}
