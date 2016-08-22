#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QThread>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

bool createConnection();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QSplashScreen* splash = new QSplashScreen;
    //splash->setPixmap(QPixmap(":/splash.jpg"));
    //splash->show();

    if(!createConnection()) {
        return -1;
    }

    //Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    //splash->showMessage(QObject::tr("Loading modules..."), topRight, Qt::white);
    //QThread::sleep(2);

    MainWindow w;
    //splash->showMessage(QObject::tr("Establishing connections..."), topRight, Qt::white);
    //QThread::sleep(2);

    w.show();
    //splash->finish(&w);
    //delete splash;
    return a.exec();
}

bool createConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("mydbinstance.cxurj1vwxauq.us-west-2.rds.amazonaws.com");
    db.setDatabaseName("test");
    db.setUserName("test");
    db.setPassword("d8A5eT3s");
    if(!db.open()) {
        QMessageBox::critical(0, QObject::tr("Database Error"),
                db.lastError().text());
        return false;
    }
    return true;
}

