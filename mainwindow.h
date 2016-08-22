#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class CreateAccount;
class AccountWidget;
class QLabel;

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
    void showAccounts();
    void updateStatusBar(const QString& str);

private:
    void createStatusBar();

    Ui::MainWindow *ui;
    CreateAccount* createWidget_;
    AccountWidget* accountWidget_;
    QLabel* statusInfo_;
};

#endif // MAINWINDOW_H
