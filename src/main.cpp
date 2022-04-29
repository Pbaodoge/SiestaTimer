#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <string>
#include "timer.hpp"

int main(int argc, char *argv[])
 {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    qmlRegisterType<MAINDATA>("main.data", 1, 0, "Data");
    const QUrl url(QStringLiteral("qrc:///QtQuickTest/main.qml"));
    engine.load(url);
    return app.exec();
 }
