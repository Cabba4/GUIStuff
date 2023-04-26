#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <audioplayer.h>
#include <QDebug>
#include <QQmlContext>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QStringList songList;
    songList << "qrc:/jjk.mp3";
    songList << "qrc:/fight-club.mp3";
    songList << "qrc:/condition_one.ogg";

    audioplayer audioPlayer(songList);

    // line above is making audio player with a songlist as input for constructor. run debugger to check values. WILL HELP

    qDebug() << "AudioPlayer initialized with song list:" << audioPlayer.getSongList();
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    engine.rootContext()-> setContextProperty("audioplayer", &audioPlayer);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
