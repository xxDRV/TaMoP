#include<QString>
#include<iostream>
#include<QTextStream>
#include "db.h"

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

bool check_answer(QString ans, int num)
{
    return true;
}

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

void close_session(QString connection_id)
{
    QList<QString> query_list = {"UPDATE Users SET connection_id = NULL WHERE connection_id = :connection_id;",
        ":connection_id", connection_id
    };
    DataBase::Connect()->query_execute(query_list);
}

QString parsing(QString data, QString connection_id)
{
    QString clear_data = data.left(data.lastIndexOf("\xd"));
    QList<QString> parametrs = clear_data.split("+");

    if(parametrs[0] == "a")
    {
        return "\r\n auth \r\n";
    }
    else if(parametrs[0] == "r")
    {
        return "\r\n registr \r\n";
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
