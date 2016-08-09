#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createaccount.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    createWidget_(0)
{
    ui->setupUi(this);

    // signals and slots
    connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(showAbout()));
    connect(ui->actionExit, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(ui->actionNewAccount, SIGNAL(triggered(bool)), this, SLOT(handleCreate()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAbout()
{
    QMessageBox::about(this,
                       tr("About TPM Desktop"),
                       tr("<h2>TPM 0.1</h2>"
                          "<p>Copyright &copy; 2016 Tiger Payment and Mail</p>"
                          "<p>TPM Desktop is a system used to manage the accounts of TPM customers.</p>")
                       );
}

void MainWindow::handleCreate()
{
    if(!createWidget_) {
        createWidget_ = new CreateAccount(this);
        this->setCentralWidget(createWidget_);
        setWindowTitle(tr("New Account"));
        createWidget_->show();
    }
}
