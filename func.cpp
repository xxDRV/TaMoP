#include<QString>
#include<iostream>
#include<QTextStream>
#include "db.h"
#include <cmath>
#include <vector>
#include<string>
#include <algorithm>
#include<cmath>

using namespace std;

/**
 * @brief authentication аутентификация
 * @param login логин
 * @param pass пароль
 * @param connection_id id подключения.
 * @return Возвращает результат аутентификации (успешно или нет).
 */
QString authentication(QString login, QString pass, QString connection_id)
{
    QList<QString> query_list = {"SELECT * FROM Users WHERE login = :login and password = :password;",
        ":login", login,
        ":password", pass
    };
    QString response = DataBase::Connect()->query_execute(query_list);

    if (response == "")
    {
        return "auth+wrong\r\n";
    }
    else
    {
        query_list = {"UPDATE Users SET connection_id = :connection_id WHERE login = :login;",
            ":login", login,
            ":connection_id", connection_id
        };
        DataBase::Connect()->query_execute(query_list);

        return "auth+ok\r\n";
    }
}
/**
 * @brief registration регистрация пользователя
 * @param login логин
 * @param pass пароль
 * @param name имя
 * @param last_name Фамилия
 * @param patronymic_name Отчество
 * @param role роль (ученик или учитель).
 * @return Возвращает результат регистрации (успешно или нет).
 */
QString registration(QString login, QString pass, QString name, QString last_name, QString patronymic_name, QString role)
{
    QList<QString> query_list = {"SELECT * FROM Users WHERE login = :login;",
        ":login", login
    };
    QString response = DataBase::Connect()->query_execute(query_list);

    if (response != "")
    {
        return "reg+already\r\n";
    }

    if (role == "student")
    {
        query_list = {"INSERT INTO Users "
                      "(login, password, name, last_name, patronymic_name, role, connection_id, task1_stat, task2_stat, task3_stat, task4_stat, task5_stat)"
                      " VALUES (:login, :pass, :name, :last_name, :patronymic_name, 'student', NULL, 0, 0, 0, 0, 0);",
                      ":login", login,
                      ":pass", pass,
                      ":name", name,
                      ":last_name", last_name,
                      ":patronymic_name", patronymic_name,
                      };
        DataBase::Connect()->query_execute(query_list);
    }
    else if (role == "teacher")
    {
        query_list = {"INSERT INTO Users "
                      "(login, password, name, last_name, patronymic_name, role, connection_id, task1_stat, task2_stat, task3_stat, task4_stat, task5_stat) "
                      "VALUES (:login, :pass, :name, :last_name, :patronymic_name, 'teacher', NULL, 0, 0, 0, 0, 0);",
                      ":login", login,
                      ":pass", pass,
                      ":name", name,
                      ":last_name", last_name,
                      ":patronymic_name", patronymic_name,
                      };
        DataBase::Connect()->query_execute(query_list);
    }
    query_list = {"SELECT * FROM Users WHERE login = :login;",
        ":login", login
    };
    response = DataBase::Connect()->query_execute(query_list);

    if (response == "")
    {
        return "reg+error\r\n";
    }
    return "reg+ok\r\n";
}
/**
 * @brief check_answer функция, которая проверяет отправлен ли ответ.
 * @param ans ответ.
 * @param num номер задания.
 * @return правда.
 */
bool check_answer(QString ans, int num)
{
    return true;
}
/**
 * @brief check_task Проверяет задачи, решённые студентом.
 * @param connection_id id подключения.
 * @param task номер задачи.
 * @param ans ответ.
 * @return Возвращает результат проверки и данные пользователя.
 */
