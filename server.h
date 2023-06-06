#ifndef SERVER_H
#define SERVER_H
#include<QTcpServer>
#include<QTcpSocket>
#include<QTime>
#include<QDataStream>

class Server : public QTcpServer{
    Q_OBJECT
public:
    Server();
    QTcpSocket *socket;

private:
    QVector <QTcpSocket*> Sockets;
    QByteArray Data;
    void SendToClient(QString str);
    qint16 nextBlockSize;
public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotsReadyRead();

};

#endif // SERVER_H
