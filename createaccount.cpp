#include "createaccount.h"
#include "ui_createaccount.h"
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include <QSignalMapper>
#include <QFileDialog>
#include <QDir>
#include <QPixmap>
#include <QBitmap>
#include <QStringList>

CreateAccount::CreateAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateAccount)
{
    ui->setupUi(this);

    setMaxLengths();
    setupValidators();
    setupCards();

    ui->btnSubmit->setEnabled(false);
    ui->cardBox->setVisible(false);
    ui->balanceBox->setMinimumSize(ui->cardBox->sizeHint());



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

void CreateAccount::setupCards()
{
    QPixmap visa(":/visa.png");
    ui->lblVisa->setPixmap(visa);
    ui->lblVisa->setMask(visa.mask());

    QPixmap maestro(":/maestro.png");
    ui->lblMaestro->setPixmap(maestro);
    ui->lblMaestro->setMask(maestro.mask());

    QPixmap amex(":/amex.png");
    ui->lblAmex->setPixmap(amex);
    ui->lblAmex->setMask(amex.mask());

    // setup card year
    ui->cmbCardYear->clear();
    for(int i = 2016; i <= 2026; ++i) {
        ui->cmbCardYear->addItem(QString::number(i));
    }

    // setup card month
    ui->cmbCardMonth->clear();
    QStringList months;
    months << tr("January")
           << tr("February")
           << tr("March")
           << tr("April")
           << tr("May")
           << tr("June")
           << tr("July")
           << tr("August")
           << tr("September")
           << tr("October")
           << tr("November")
           << tr("December")
              ;
    ui->cmbCardMonth->addItems(months);
}
