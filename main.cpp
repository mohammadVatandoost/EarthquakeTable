#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlContext>
#include <QQuickWindow>
#include <QApplication>
#include <QDebug>
#include "backend.h"
#include "sensorslist.h"
#include "groundmotionlist.h"
#include "colibrateitemlist.h"
#include "groundmotionmodel.h"
#include "colibrateitemmodel.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QGuiApplication app(argc, argv);
    QApplication app(argc, argv);
    QQuickStyle::setStyle("Material");

    qmlRegisterType<ColibrateItemModel>("ColibrateItemModel", 1, 0, "ColibrateItemModel");
    qmlRegisterUncreatableType<ColibrateItemList>("ColibrateItemList",1,0,"ColibrateItemList",
                                         QStringLiteral("ColibrateItemList should not be created in QML"));
    qmlRegisterType<GroundMotionModel>("GroundMotionModel", 1, 0, "GroundMotionModel");
    qmlRegisterUncreatableType<GroundMotionList>("GroundMotionList",1,0,"GroundMotionList",
                                         QStringLiteral("groundMotionList should not be created in QML"));

    SensorsList sensorsList;
    GroundMotionList groundMotionList;
    ColibrateItemList colibrateItemList;
    Backend backEnd;
    backEnd.setSensorsList(&sensorsList);
    backEnd.setGroundMotionList(&groundMotionList);
    backEnd.setColibrateItemList(&colibrateItemList);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("SensorsList"), &sensorsList);
    engine.rootContext()->setContextProperty(QStringLiteral("GroundMotionList"), &groundMotionList);
    engine.rootContext()->setContextProperty(QStringLiteral("ColibrateItemList"), &colibrateItemList);
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
