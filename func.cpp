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































/**
 * @brief isSelfDual
 * @param s
 * @return
 * Данная функция преобразует множество М1 в булеву функцию в виде строки.
 * Затем создается копия данной строки, переворачивается и все нули заменяются на единицы и наоборот.
 * На следующем шаге мы сравниваем строки.
 * При условии, что строки эквивалентны - возвращается true, в противном случае - false.
 */


bool isSelfDual(std::string s) {
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
    string M2 = M;
    reverse(M2.begin(), M2.end());
    for(int i=0;i<M2.size();i++){
        if (M2[i]=='0')
            M2[i]='1';
        else
            M2[i]='0';
    }
    if (M2==M)
        return true;
    else
        return false;
}

bool isMonotonic(const std::vector<int>& M1) {
    int size = M1.size();

    // Проверяем монотонность по возрастанию
    bool isIncreasing = true;
    for (int i = 1; i < size; i++) {
        if (M1[i] < M1[i - 1]) {
            isIncreasing = false;
            break;
        }
    }

    // Проверяем монотонность по убыванию, только если функция не является монотонной по возрастанию
    bool isDecreasing = true;
    if (!isIncreasing) {
        for (int i = 1; i < size; i++) {
            if (M1[i] > M1[i - 1]) {
                isDecreasing = false;
                break;
            }
        }
    }

    return isIncreasing || isDecreasing;
}
