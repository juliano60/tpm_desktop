#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createaccount.h"
#include "accountwidget.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QScrollArea>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    createWidget_(0),
    accountWidget_(0)
{
    ui->setupUi(this);

    createStatusBar();
    resize(QDesktopWidget().availableGeometry(this).size() * 0.8);

    // signals and slots
    connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(showAbout()));
    connect(ui->actionExit, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(ui->actionNewAccount, SIGNAL(triggered(bool)), this, SLOT(handleCreate()));
    connect(ui->actionViewAccount, SIGNAL(triggered(bool)), this, SLOT(showAccounts()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAbout()
{
    QMessageBox::about(this,
                       tr("About TPM Desktop"),
                       tr("<h1>TPM 0.1</h1>"
                          "<p>Copyright &copy; 2016 Tiger Payment and Mail</p>"
                          "<p>TPM Desktop is a system used to manage the accounts of TPM customers.</p>")
                       );
}

void MainWindow::handleCreate()
{
    if(!createWidget_) {       
        createWidget_ = new CreateAccount;
        this->setCentralWidget(createWidget_);
        setWindowTitle(tr("New Account"));
        createWidget_->show();
        connect(createWidget_, SIGNAL(statusInfo(QString)), this, SLOT(updateStatusBar(const QString&)));
    }
    else {
        createWidget_->show();
        createWidget_->raise();
        createWidget_->activateWindow();
    }
}

void MainWindow::showAccounts()
{
    if(!accountWidget_) {
        accountWidget_ = new AccountWidget;
        this->setCentralWidget(accountWidget_);
        setWindowTitle(tr("Accounts"));
        accountWidget_->show();
    }
    else {
        accountWidget_->show();
        accountWidget_->raise();
        accountWidget_->activateWindow();
    }
}

void MainWindow::updateStatusBar(const QString &str)
{
    statusInfo_->setText(str);
}

void MainWindow::createStatusBar()
{
    statusInfo_ = new QLabel(tr(""));
    ui->statusBar->addWidget(statusInfo_, 1);
    updateStatusBar(tr("Ready"));
}
