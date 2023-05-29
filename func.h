#ifndef FUNC_H
#define FUNC_H
#include<QString>
#include<iostream>
#include<QTextStream>
#include "db.h"

/**
 * @brief authentication функция аутентификации.
 * @param login логин.
 * @param pass пароль.
 * @param connection_id id подключения.
 * @return результат аутентификации.
 */
QString authentication(QString login, QString pass, QString connection_id);

/**
 * @brief registration функция регистрации.
 * @param login логин.
 * @param pass пароль
 * @param name имя.
 * @param last_name фамилия.
 * @param patronymic_name отчество.
 * @param role роль.
 * @return результат регистрации.
 */
QString registration(QString login, QString pass, QString name, QString last_name, QString patronymic_name, QString role);
/**
 * @brief check_answer функция, которая проверяет отправлен ли ответ.
 * @param ans ответ.
 * @param num номер.
 * @return правда.
 */
bool check_answer(QString ans, int num);
/**
 * @brief check_task Проверяет задачи, решённые студентом.
 * @param connection_id id подключения.
 * @param task номер задачи.
 * @param ans ответ.
 * @return Возвращает результат проверки и данные пользователя.
 */
QString check_task(QString connection_id, QString task, QString ans);
/**
 * @brief get_stat функция, отвечающая за получение статистики.
 * @param connection_id id подключения.
 * @return возвращает статистику, в зависимости от роли пользователя. Для учителя- статистика всех учеников. Для ученика- только его личная статистика.
 */
QString get_stat(QString connection_id);
/**
 * @brief close_session отключение пользователя
 * @param connection_id id подключения.
 */
void close_session(QString connection_id);
/**
 * @brief parsing функция для сервера, которая отвечает за структурирование информации, поступающей на сервер.
 * @param data данные, поступающие на сервер.
 * @param connection_id id подключения.
 * @return Возвращает информацию, поступающую на сервер, в удобном для восприятия виде.
 */
QString parsing(QString data, QString connection_id);



#endif // FUNC_H
