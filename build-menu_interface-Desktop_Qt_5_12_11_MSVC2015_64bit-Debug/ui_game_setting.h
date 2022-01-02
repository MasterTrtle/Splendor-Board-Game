/********************************************************************************
** Form generated from reading UI file 'game_setting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_SETTING_H
#define UI_GAME_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_game_setting
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *nb_jouers;
    QLabel *label_3;
    QCheckBox *AI_checkBox;
    QLineEdit *usename1;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *usename1_2;
    QLineEdit *usename1_3;
    QLineEdit *usename1_4;
    QLabel *label_7;
    QCheckBox *AI_checkBox_2;

    void setupUi(QDialog *game_setting)
    {
        if (game_setting->objectName().isEmpty())
            game_setting->setObjectName(QString::fromUtf8("game_setting"));
        game_setting->resize(290, 325);
        buttonBox = new QDialogButtonBox(game_setting);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-110, 280, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(game_setting);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 81, 21));
        label_2 = new QLabel(game_setting);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 160, 111, 20));
        nb_jouers = new QSpinBox(game_setting);
        nb_jouers->setObjectName(QString::fromUtf8("nb_jouers"));
        nb_jouers->setGeometry(QRect(200, 160, 42, 22));
        nb_jouers->setMinimum(2);
        nb_jouers->setMaximum(4);
        label_3 = new QLabel(game_setting);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 200, 91, 16));
        AI_checkBox = new QCheckBox(game_setting);
        AI_checkBox->setObjectName(QString::fromUtf8("AI_checkBox"));
        AI_checkBox->setGeometry(QRect(230, 200, 73, 18));
        usename1 = new QLineEdit(game_setting);
        usename1->setObjectName(QString::fromUtf8("usename1"));
        usename1->setGeometry(QRect(140, 20, 111, 20));
        label_4 = new QLabel(game_setting);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 50, 81, 21));
        label_5 = new QLabel(game_setting);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 80, 81, 21));
        label_6 = new QLabel(game_setting);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 110, 81, 21));
        usename1_2 = new QLineEdit(game_setting);
        usename1_2->setObjectName(QString::fromUtf8("usename1_2"));
        usename1_2->setGeometry(QRect(140, 50, 111, 20));
        usename1_3 = new QLineEdit(game_setting);
        usename1_3->setObjectName(QString::fromUtf8("usename1_3"));
        usename1_3->setEnabled(false);
        usename1_3->setGeometry(QRect(140, 80, 111, 20));
        usename1_4 = new QLineEdit(game_setting);
        usename1_4->setObjectName(QString::fromUtf8("usename1_4"));
        usename1_4->setEnabled(false);
        usename1_4->setGeometry(QRect(140, 110, 111, 20));
        label_7 = new QLabel(game_setting);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 230, 91, 16));
        AI_checkBox_2 = new QCheckBox(game_setting);
        AI_checkBox_2->setObjectName(QString::fromUtf8("AI_checkBox_2"));
        AI_checkBox_2->setGeometry(QRect(230, 230, 73, 18));

        retranslateUi(game_setting);
        QObject::connect(buttonBox, SIGNAL(rejected()), game_setting, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(clicked(QAbstractButton*)), game_setting, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(accepted()), game_setting, SLOT(accept()));

        QMetaObject::connectSlotsByName(game_setting);
    } // setupUi

    void retranslateUi(QDialog *game_setting)
    {
        game_setting->setWindowTitle(QApplication::translate("game_setting", "Dialog", nullptr));
        label->setText(QApplication::translate("game_setting", "Player1 nom", nullptr));
        label_2->setText(QApplication::translate("game_setting", "Nombre de joueurs", nullptr));
        label_3->setText(QApplication::translate("game_setting", "Activer IA", nullptr));
        AI_checkBox->setText(QString());
        label_4->setText(QApplication::translate("game_setting", "Player2 nom", nullptr));
        label_5->setText(QApplication::translate("game_setting", "Player3 nom", nullptr));
        label_6->setText(QApplication::translate("game_setting", "Player4 nom", nullptr));
        label_7->setText(QApplication::translate("game_setting", "Extension", nullptr));
        AI_checkBox_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class game_setting: public Ui_game_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_SETTING_H