QString check_task(QString connection_id, QString task, QString ans)
{
    QList<QString> query_list = {"SELECT * FROM Users WHERE connection_id = :connection_id;",
        ":connection_id", connection_id
    };
    QString response = DataBase::Connect()->query_execute(query_list);

    if (response != "")
    {
        if (task == "1")
        {
            if (check_answer(ans, 1))
            {
                query_list = {"UPDATE Users SET task1_stat = task1_stat + 1 WHERE connection_id = :connection_id;",
                    ":connection_id", connection_id
                };
                DataBase::Connect()->query_execute(query_list);
            }
            else
            {
                query_list = {"UPDATE Users SET task1_stat = task1_stat - 1 WHERE connection_id = :connection_id;",
                    ":connection_id", connection_id
                };
                DataBase::Connect()->query_execute(query_list);
            }
        }
        if (task == "2")
        {
            if (check_answer(ans, 2))
            {
                query_list = {"UPDATE Users SET task2_stat = task2_stat + 1 WHERE connection_id = :connection_id;",
                    ":connection_id", connection_id
                };
                DataBase::Connect()->query_execute(query_list);
            }
            else
            {
                query_list = {"UPDATE Users SET task2_stat = task2_stat - 1 WHERE connection_id = :connection_id;",
                    ":connection_id", connection_id
                };
                DataBase::Connect()->query_execute(query_list);
            }
        }
        if (task == "3")
        {
            if (check_answer(ans, 3))
            {
                query_list = {"UPDATE Users SET task3_stat = task3_stat + 1 WHERE connection_id = :connection_id;",
                    ":connection_id", connection_id
                };
                DataBase::Connect()->query_execute(query_list);
            }
            else
            {
                query_list = {"UPDATE Users SET task3_stat = task3_stat - 1 WHERE connection_id = :connection_id;",
                    ":connection_id", connection_id
                };
                DataBase::Connect()->query_execute(query_list);
            }
        }
        if (task == "4")
        {
            if (check_answer(ans, 4))
            {
                query_list = {"UPDATE Users SET task4_stat = task4_stat + 1 WHERE connection_id = :connection_id;",
                    ":connection_id", connection_id
                };
                DataBase::Connect()->query_execute(query_list);
            }
            else
            {
                query_list = {"UPDATE Users SET task4_stat = task4_stat - 1 WHERE connection_id = :connection_id;",
                    ":connection_id", connection_id
                };
                DataBase::Connect()->query_execute(query_list);
            }
        }
        if (task == "5")
        {
            if (check_answer(ans, 5))
            {
                query_list = {"UPDATE Users SET task5_stat = task5_stat + 1 WHERE connection_id = :connection_id;",
                    ":connection_id", connection_id
                };
                DataBase::Connect()->query_execute(query_list);
            }
            else
            {
                query_list = {"UPDATE Users SET task5_stat = task5_stat - 1 WHERE connection_id = :connection_id;",
                    ":connection_id", connection_id
                };
                DataBase::Connect()->query_execute(query_list);
            }
        }
        return "check+ok\r\n";
    }
    return "chek+autherr\r\n";
}
/**
 * @brief get_stat функция, отвечающая за получение статистики.
 * @param connection_id id подключения.
 * @return возвращает статистику, в зависимости от роли пользователя. Для учителя- статистика всех учеников. Для ученика- только его личная статистика.
. */
QString get_stat(QString connection_id)
{
    QList<QString> query_list = {"SELECT role FROM Users WHERE connection_id = :connection_id;",
        ":connection_id", connection_id
    };
    QString role = DataBase::Connect()->query_execute(query_list);

    QString response = "";

    if (role == "student;")
    {
        QList<QString> query_list = {"SELECT task1_stat, task2_stat, task3_stat, task4_stat, task5_stat FROM Users "
            "WHERE connection_id = :connection_id;",
            ":connection_id", connection_id
        };
        response = DataBase::Connect()->query_execute(query_list);
        return response;
    }
    else if (role == "teacher;")
    {
        QList<QString> query_list = {"SELECT name, last_name, patronymic_name, task1_stat, task2_stat, task3_stat, task4_stat, task5_stat FROM Users "
                                     "WHERE role = 'student';"};
        response = DataBase::Connect()->query_execute(query_list);
        return response;
    }
    return "stat+autherr\r\n";
}
/**
 * @brief close_session отключение пользователя.
 * @param connection_id id подключения.
 */
