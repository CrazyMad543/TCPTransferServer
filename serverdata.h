#ifndef SERVERDATA_H
#define SERVERDATA_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class ServerData : public QObject
{
    Q_OBJECT
public:
    explicit ServerData(QObject *parent = 0);
    Q_INVOKABLE void listenServer(const QString& port);

signals:

public slots:
    void slotNewConnection();

private:
    QTcpServer *server;
    QTcpSocket *socket;
};

#endif // SERVERDATA_H
