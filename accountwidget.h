#ifndef ACCOUNTWIDGET_H
#define ACCOUNTWIDGET_H

#include <QWidget>

class QSqlTableModel;

namespace Ui {
class AccountWidget;
}

class AccountWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AccountWidget(QWidget *parent = 0);
    ~AccountWidget();

private:
    Ui::AccountWidget *ui;
    QSqlTableModel* tableModel_;
};

#endif // ACCOUNTWIDGET_H
