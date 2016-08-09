/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNewAccount;
    QAction *actionExit;
    QAction *actionViewAccount;
    QAction *actionEditAccount;
    QAction *actionAbout;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Edit;
    QMenu *menu_Help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(544, 400);
        actionNewAccount = new QAction(MainWindow);
        actionNewAccount->setObjectName(QStringLiteral("actionNewAccount"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/16x16_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewAccount->setIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/16x16_exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionViewAccount = new QAction(MainWindow);
        actionViewAccount->setObjectName(QStringLiteral("actionViewAccount"));
        actionViewAccount->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/16x16_view.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionViewAccount->setIcon(icon2);
        actionEditAccount = new QAction(MainWindow);
        actionEditAccount->setObjectName(QStringLiteral("actionEditAccount"));
        actionEditAccount->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/16x16_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEditAccount->setIcon(icon3);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 544, 21));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QStringLiteral("menu_Edit"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_File->addAction(actionNewAccount);
        menu_File->addSeparator();
        menu_File->addAction(actionExit);
        menu_Edit->addAction(actionViewAccount);
        menu_Edit->addAction(actionEditAccount);
        menu_Help->addAction(actionAbout);
        mainToolBar->addAction(actionNewAccount);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionViewAccount);
        mainToolBar->addAction(actionEditAccount);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "TPM Desktop", 0));
        actionNewAccount->setText(QApplication::translate("MainWindow", "&New Account...", 0));
#ifndef QT_NO_TOOLTIP
        actionNewAccount->setToolTip(QApplication::translate("MainWindow", "Create a new account", 0));
#endif // QT_NO_TOOLTIP
        actionExit->setText(QApplication::translate("MainWindow", "&Exit", 0));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("MainWindow", "Close application", 0));
#endif // QT_NO_TOOLTIP
        actionViewAccount->setText(QApplication::translate("MainWindow", "&View Account...", 0));
#ifndef QT_NO_TOOLTIP
        actionViewAccount->setToolTip(QApplication::translate("MainWindow", "Display an existing account", 0));
#endif // QT_NO_TOOLTIP
        actionEditAccount->setText(QApplication::translate("MainWindow", "&Edit Account...", 0));
#ifndef QT_NO_TOOLTIP
        actionEditAccount->setToolTip(QApplication::translate("MainWindow", "Update or delete an existing account", 0));
#endif // QT_NO_TOOLTIP
        actionAbout->setText(QApplication::translate("MainWindow", "About TPM...", 0));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menu_Edit->setTitle(QApplication::translate("MainWindow", "&Edit", 0));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
