#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QWidget>

namespace Ui {
class CreateAccount;
}

class CreateAccount : public QWidget
{
    Q_OBJECT

public:
    explicit CreateAccount(QWidget *parent = 0);
    ~CreateAccount();

private slots:
    void enableSubmit();
    void normalizeName(QWidget* sender);
    void addAttachment();
    void resetForm();

private:
    void setMaxLengths();
    void setupValidators();
    bool validateForm();


    Ui::CreateAccount *ui;
};

#endif // CREATEACCOUNT_H
