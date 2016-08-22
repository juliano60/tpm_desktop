#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class CreateAccount;
}

class CreateAccount : public QWidget
{
    Q_OBJECT

public:
    explicit CreateAccount(QWidget *parent = 0);
    ~CreateAccount();

signals:
    void statusInfo(const QString&);

private slots:
    void enableSubmit();
    void normalizeName();
    void addAttachment();
    void resetForm();
    void setupCards();
    void checkEmail();

private:
    void setMaxLengths();
    void setupValidators();
    bool validateForm();
    void createImageLabel(QLabel* lbl, const QString& imgFilename);


    Ui::CreateAccount *ui;
};

#endif // CREATEACCOUNT_H
