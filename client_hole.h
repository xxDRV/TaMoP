#ifndef CLIENT_HOLE_H
#define CLIENT_HOLE_H

#include<QTcpSocket>
#include<QTime>
#include<QDataStream>
#include <QObject>

class Client_hole;

/**
 * @brief The Client_hole_destroyer class Класс для разрыва соединения с клиентом.
 */
class Client_hole_destroyer{
private:
    Client_hole *p_instance;
public:
    ~Client_hole_destroyer();
    /**
     * @brief initialize Функция, отвечающая за существование единственного клиента (все следующие клиенты уничтожаются).
     * @param p клиент.
     */
    void initialize(Client_hole *p);
};


/**
 * @brief The Client_hole class  Класс для установки соединения с клиентом.
 */
class Client_hole:public QObject
{
        Q_OBJECT

private:

    static Client_hole* p_instance;
    static Client_hole_destroyer destroyer;
    QTcpSocket* socket;
    qint16 nextBlockSize;
    QByteArray Data;


protected:
    Client_hole();
    Client_hole(const Client_hole&);
    Client_hole& operator =(Client_hole &);
    ~Client_hole(){}
    friend class Client_hole_destroyer;

public:
    //void connect();
    /**
     * @brief SendToServer функция отправки сообщения на сервер.
     * @param str сообщение, отправляемое на сервер.
     */
    void SendToServer(QString str);
    /**
     * @brief get_instance если не существует подключения, то создаётся новое.
     * @return подключение.
     */
    static Client_hole& get_instance();

public slots:
    /**
     * @brief slotsReadyRead Функция, которая отвечает за то, что клиент готов принимать сообщения.
     */
    void slotsReadyRead();
};
/*
class Client:public QObject{
        Q_OBJECT
private:

    QTcpSocket *socket;
    qint16 nextBlockSize;
public:

    void SendToServer(QString str);
public slots:

    void slotsReadyRead();
};
*/

#endif // CLIENT_HOLE_H
