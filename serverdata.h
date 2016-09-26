#ifndef SERVERDATA_H
#define SERVERDATA_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>

class ServerData : public QObject
{
    Q_OBJECT
public:
    explicit ServerData(QObject *parent = 0);
    ~ServerData();

    Q_INVOKABLE void listenServer(const QString& port);

signals:

public slots:
    void slotNewConnection();
    void readData();

private:
    QFile *file;
    QTcpServer *server;
    QTcpSocket *socket;
};

#endif // SERVERDATA_H
