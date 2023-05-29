#ifndef SERVER_H
#define SERVER_H
#include<QTcpServer>
#include<QTcpSocket>
#include<QTime>
#include<QDataStream>

/**
 * @brief The Server class класс для сервера.
 */
class Server : public QTcpServer{
    Q_OBJECT
public:
    Server();
    QTcpSocket *socket;
private:
    /**
     * @brief Sockets сокеты.
     */
    QVector <QTcpSocket*> Sockets;
    QByteArray Data;
    /**
     * @brief SendToClient
     * @param str
     */
    void SendToClient(QString str);
    qint16 nextBlockSize;
public slots:
    /**
     * @brief incomingConnection конструктор для подключения клиента.
     * @param socketDescriptor сокет, по которому клиент подключается к серверу.
     */
    void incomingConnection(qintptr socketDescriptor);
    /**
     * @brief slotsReadyRead Сервер готов читать.
     */
    void slotsReadyRead();

};

#endif // SERVER_H
