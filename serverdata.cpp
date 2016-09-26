#include "serverdata.h"

#include <QDebug>

ServerData::ServerData(QObject *parent) : QObject(parent) {
    server = new QTcpServer();
}

void ServerData::listenServer(const QString &port) {
    server->listen(QHostAddress::Any, port.toInt());
    connect(server, &QTcpServer::newConnection, this, &ServerData::slotNewConnection);
}

void ServerData::slotNewConnection() {
    socket = server->nextPendingConnection();
    qDebug() << "New Connection!";
}
