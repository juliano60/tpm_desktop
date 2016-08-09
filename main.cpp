#include "mainwindow.h"
#include <QApplication>
#include "createaccount.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //CreateAccount w;
    w.show();
    return a.exec();
}
