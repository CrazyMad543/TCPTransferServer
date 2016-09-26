#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "serverdata.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<ServerData> ("Server.data", 1, 0, "ServerData");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
