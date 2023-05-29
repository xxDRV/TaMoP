#include <QCoreApplication>
#include "server.h"

/**
 * @brief main функция, которая отвечает обработку сообщений сервером.
 * @param argc аргумент командной строки
 * @param argv аргумент командной строки
 * @return итог подключения командной строки.
 */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server s;
    return a.exec();
}
