#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class CreateAccount;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void showAbout();
    void handleCreate();

private:
    Ui::MainWindow *ui;
    CreateAccount* createWidget_;
};

#endif // MAINWINDOW_H
