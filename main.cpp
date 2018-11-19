#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "parametri.h"
#include "filtroparam.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    parametri par;
    filtroparam filtro;
    filtro.setSourceModel(&par);

    engine.rootContext()->setContextProperty("filtro",&filtro);
    engine.rootContext()->setContextProperty("elencoParametr",&par);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
