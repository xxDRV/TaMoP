#include "mainwindow.h"

#include <QApplication>
/**
 * @brief qMain функция, которая отвечает обработку сообщений клиентом.
 * @param argc аргумент командной строки.
 * @param argv аргумент командной строки.
 * @return результат подключения командной строки.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    return a.exec();
}
