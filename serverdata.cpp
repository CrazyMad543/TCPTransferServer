#include "serverdata.h"

ServerData::ServerData(QObject *parent) : QObject(parent) {
    server = new QTcpServer();
}

ServerData::~ServerData() {
    delete server;
}

void ServerData::listenServer(const QString &port) {
    server->listen(QHostAddress::Any, port.toInt());
    connect(server, &QTcpServer::newConnection, this, &ServerData::slotNewConnection);
}

void ServerData::slotNewConnection() {
    socket = server->nextPendingConnection();

    file = new QFile("download.exe");
    file->open(QIODevice::WriteOnly | QIODevice::Truncate);

    connect(socket, &QTcpSocket::readyRead, this, &ServerData::readData);
}

void ServerData::readData() {
    QByteArray byteArray;
    byteArray += socket->read(socket->bytesAvailable());
    file->write(byteArray);
    byteArray.clear();
}

