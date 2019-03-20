#include <QApplication>

#include <QQmlContext>
#include <QQuickItem>
#include <QQuickView>

#include <QQmlComponent>
#include <QObject>
#include <QDebug>
#include <QQmlProperty>

#include <QThread>
#include <QQmlApplicationEngine>

#include "backend.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    BackEnd* backEnd = new BackEnd();

    QQmlApplicationEngine engine;
    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:/main.qml")));
    QQmlContext *context = engine.rootContext();
    QObject *object = component.create();

    backEnd->getObjects(object, context);

    engine.rootContext()->setContextProperty("backEnd", backEnd);

    return app.exec();
}
