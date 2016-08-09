#include "createaccount.h"
#include "ui_createaccount.h"
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include <QSignalMapper>
#include <QFileDialog>
#include <QDir>

CreateAccount::CreateAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateAccount)
{
    ui->setupUi(this);

    setMaxLengths();
    setupValidators();
    enableSubmit();

    // signals and slots
    QSignalMapper* mapper = new QSignalMapper(this);

    mapper->setMapping(ui->editFirstname, ui->editFirstname);
    mapper->setMapping(ui->editLastname, ui->editLastname);
    mapper->setMapping(ui->editProfession, ui->editProfession);

    connect(ui->editFirstname, SIGNAL(editingFinished()), mapper, SLOT(map()));
    connect(ui->editLastname, SIGNAL(editingFinished()), mapper, SLOT(map()));
    connect(ui->editProfession, SIGNAL(editingFinished()), mapper, SLOT(map()));
    connect(mapper, SIGNAL(mapped(QWidget*)), this, SLOT(normalizeName(QWidget*)));

    connect(ui->editFirstname, SIGNAL(editingFinished()), this, SLOT(enableSubmit()));
    connect(ui->editLastname, SIGNAL(editingFinished()), this, SLOT(enableSubmit()));
    connect(ui->editProfession, SIGNAL(editingFinished()), this, SLOT(enableSubmit()));
    connect(ui->editContact, SIGNAL(editingFinished()), this, SLOT(enableSubmit()));
    connect(ui->editID, SIGNAL(textChanged(QString)), this, SLOT(enableSubmit()));
    connect(ui->btnAttachment, SIGNAL(clicked(bool)), this, SLOT(addAttachment()));

    connect(ui->btnReset, SIGNAL(clicked(bool)), this, SLOT(resetForm()));
}

CreateAccount::~CreateAccount()
{
    delete ui;
}

void CreateAccount::enableSubmit()
{
    ui->btnSubmit->setEnabled(validateForm());
}

void CreateAccount::normalizeName(QWidget* sender)
{
    QLineEdit* source = static_cast<QLineEdit*>(sender);
    if(source->text().length() > 0) {
            source->setText(source->text().toUpper().left(1) + source->text().toLower().mid(1));
    }
}

void CreateAccount::setMaxLengths()
{
    const int maxLen = 20;

    ui->editFirstname->setMaxLength(maxLen);
    ui->editLastname->setMaxLength(maxLen);
    ui->editProfession->setMaxLength(maxLen);

    const int maxDigits = 11;
    ui->editContact->setMaxLength(maxDigits);
}

void CreateAccount::setupValidators()
{
    // simple alphabetic regex
    // TODO: update for Unicode characters
    QRegularExpression rxAlpha("^[a-zA-Z-]+$");
    QValidator* alphaValidator = new QRegularExpressionValidator(rxAlpha, this);

    ui->editFirstname->setValidator(alphaValidator);
    ui->editLastname->setValidator(alphaValidator);
    ui->editProfession->setValidator(alphaValidator);

    QRegularExpression rxNum("^\\d+$");
    QValidator* numValidator = new QRegularExpressionValidator(rxNum, this);

    ui->editContact->setValidator(numValidator);

    QRegularExpression rxEmail("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");
    QValidator* emailValidator = new QRegularExpressionValidator(rxEmail, this);

    ui->editEmail->setValidator(emailValidator);
}

bool CreateAccount::validateForm()
{
    return !ui->editFirstname->text().isEmpty() &&
            !ui->editLastname->text().isEmpty() &&
            !ui->editEmail->text().isEmpty() &&
             ui->editEmail->hasAcceptableInput() &&
            !ui->editProfession->text().isEmpty() &&
            !ui->editID->text().isEmpty();
}

void CreateAccount::addAttachment()
{
    QString supportedFiles = tr("PDF Documents (*.pdf);;"
                                "Images (*.png *.jpeg *.jpg)"
                                );

    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Add Attachment:"),
                                                    QDir::currentPath(),
                                                    supportedFiles
                                                    );
    if(!filename.isEmpty()) {
        ui->editID->setText(filename);
        enableSubmit();
    }
}

void CreateAccount::resetForm()
{
    ui->editFirstname->clear();
    ui->editLastname->clear();
    ui->editProfession->clear();
    ui->editEmail->clear();
    ui->editContact->clear();
    ui->editID->clear();

    enableSubmit();
}
