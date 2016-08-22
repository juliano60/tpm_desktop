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
#include <QDateTime>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

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
    ui->dummyBox->setMinimumSize(ui->cardBox->sizeHint());

    ui->editEmail->setMinimumSize(ui->editEmail->sizeHint());
    createImageLabel(ui->lblTick, ":/tick.png");
    ui->lblTick->setVisible(false);
    ui->lblTick->setMinimumSize(ui->lblTick->sizeHint());

    // signals and slots

    connect(ui->editFirstname, SIGNAL(editingFinished()), this, SLOT(normalizeName()));
    connect(ui->editMiddlename, SIGNAL(editingFinished()), this, SLOT(normalizeName()));
    connect(ui->editLastname, SIGNAL(editingFinished()), this, SLOT(normalizeName()));
    connect(ui->editProfession, SIGNAL(editingFinished()), this, SLOT(normalizeName()));

    // connect required fields to submit
    connect(ui->editFirstname, SIGNAL(editingFinished()), this, SLOT(enableSubmit()));
    connect(ui->editLastname, SIGNAL(editingFinished()), this, SLOT(enableSubmit()));
    connect(ui->editEmail, SIGNAL(editingFinished()), this, SLOT(checkEmail()));
    connect(ui->editContact, SIGNAL(editingFinished()), this, SLOT(enableSubmit()));
    connect(ui->editAttachment, SIGNAL(textChanged(QString)), this, SLOT(enableSubmit()));
    connect(ui->editAmount, SIGNAL(editingFinished()), this, SLOT(enableSubmit()));

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

void CreateAccount::normalizeName()
{
    QLineEdit* source = qobject_cast<QLineEdit*>(sender());
    if(source->text().length() > 0) {
            source->setText(source->text().toUpper().left(1) + source->text().toLower().mid(1));
    }
}

void CreateAccount::setMaxLengths()
{
    const int maxLen = 30;

    ui->editFirstname->setMaxLength(maxLen);
    ui->editLastname->setMaxLength(maxLen);
    ui->editMiddlename->setMaxLength(maxLen);
    ui->editProfession->setMaxLength(maxLen);
    ui->editEmail->setMaxLength(maxLen);

    const int maxDigits = 11;
    ui->editContact->setMaxLength(maxDigits);
}

void CreateAccount::setupValidators()
{
    // simple alphabetic regex
    // TODO: update for Unicode characters
    QRegularExpression rxAlpha("^[a-zA-Z-]+$");
    QValidator* alphaValidator = new QRegularExpressionValidator(rxAlpha, this);

    // firstname

    ui->editFirstname->setValidator(alphaValidator);
    ui->editFirstname->setPlaceholderText(tr("e.g. Mike"));

    // middle name

    ui->editMiddlename->setValidator(alphaValidator);
    ui->editMiddlename->setPlaceholderText(tr("e.g. Joe"));

    // lastname

    ui->editLastname->setValidator(alphaValidator);
    ui->editLastname->setPlaceholderText(tr("e.g. Stones"));

    // profession

    ui->editProfession->setValidator(alphaValidator);
    ui->editProfession->setPlaceholderText(tr("e.g. Engineer"));

    QRegularExpression rxNum("^\\d+$");
    QValidator* numValidator = new QRegularExpressionValidator(rxNum, this);

    // contact

    ui->editContact->setValidator(numValidator);
    ui->editContact->setPlaceholderText("e.g. 01202876543");

    // email

    QRegularExpression rxEmail("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");
    QValidator* emailValidator = new QRegularExpressionValidator(rxEmail, this);

    ui->editEmail->setValidator(emailValidator);
    ui->editEmail->setPlaceholderText("e.g. joe.stones@gmail.com");

    // amount
    ui->editAmount->setValidator(numValidator);

    // cardnumber
    ui->editCardNumber->setInputMask("9999-9999-9999-9999");
}

bool CreateAccount::validateForm()
{
    return !ui->editFirstname->text().isEmpty() &&
            !ui->editLastname->text().isEmpty() &&
            !ui->editEmail->text().isEmpty() &&
                ui->editEmail->hasAcceptableInput() &&
            !ui->editContact->text().isEmpty() &&
                ui->editContact->hasAcceptableInput() &&
            !ui->editAttachment->text().isEmpty() &&
            !ui->editAmount->text().isEmpty();
}

void CreateAccount::createImageLabel(QLabel *lbl, const QString &imgFilename)
{
    QPixmap img(imgFilename);
    lbl->setPixmap(img);
    lbl->setMask(img.mask());
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
        ui->editAttachment->setText(filename);
        enableSubmit();
        emit statusInfo("Photo ID attached");
    }
}

void CreateAccount::resetForm()
{
    // clear edit fields
    ui->editFirstname->clear();
    ui->editMiddlename->clear();
    ui->editLastname->clear();
    ui->editProfession->clear();
    ui->editEmail->clear();
    ui->editContact->clear();
    ui->editAttachment->clear();
    ui->editAmount->clear();
    ui->editCardHolderName->clear();
    ui->editCardNumber->clear();
    ui->editCardSecurity->clear();

    // reset radios
    ui->radioCash->setEnabled(true);

    // reset combos
    ui->cmbCardType->setCurrentIndex(0);
    ui->cmbCardMonth->setCurrentIndex(0);
    ui->cmbCardYear->setCurrentIndex(0);

    // labels
    ui->lblTick->setVisible(false);

    enableSubmit();
}

void CreateAccount::setupCards()
{
    createImageLabel(ui->lblVisa, ":/visa.png");
    createImageLabel(ui->lblMaestro, ":/maestro.png");
    createImageLabel(ui->lblAmex, ":/amex.png");

    // setup card year
    ui->cmbCardYear->clear();
    ui->cmbCardYear->addItem("Year");
    int cyear = QDateTime::currentDateTime().date().year();
    for(int i = cyear; i <= cyear+10; ++i) {
        ui->cmbCardYear->addItem(QString::number(i));
    }

    // setup card month
    ui->cmbCardMonth->clear();
    QStringList months;
    months << tr("Month")
           << tr("January")
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

void CreateAccount::checkEmail()
{
    QSqlQuery query;
    if(!query.exec(QString("SELECT * FROM customer where email = '%1'").arg(ui->editEmail->text()))){
        qDebug() << query.lastError().text();
        return;
    }

    qDebug() << "Row count: " << query.size();
    QString icons[] = {":/cross.png", ":/tick.png"};

    if(query.size() >= 1) {
        createImageLabel(ui->lblTick, icons[0]);
        ui->lblTick->setVisible(true);
        ui->lblTick->setToolTip(tr("Email already registered"));
    }
    else {
        createImageLabel(ui->lblTick, icons[1]);
        ui->lblTick->setVisible(true);
    }
}
