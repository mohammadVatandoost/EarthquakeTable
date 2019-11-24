#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlContext>
#include <QQuickWindow>
#include <QApplication>
#include "backend.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QGuiApplication app(argc, argv);
    QApplication app(argc, argv);
    QQuickStyle::setStyle("Material");

//    qmlRegisterType<SensorModel>("SensorModel", 1, 0, "SensorModel");
//    qmlRegisterUncreatableType<SensorsList>("SensorsList",1,0,"SensorsList",
//                                         QStringLiteral("SensorsList should not be created in QML"));
//    SensorsList sensorsList;
    Backend backEnd;
//    backEnd.setSensorsList(&sensorsList);
    QQmlApplicationEngine engine;
//    engine.rootContext()->setContextProperty(QStringLiteral("SensorsList"), &sensorsList);
    engine.rootContext()->setContextProperty(QStringLiteral("BackEnd"), &backEnd);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    // for connecting qml slot to c++ signal
//    QObject *topLevel = engine.rootObjects().value(0);
//    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);

    // connect our QML signal to our C++ slot
//    QObject::connect(&backEnd, SIGNAL(notifyInfoDataChanged()),
//                            window, SLOT(refreshData()));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
