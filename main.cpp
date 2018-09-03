#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <fstream>
#include <iostream>
#include <QDebug>
#include <QTextStream>
#include "airport.h"
#include "filegenerator.h"
#include "dummyconsumer.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    GlobalTime::getInstance();

    Airport a("/home/radu/intern_project/conf2");
    DummyConsumer dummy;
    FileGenerator fg;
    fg.registerConsumer(&a);
    //fg.registerConsumer(&dummy);

    fg.generateRequests("/home/radu/intern_project/test2");
    std::this_thread::sleep_for(std::chrono::seconds(20));
    a.stop();
    return 0;
    return app.exec();
}
