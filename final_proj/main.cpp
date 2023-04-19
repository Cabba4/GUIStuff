#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <audioplayer.h>
#include <QPushButton>
#include <QTextBrowser>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    audioplayer audioPlayer;
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    // Get the root object of the QML file
    QObject *rootObject = engine.rootObjects().first();

    // Get the play button from the QML file
    QPushButton *playButton = rootObject->findChild<QPushButton*>("playButton");

    // Get the music list text from the QML file
    QTextBrowser *musicList = rootObject->findChild<QTextBrowser*>("musicList");

    // Connect the AudioPlayer signals to the Button slots
    QObject::connect(&audioPlayer, &audioplayer::playStateChanged, playButton, &QPushButton::setText);
    QObject::connect(&audioPlayer, &audioplayer::songChanged, musicList, &QTextBrowser::setText);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
