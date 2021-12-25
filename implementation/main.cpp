#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QQmlContext>
#include <core.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    core warper;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("core_cpp",&warper);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
