#include "accountwidget.h"
#include "ui_accountwidget.h"
#include <QSqlTableModel>

namespace {
    enum {
        CUSTOMER_ID = 0,
        FIRSTNAME,
        LASTNAME,
        GENDER,
        EMAIL,
        PHONE,
        BALANCE
    };
}

AccountWidget::AccountWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountWidget)
{
    ui->setupUi(this);

    tableModel_ = new QSqlTableModel(this);
    tableModel_->setTable("customer");
    tableModel_->setSort(FIRSTNAME, Qt::AscendingOrder);
    tableModel_->setHeaderData(FIRSTNAME, Qt::Horizontal, tr("Firstname"));
    tableModel_->setHeaderData(LASTNAME, Qt::Horizontal, tr("Lastname"));
    tableModel_->setHeaderData(GENDER, Qt::Horizontal, tr("Gender"));
    tableModel_->setHeaderData(EMAIL, Qt::Horizontal, tr("Email"));
    tableModel_->setHeaderData(PHONE, Qt::Horizontal, tr("Phone"));
    tableModel_->setHeaderData(BALANCE, Qt::Horizontal, tr("Balance"));
    tableModel_->select();

    ui->tableView->setModel(tableModel_);
    //ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setColumnHidden(CUSTOMER_ID, true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

AccountWidget::~AccountWidget()
{
    delete ui;
}
