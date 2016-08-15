#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen* splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/splash.jpg"));
    splash->show();

    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash->showMessage(QObject::tr("Loading modules..."), topRight, Qt::white);
    QThread::sleep(2);

    MainWindow w;
    splash->showMessage(QObject::tr("Establishing connections..."), topRight, Qt::white);
    QThread::sleep(2);

    w.show();
    splash->finish(&w);
    delete splash;
    return a.exec();
}