void close_session(QString connection_id)
{
    QList<QString> query_list = {"UPDATE Users SET connection_id = NULL WHERE connection_id = :connection_id;",
        ":connection_id", connection_id
    };
    DataBase::Connect()->query_execute(query_list);
}
/**
 * @brief parsing функция для сервера, которая отвечает за структурирование информации, поступающей на сервер.
 * @param data данные, поступающие на сервер.
 * @param connection_id id подключения.
 * @return Возвращает информацию, поступающую на сервер, в удобном для восприятия виде.
 */
QString parsing(QString data, QString connection_id)
{
    QList<QString> parametrs = data.split("+");

    if(parametrs[0] == "auth" and parametrs.count() == 3)
    {
       return authentication(parametrs[1], parametrs[2], connection_id);
    }
    else if(parametrs[0] == "reg" and parametrs.count() == 7)
    {
       return registration(parametrs[1], parametrs[2], parametrs[3], parametrs[4], parametrs[5], parametrs[6]);
    }
    else if(parametrs[0] == "c")
    {
        return "\r\n check \r\n";
    }
    else if(parametrs[0] == "s")
    {
        return "\r\n start \r\n";
    }
    else if(parametrs[0] == "l")
    {
        return "\r\n logout \r\n";
    }
    else {
        return "Error data parsing\r\n";
    }
}
























/**
 * @brief M1_to_f Данная функция преобразует множество М1 в булеву функцию в виде строки.
 * @param s строка для множества M1
 * @return возвращает функцию f
 */
string M1_to_f(string s){
    string delimiter = ",";
    string sub = "";
    int r_pos = s.rfind(",");
    for(int i =r_pos+1;i<s.size();i++){
        sub+=s[i];
    }
    int step = pow(2, ceil(log(stoi(sub))/log(2)));
    string M(step,'0');
    //cout<<M<<"\n";
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        M[stoi(token)]='1';
        s.erase(0, pos + delimiter.length());
    }
    M[stoi(s)]='1';
    return M;
}





/**
 * @brief isSelfDual  В данной функции на вход поступает строка. После этого создается копия данной строки, переворачивается и все нули заменяются на единицы и наоборот.
 * На следующем шаге мы сравниваем строки.
 * @param s строка, которая подаётся на вход и сразу же преобразовывается в множество M1.
 * @return возвращает правду или ложь (является ли функция самодвойственной или нет)
 */

QString isSelfDual(QString qs) {
    string s = qs.toStdString();
    string M = M1_to_f(s);
    string M2 = M;
    reverse(M2.begin(), M2.end());
    for(int i=0;i<M2.size();i++){
        if (M2[i]=='0')
            M2[i]='1';
        else
            M2[i]='0';
    }
    if (M2==M)
        return "true";

    else
        return "false";
}

/**
 * @brief Dual функция, которая строит вектор значений двойственной функции.
 * @param qs строка, которая подаётся на вход и сразу же преобразовывается в множество M1.
 * @return возвращается вектор значений двойственной функции.
 */

QString Dual(QString qs) {
    string s = qs.toStdString();
    string M = M1_to_f(s);
    string M2 = M;
    reverse(M2.begin(), M2.end());
    QString M3 = QString::fromStdString(M2);
    return M3;
}
/**
 * @brief isMonotonic функция, которая исследует функцию,  заданную множеством M1, на монотонность.
 * @param qs строка, которая подаётся на вход и сразу же преобразовывается в множество M1.
 * @return Возвращает правду или ложь.
 */
QString isMonotonic(QString qs) {
    string s = qs.toStdString();
    string M = M1_to_f(s);
    QString sss = QString::fromStdString(M);
    qDebug()<<sss;
    bool flag_up = true;
    for(int i=1;i<M.size();i++){
        if (M[i-1]=='1' && M[i]=='0')
            flag_up = false;
    }
    bool flag_down = true;
    for(int i=1;i<M.size();i++){
        if (M[i-1]=='0' && M[i]=='1')
            flag_down = false;
    }
    if (flag_down || flag_up)
        return "true";
    else
        return "false";
}
