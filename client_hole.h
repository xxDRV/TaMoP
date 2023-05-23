#ifndef CLIENT_HOLE_H
#define CLIENT_HOLE_H

#include<QTcpSocket>
#include<QTime>
#include<QDataStream>
#include <QObject>

class Client_hole;


class Client_hole_destroyer{
private:
    Client_hole *p_instance;
public:
    ~Client_hole_destroyer();
    void initialize(Client_hole *p);
};



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
    void SendToServer(QString str);
    static Client_hole& get_instance();

public slots:

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
