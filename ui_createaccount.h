/********************************************************************************
** Form generated from reading UI file 'createaccount.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEACCOUNT_H
#define UI_CREATEACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateAccount
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLineEdit *editFirstname;
    QLabel *label_2;
    QLineEdit *editLastname;
    QLabel *label_4;
    QLineEdit *editProfession;
    QLabel *label_5;
    QLineEdit *editEmail;
    QLabel *label_6;
    QLineEdit *editContact;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *editID;
    QPushButton *btnAttachment;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QLineEdit *editAmount;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSubmit;
    QPushButton *btnReset;

    void setupUi(QWidget *CreateAccount)
    {
        if (CreateAccount->objectName().isEmpty())
            CreateAccount->setObjectName(QStringLiteral("CreateAccount"));
        CreateAccount->resize(625, 467);
        QFont font;
        font.setFamily(QStringLiteral("Verdana"));
        font.setPointSize(10);
        CreateAccount->setFont(font);
        gridLayout = new QGridLayout(CreateAccount);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(CreateAccount);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setUnderline(false);
        groupBox->setFont(font1);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        editFirstname = new QLineEdit(groupBox);
        editFirstname->setObjectName(QStringLiteral("editFirstname"));

        verticalLayout_3->addWidget(editFirstname);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        editLastname = new QLineEdit(groupBox);
        editLastname->setObjectName(QStringLiteral("editLastname"));

        verticalLayout_3->addWidget(editLastname);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        editProfession = new QLineEdit(groupBox);
        editProfession->setObjectName(QStringLiteral("editProfession"));

        verticalLayout_3->addWidget(editProfession);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);

        editEmail = new QLineEdit(groupBox);
        editEmail->setObjectName(QStringLiteral("editEmail"));

        verticalLayout_3->addWidget(editEmail);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_3->addWidget(label_6);

        editContact = new QLineEdit(groupBox);
        editContact->setObjectName(QStringLiteral("editContact"));

        verticalLayout_3->addWidget(editContact);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        editID = new QLineEdit(groupBox);
        editID->setObjectName(QStringLiteral("editID"));
        editID->setReadOnly(true);

        horizontalLayout_3->addWidget(editID);

        btnAttachment = new QPushButton(groupBox);
        btnAttachment->setObjectName(QStringLiteral("btnAttachment"));

        horizontalLayout_3->addWidget(btnAttachment);


        verticalLayout_3->addLayout(horizontalLayout_3);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(CreateAccount);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_4 = new QGroupBox(groupBox_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        radioButton = new QRadioButton(groupBox_4);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        horizontalLayout_4->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox_4);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setEnabled(false);
        radioButton_2->setCheckable(true);

        horizontalLayout_4->addWidget(radioButton_2);


        verticalLayout_2->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(groupBox_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout = new QVBoxLayout(groupBox_5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        editAmount = new QLineEdit(groupBox_5);
        editAmount->setObjectName(QStringLiteral("editAmount"));

        verticalLayout->addWidget(editAmount);

        verticalSpacer = new QSpacerItem(20, 196, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addWidget(groupBox_5);


        gridLayout->addWidget(groupBox_3, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox_2 = new QGroupBox(CreateAccount);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSubmit = new QPushButton(groupBox_2);
        btnSubmit->setObjectName(QStringLiteral("btnSubmit"));

        horizontalLayout->addWidget(btnSubmit);

        btnReset = new QPushButton(groupBox_2);
        btnReset->setObjectName(QStringLiteral("btnReset"));

        horizontalLayout->addWidget(btnReset);


        horizontalLayout_2->addWidget(groupBox_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 2);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(editFirstname);
        label_2->setBuddy(editLastname);
        label_4->setBuddy(editProfession);
        label_5->setBuddy(editEmail);
        label_6->setBuddy(editContact);
        label_3->setBuddy(btnAttachment);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(editLastname, editProfession);
        QWidget::setTabOrder(editProfession, editEmail);
        QWidget::setTabOrder(editEmail, editContact);
        QWidget::setTabOrder(editContact, btnAttachment);
        QWidget::setTabOrder(btnAttachment, editID);
        QWidget::setTabOrder(editID, btnReset);

        retranslateUi(CreateAccount);

        btnSubmit->setDefault(true);


        QMetaObject::connectSlotsByName(CreateAccount);
    } // setupUi

    void retranslateUi(QWidget *CreateAccount)
    {
        CreateAccount->setWindowTitle(QApplication::translate("CreateAccount", "Form", 0));
        groupBox->setTitle(QApplication::translate("CreateAccount", "Contact Information", 0));
        label->setText(QApplication::translate("CreateAccount", "*&Firstname:", 0));
        label_2->setText(QApplication::translate("CreateAccount", "*&Lastname:", 0));
        label_4->setText(QApplication::translate("CreateAccount", "&Profession:", 0));
        label_5->setText(QApplication::translate("CreateAccount", "*&Email:", 0));
        label_6->setText(QApplication::translate("CreateAccount", "*&Contact:", 0));
        label_3->setText(QApplication::translate("CreateAccount", "*Proof of &ID:", 0));
        btnAttachment->setText(QApplication::translate("CreateAccount", "Attach", 0));
        groupBox_3->setTitle(QApplication::translate("CreateAccount", "Payment Information", 0));
        groupBox_4->setTitle(QApplication::translate("CreateAccount", "Method", 0));
        radioButton->setText(QApplication::translate("CreateAccount", "Cash", 0));
        radioButton_2->setText(QApplication::translate("CreateAccount", "Bank Card", 0));
        groupBox_5->setTitle(QApplication::translate("CreateAccount", "Balance", 0));
        label_7->setText(QApplication::translate("CreateAccount", "Amount (\302\243):", 0));
        groupBox_2->setTitle(QString());
        btnSubmit->setText(QApplication::translate("CreateAccount", "Submit", 0));
        btnReset->setText(QApplication::translate("CreateAccount", "Reset", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateAccount: public Ui_CreateAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEACCOUNT_H
