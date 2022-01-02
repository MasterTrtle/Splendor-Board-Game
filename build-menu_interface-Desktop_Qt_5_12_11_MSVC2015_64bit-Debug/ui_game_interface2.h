/********************************************************************************
** Form generated from reading UI file 'game_interface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_INTERFACE_H
#define UI_GAME_INTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameInterface
{
public:
    QPushButton *card1_1;
    QPushButton *card1_2;
    QPushButton *card1_3;
    QPushButton *card1_4;
    QPushButton *card2_1;
    QPushButton *card2_2;
    QPushButton *card2_3;
    QPushButton *card2_4;
    QPushButton *card3_1;
    QPushButton *card3_2;
    QPushButton *card3_3;
    QPushButton *card3_4;
    QTextBrowser *gold_num;
    QTextBrowser *black_num;
    QTextBrowser *red_num;
    QTextBrowser *green_num;
    QTextBrowser *blue_num;
    QTextBrowser *white_num;
    QLabel *money;
    QTextBrowser *white_have;
    QTextBrowser *blue_have;
    QTextBrowser *green_have;
    QTextBrowser *red_have;
    QTextBrowser *black_have;
    QLabel *label;
    QTextBrowser *gold_have;
    QPushButton *selectBlack;
    QPushButton *selectRed;
    QPushButton *selectGreen;
    QPushButton *selectBlue;
    QPushButton *selectWhite;
    QTextBrowser *gradePeople2;
    QTextBrowser *gradePeople1;
    QToolButton *re;
    QToolButton *changeMan;
    QLabel *background;
    QToolButton *oppo1;
    QLabel *oppo_turn;
    QLabel *oppo_turn_2;
    QLabel *highlight1_1;
    QLabel *highlight1_2;
    QLabel *highlight1_3;
    QLabel *highlight1_4;
    QLabel *highlight2_1;
    QLabel *highlight2_2;
    QLabel *highlight2_3;
    QLabel *highlight2_4;
    QLabel *highlight3_1;
    QLabel *highlight3_2;
    QLabel *highlight3_3;
    QLabel *highlight3_4;
    QTextBrowser *black_card;
    QTextBrowser *blue_card;
    QTextBrowser *green_card;
    QTextBrowser *red_card;
    QTextBrowser *white_card;
    QToolButton *reserved1;
    QToolButton *reserved2;
    QToolButton *reserved3;
    QToolButton *noble1;
    QToolButton *noble2;
    QToolButton *noble3;
    QLabel *highlight4_1;
    QLabel *highlight4_2;
    QLabel *highlight4_3;
    QLabel *yellowLight1_1;
    QLabel *yellowLight1_2;
    QLabel *yellowLight1_3;
    QLabel *yellowLight1_4;
    QLabel *yellowLight2_1;
    QLabel *yellowLight2_2;
    QLabel *yellowLight2_3;
    QLabel *yellowLight2_4;
    QLabel *yellowLight3_1;
    QLabel *yellowLight3_2;
    QLabel *yellowLight3_3;
    QLabel *yellowLight3_4;
    QLabel *yellowLight4_1;
    QLabel *yellowLight4_2;
    QLabel *yellowLight4_3;
    QLabel *name2;
    QLabel *name1;
    QToolButton *musicC;

    void setupUi(QWidget *gameInterface)
    {
        if (gameInterface->objectName().isEmpty())
            gameInterface->setObjectName(QString::fromUtf8("gameInterface"));
        gameInterface->resize(1400, 800);
        gameInterface->setMinimumSize(QSize(1400, 800));
        gameInterface->setMaximumSize(QSize(1400, 800));
        gameInterface->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/\346\211\223\345\274\200\347\225\214\351\235\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        gameInterface->setWindowIcon(icon);
        gameInterface->setStyleSheet(QString::fromUtf8("#gameInterface{\n"
"border-image: url(:/images/background.png);\n"
"}"));
        card1_1 = new QPushButton(gameInterface);
        card1_1->setObjectName(QString::fromUtf8("card1_1"));
        card1_1->setGeometry(QRect(310, 80, 141, 171));
        card1_1->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border-image: url(:/images/card/blue-high/1.png);\n"
"\n"
"\n"
""));
        card1_2 = new QPushButton(gameInterface);
        card1_2->setObjectName(QString::fromUtf8("card1_2"));
        card1_2->setGeometry(QRect(490, 80, 141, 171));
        card1_2->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border-image: url(:/images/card/blue-high/2.png);"));
        card1_3 = new QPushButton(gameInterface);
        card1_3->setObjectName(QString::fromUtf8("card1_3"));
        card1_3->setGeometry(QRect(670, 80, 141, 171));
        card1_3->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border-image: url(:/images/card/blue-high/3.png);"));
        card1_4 = new QPushButton(gameInterface);
        card1_4->setObjectName(QString::fromUtf8("card1_4"));
        card1_4->setGeometry(QRect(860, 80, 141, 171));
        card1_4->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border-image: url(:/images/card/blue-high/4.png);"));
        card2_1 = new QPushButton(gameInterface);
        card2_1->setObjectName(QString::fromUtf8("card2_1"));
        card2_1->setGeometry(QRect(310, 270, 141, 171));
        card2_1->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border-image: url(:/images/card/yellow-middle/1.png);"));
        card2_2 = new QPushButton(gameInterface);
        card2_2->setObjectName(QString::fromUtf8("card2_2"));
        card2_2->setGeometry(QRect(490, 270, 141, 171));
        card2_2->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border-image: url(:/images/card/yellow-middle/2.png);"));
        card2_3 = new QPushButton(gameInterface);
        card2_3->setObjectName(QString::fromUtf8("card2_3"));
        card2_3->setGeometry(QRect(670, 270, 141, 171));
        card2_3->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border-image: url(:/images/card/yellow-middle/3.png);"));
        card2_4 = new QPushButton(gameInterface);
        card2_4->setObjectName(QString::fromUtf8("card2_4"));
        card2_4->setGeometry(QRect(860, 270, 141, 171));
        card2_4->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border-image: url(:/images/card/yellow-middle/4.png);"));
        card3_1 = new QPushButton(gameInterface);
        card3_1->setObjectName(QString::fromUtf8("card3_1"));
        card3_1->setGeometry(QRect(310, 470, 141, 171));
        card3_1->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border-image: url(:/images/card/green-low/1.png);"));
        card3_2 = new QPushButton(gameInterface);
        card3_2->setObjectName(QString::fromUtf8("card3_2"));
        card3_2->setGeometry(QRect(490, 470, 141, 171));
        card3_2->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border-image: url(:/images/card/green-low/2.png);"));
        card3_3 = new QPushButton(gameInterface);
        card3_3->setObjectName(QString::fromUtf8("card3_3"));
        card3_3->setGeometry(QRect(670, 470, 141, 171));
        card3_3->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border-image: url(:/images/card/green-low/3.png);"));
        card3_4 = new QPushButton(gameInterface);
        card3_4->setObjectName(QString::fromUtf8("card3_4"));
        card3_4->setGeometry(QRect(860, 470, 141, 171));
        card3_4->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border-image: url(:/images/card/green-low/4.png);\n"
""));
        gold_num = new QTextBrowser(gameInterface);
        gold_num->setObjectName(QString::fromUtf8("gold_num"));
        gold_num->setGeometry(QRect(1030, 110, 41, 41));
        gold_num->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        black_num = new QTextBrowser(gameInterface);
        black_num->setObjectName(QString::fromUtf8("black_num"));
        black_num->setGeometry(QRect(1030, 200, 51, 51));
        black_num->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        red_num = new QTextBrowser(gameInterface);
        red_num->setObjectName(QString::fromUtf8("red_num"));
        red_num->setGeometry(QRect(1040, 310, 51, 41));
        red_num->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        green_num = new QTextBrowser(gameInterface);
        green_num->setObjectName(QString::fromUtf8("green_num"));
        green_num->setGeometry(QRect(1050, 410, 51, 51));
        green_num->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        blue_num = new QTextBrowser(gameInterface);
        blue_num->setObjectName(QString::fromUtf8("blue_num"));
        blue_num->setGeometry(QRect(1060, 510, 41, 41));
        blue_num->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        white_num = new QTextBrowser(gameInterface);
        white_num->setObjectName(QString::fromUtf8("white_num"));
        white_num->setGeometry(QRect(1070, 630, 41, 41));
        white_num->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        money = new QLabel(gameInterface);
        money->setObjectName(QString::fromUtf8("money"));
        money->setGeometry(QRect(480, 710, 501, 91));
        money->setStyleSheet(QString::fromUtf8("border-image: url(:/images/bb.png);\n"
"border-radius:20px;"));
        white_have = new QTextBrowser(gameInterface);
        white_have->setObjectName(QString::fromUtf8("white_have"));
        white_have->setGeometry(QRect(535, 730, 51, 61));
        white_have->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        blue_have = new QTextBrowser(gameInterface);
        blue_have->setObjectName(QString::fromUtf8("blue_have"));
        blue_have->setGeometry(QRect(635, 730, 51, 61));
        blue_have->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        green_have = new QTextBrowser(gameInterface);
        green_have->setObjectName(QString::fromUtf8("green_have"));
        green_have->setGeometry(QRect(730, 730, 51, 61));
        green_have->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        red_have = new QTextBrowser(gameInterface);
        red_have->setObjectName(QString::fromUtf8("red_have"));
        red_have->setGeometry(QRect(830, 730, 51, 61));
        red_have->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        black_have = new QTextBrowser(gameInterface);
        black_have->setObjectName(QString::fromUtf8("black_have"));
        black_have->setGeometry(QRect(930, 730, 51, 61));
        black_have->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        label = new QLabel(gameInterface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(390, 710, 91, 81));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/images/bbb.png);\n"
"border-radius:35px;"));
        gold_have = new QTextBrowser(gameInterface);
        gold_have->setObjectName(QString::fromUtf8("gold_have"));
        gold_have->setGeometry(QRect(360, 750, 51, 61));
        gold_have->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        selectBlack = new QPushButton(gameInterface);
        selectBlack->setObjectName(QString::fromUtf8("selectBlack"));
        selectBlack->setGeometry(QRect(1070, 150, 71, 61));
        selectBlack->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"\n"
"\n"
""));
        selectRed = new QPushButton(gameInterface);
        selectRed->setObjectName(QString::fromUtf8("selectRed"));
        selectRed->setGeometry(QRect(1070, 240, 71, 61));
        selectRed->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"\n"
"\n"
""));
        selectGreen = new QPushButton(gameInterface);
        selectGreen->setObjectName(QString::fromUtf8("selectGreen"));
        selectGreen->setGeometry(QRect(1080, 350, 71, 61));
        selectGreen->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"\n"
"\n"
""));
        selectBlue = new QPushButton(gameInterface);
        selectBlue->setObjectName(QString::fromUtf8("selectBlue"));
        selectBlue->setGeometry(QRect(1090, 460, 71, 61));
        selectBlue->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"\n"
"\n"
""));
        selectWhite = new QPushButton(gameInterface);
        selectWhite->setObjectName(QString::fromUtf8("selectWhite"));
        selectWhite->setGeometry(QRect(1110, 580, 71, 61));
        selectWhite->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"\n"
"\n"
""));
        gradePeople2 = new QTextBrowser(gameInterface);
        gradePeople2->setObjectName(QString::fromUtf8("gradePeople2"));
        gradePeople2->setGeometry(QRect(120, 20, 61, 61));
        gradePeople2->setStyleSheet(QString::fromUtf8("background-color:rgba(130, 87, 103,0.8);\n"
"border-radius:20px;\n"
"border:1px solid rgb(197, 197, 98)"));
        gradePeople1 = new QTextBrowser(gameInterface);
        gradePeople1->setObjectName(QString::fromUtf8("gradePeople1"));
        gradePeople1->setGeometry(QRect(130, 620, 61, 61));
        gradePeople1->setStyleSheet(QString::fromUtf8("background-color:rgba(130, 87, 103,0.8);\n"
"border-radius:20px;\n"
"border:1px solid rgb(197, 197, 98)\n"
""));
        re = new QToolButton(gameInterface);
        re->setObjectName(QString::fromUtf8("re"));
        re->setGeometry(QRect(1340, 0, 61, 141));
        re->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border:none;\n"
"border-radius:30px;"));
        changeMan = new QToolButton(gameInterface);
        changeMan->setObjectName(QString::fromUtf8("changeMan"));
        changeMan->setGeometry(QRect(670, 650, 121, 51));
        changeMan->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";\n"
"border-radius:15px;\n"
"background-color: qlineargradient(spread: pad, x1: 0, y1: 0, x2: 0, y2: 1,\\ stop : 0 rgba(255, 255, 255, 200),\\ stop : 0.5 rgba(0, 100, 255, 255),\\ stop : 1 rgba(255, 255, 255, 200));\n"
"color:rgb(255,255,255);"));
        background = new QLabel(gameInterface);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(0, 0, 1400, 800));
        background->setMinimumSize(QSize(1400, 800));
        background->setMaximumSize(QSize(1400, 800));
        background->setStyleSheet(QString::fromUtf8("border-image: url(:/images/background.png);"));
        oppo1 = new QToolButton(gameInterface);
        oppo1->setObjectName(QString::fromUtf8("oppo1"));
        oppo1->setGeometry(QRect(0, 40, 201, 151));
        oppo1->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 254, 0);\n"
"border-top-right-radius:65px;\n"
"border-bottom-right-radius:65px;\n"
""));
        oppo_turn = new QLabel(gameInterface);
        oppo_turn->setObjectName(QString::fromUtf8("oppo_turn"));
        oppo_turn->setGeometry(QRect(0, 632, 227, 171));
        oppo_turn->setStyleSheet(QString::fromUtf8("border-image: url(:/images/oppo_turn.png);\n"
"border-top-right-radius:80px;\n"
"border-bottom-right-radius:80px;\n"
""));
        oppo_turn_2 = new QLabel(gameInterface);
        oppo_turn_2->setObjectName(QString::fromUtf8("oppo_turn_2"));
        oppo_turn_2->setGeometry(QRect(0, 40, 197, 151));
        oppo_turn_2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/myturn.png);\n"
"border-top-right-radius:75px;\n"
"border-bottom-right-radius:75px;"));
        highlight1_1 = new QLabel(gameInterface);
        highlight1_1->setObjectName(QString::fromUtf8("highlight1_1"));
        highlight1_1->setGeometry(QRect(307, 77, 147, 177));
        highlight1_1->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border:5px solid rgb(0, 216, 104)"));
        highlight1_2 = new QLabel(gameInterface);
        highlight1_2->setObjectName(QString::fromUtf8("highlight1_2"));
        highlight1_2->setGeometry(QRect(487, 77, 147, 177));
        highlight1_2->setStyleSheet(QString::fromUtf8("border:5px solid rgb(0, 216, 104);\n"
"border-radius:15px;"));
        highlight1_3 = new QLabel(gameInterface);
        highlight1_3->setObjectName(QString::fromUtf8("highlight1_3"));
        highlight1_3->setGeometry(QRect(667, 77, 147, 177));
        highlight1_3->setStyleSheet(QString::fromUtf8("border:5px solid rgb(0, 216, 104);\n"
"border-radius:15px;"));
        highlight1_4 = new QLabel(gameInterface);
        highlight1_4->setObjectName(QString::fromUtf8("highlight1_4"));
        highlight1_4->setGeometry(QRect(857, 77, 147, 177));
        highlight1_4->setStyleSheet(QString::fromUtf8("border:5px solid rgb(0, 216, 104);\n"
"border-radius:15px;"));
        highlight2_1 = new QLabel(gameInterface);
        highlight2_1->setObjectName(QString::fromUtf8("highlight2_1"));
        highlight2_1->setGeometry(QRect(307, 267, 147, 177));
        highlight2_1->setStyleSheet(QString::fromUtf8("border:5px solid rgb(0, 216, 104);\n"
"border-radius:15px;"));
        highlight2_2 = new QLabel(gameInterface);
        highlight2_2->setObjectName(QString::fromUtf8("highlight2_2"));
        highlight2_2->setGeometry(QRect(487, 267, 147, 177));
        highlight2_2->setStyleSheet(QString::fromUtf8("border:5px solid rgb(0, 216, 104);\n"
"border-radius:15px;"));
        highlight2_3 = new QLabel(gameInterface);
        highlight2_3->setObjectName(QString::fromUtf8("highlight2_3"));
        highlight2_3->setGeometry(QRect(667, 267, 147, 177));
        highlight2_3->setStyleSheet(QString::fromUtf8("border:5px solid rgb(0, 216, 104);\n"
"border-radius:15px;"));
        highlight2_4 = new QLabel(gameInterface);
        highlight2_4->setObjectName(QString::fromUtf8("highlight2_4"));
        highlight2_4->setGeometry(QRect(857, 267, 147, 177));
        highlight2_4->setStyleSheet(QString::fromUtf8("border:5px solid rgb(0, 216, 104);\n"
"border-radius:15px;"));
        highlight3_1 = new QLabel(gameInterface);
        highlight3_1->setObjectName(QString::fromUtf8("highlight3_1"));
        highlight3_1->setGeometry(QRect(307, 467, 147, 177));
        highlight3_1->setStyleSheet(QString::fromUtf8("border:5px solid rgb(0, 216, 104);\n"
"border-radius:15px;\n"
""));
        highlight3_2 = new QLabel(gameInterface);
        highlight3_2->setObjectName(QString::fromUtf8("highlight3_2"));
        highlight3_2->setGeometry(QRect(487, 467, 147, 177));
        highlight3_2->setStyleSheet(QString::fromUtf8("border:5px solid rgb(0, 216, 104);\n"
"border-radius:15px;"));
        highlight3_3 = new QLabel(gameInterface);
        highlight3_3->setObjectName(QString::fromUtf8("highlight3_3"));
        highlight3_3->setGeometry(QRect(667, 467, 147, 177));
        highlight3_3->setStyleSheet(QString::fromUtf8("border:5px solid rgb(0, 216, 104);\n"
"border-radius:15px;"));
        highlight3_4 = new QLabel(gameInterface);
        highlight3_4->setObjectName(QString::fromUtf8("highlight3_4"));
        highlight3_4->setGeometry(QRect(857, 467, 147, 177));
        highlight3_4->setStyleSheet(QString::fromUtf8("border:5px solid rgb(0, 216, 104);\n"
"border-radius:15px;"));
        black_card = new QTextBrowser(gameInterface);
        black_card->setObjectName(QString::fromUtf8("black_card"));
        black_card->setGeometry(QRect(880, 720, 42, 53));
        black_card->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(99, 99, 99, 255), stop:1 rgba(55, 55, 55, 255));\n"
"border-radius:15px;\n"
"border:1px solid white;"));
        blue_card = new QTextBrowser(gameInterface);
        blue_card->setObjectName(QString::fromUtf8("blue_card"));
        blue_card->setGeometry(QRect(591, 720, 42, 53));
        blue_card->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(112, 198, 255, 255), stop:1 rgba(80, 141, 182, 255));\n"
"border:1px solid white;\n"
"border-radius:15px;\n"
""));
        green_card = new QTextBrowser(gameInterface);
        green_card->setObjectName(QString::fromUtf8("green_card"));
        green_card->setGeometry(QRect(688, 720, 42, 53));
        green_card->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(155, 255, 162, 255), stop:1 rgba(0, 213, 0, 255));\n"
"border-radius:15px;\n"
"border:1px solid white;"));
        red_card = new QTextBrowser(gameInterface);
        red_card->setObjectName(QString::fromUtf8("red_card"));
        red_card->setGeometry(QRect(783, 720, 42, 53));
        red_card->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(234, 189, 189, 255), stop:1 rgba(247, 90, 90, 255));\n"
"border-radius:15px;\n"
"border:1px solid white;"));
        white_card = new QTextBrowser(gameInterface);
        white_card->setObjectName(QString::fromUtf8("white_card"));
        white_card->setGeometry(QRect(494, 720, 42, 53));
        white_card->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
"border-radius:15px;\n"
"border:1px solid black;"));
        reserved1 = new QToolButton(gameInterface);
        reserved1->setObjectName(QString::fromUtf8("reserved1"));
        reserved1->setGeometry(QRect(10, 540, 71, 91));
        reserved1->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 80);\n"
"border-radius:18px;\n"
"border:2px solid rgb(176, 176, 87);"));
        reserved2 = new QToolButton(gameInterface);
        reserved2->setObjectName(QString::fromUtf8("reserved2"));
        reserved2->setGeometry(QRect(90, 540, 71, 91));
        reserved2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 80);\n"
"border-radius:18px;\n"
"border:2px solid rgb(176, 176, 87);"));
        reserved3 = new QToolButton(gameInterface);
        reserved3->setObjectName(QString::fromUtf8("reserved3"));
        reserved3->setGeometry(QRect(170, 540, 71, 91));
        reserved3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 80);\n"
"border-radius:18px;\n"
"border:2px solid rgb(176, 176, 87);"));
        noble1 = new QToolButton(gameInterface);
        noble1->setObjectName(QString::fromUtf8("noble1"));
        noble1->setGeometry(QRect(1170, 130, 171, 171));
        noble1->setStyleSheet(QString::fromUtf8("border-image: url(:/images/\350\264\265\346\227\217/1.png);\n"
"border-radius:15px;"));
        noble2 = new QToolButton(gameInterface);
        noble2->setObjectName(QString::fromUtf8("noble2"));
        noble2->setGeometry(QRect(1190, 310, 171, 171));
        noble2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/\350\264\265\346\227\217/2.png);\n"
"border-radius:15px;"));
        noble3 = new QToolButton(gameInterface);
        noble3->setObjectName(QString::fromUtf8("noble3"));
        noble3->setGeometry(QRect(1210, 490, 171, 171));
        noble3->setStyleSheet(QString::fromUtf8("border-image: url(:/images/\350\264\265\346\227\217/3.png);\n"
"border-radius:15px;"));
        highlight4_1 = new QLabel(gameInterface);
        highlight4_1->setObjectName(QString::fromUtf8("highlight4_1"));
        highlight4_1->setGeometry(QRect(8, 538, 75, 95));
        highlight4_1->setStyleSheet(QString::fromUtf8("border:5px solid rgb(0, 216, 104);\n"
"border-radius:18px;"));
        highlight4_2 = new QLabel(gameInterface);
        highlight4_2->setObjectName(QString::fromUtf8("highlight4_2"));
        highlight4_2->setGeometry(QRect(88, 538, 75, 95));
        highlight4_2->setStyleSheet(QString::fromUtf8("border:5px solid rgb(0, 216, 104);\n"
"border-radius:18px;"));
        highlight4_3 = new QLabel(gameInterface);
        highlight4_3->setObjectName(QString::fromUtf8("highlight4_3"));
        highlight4_3->setGeometry(QRect(168, 538, 75, 95));
        highlight4_3->setStyleSheet(QString::fromUtf8("border:5px solid rgb(0, 216, 104);\n"
"border-radius:18px;"));
        yellowLight1_1 = new QLabel(gameInterface);
        yellowLight1_1->setObjectName(QString::fromUtf8("yellowLight1_1"));
        yellowLight1_1->setGeometry(QRect(307, 77, 147, 177));
        yellowLight1_1->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border:5px solid rgb(218, 218, 108)"));
        yellowLight1_2 = new QLabel(gameInterface);
        yellowLight1_2->setObjectName(QString::fromUtf8("yellowLight1_2"));
        yellowLight1_2->setGeometry(QRect(487, 77, 147, 177));
        yellowLight1_2->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border:5px solid rgb(218, 218, 108)"));
        yellowLight1_3 = new QLabel(gameInterface);
        yellowLight1_3->setObjectName(QString::fromUtf8("yellowLight1_3"));
        yellowLight1_3->setGeometry(QRect(667, 77, 147, 177));
        yellowLight1_3->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border:5px solid rgb(218, 218, 108)"));
        yellowLight1_4 = new QLabel(gameInterface);
        yellowLight1_4->setObjectName(QString::fromUtf8("yellowLight1_4"));
        yellowLight1_4->setGeometry(QRect(857, 77, 147, 177));
        yellowLight1_4->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border:5px solid rgb(218, 218, 108)"));
        yellowLight2_1 = new QLabel(gameInterface);
        yellowLight2_1->setObjectName(QString::fromUtf8("yellowLight2_1"));
        yellowLight2_1->setGeometry(QRect(307, 267, 147, 177));
        yellowLight2_1->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border:5px solid rgb(218, 218, 108)"));
        yellowLight2_2 = new QLabel(gameInterface);
        yellowLight2_2->setObjectName(QString::fromUtf8("yellowLight2_2"));
        yellowLight2_2->setGeometry(QRect(487, 267, 147, 177));
        yellowLight2_2->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border:5px solid rgb(218, 218, 108)"));
        yellowLight2_3 = new QLabel(gameInterface);
        yellowLight2_3->setObjectName(QString::fromUtf8("yellowLight2_3"));
        yellowLight2_3->setGeometry(QRect(667, 267, 147, 177));
        yellowLight2_3->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border:5px solid rgb(218, 218, 108)"));
        yellowLight2_4 = new QLabel(gameInterface);
        yellowLight2_4->setObjectName(QString::fromUtf8("yellowLight2_4"));
        yellowLight2_4->setGeometry(QRect(857, 267, 147, 177));
        yellowLight2_4->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border:5px solid rgb(218, 218, 108)"));
        yellowLight3_1 = new QLabel(gameInterface);
        yellowLight3_1->setObjectName(QString::fromUtf8("yellowLight3_1"));
        yellowLight3_1->setGeometry(QRect(307, 467, 147, 177));
        yellowLight3_1->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border:5px solid rgb(218, 218, 108)"));
        yellowLight3_2 = new QLabel(gameInterface);
        yellowLight3_2->setObjectName(QString::fromUtf8("yellowLight3_2"));
        yellowLight3_2->setGeometry(QRect(487, 467, 147, 177));
        yellowLight3_2->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border:5px solid rgb(218, 218, 108)"));
        yellowLight3_3 = new QLabel(gameInterface);
        yellowLight3_3->setObjectName(QString::fromUtf8("yellowLight3_3"));
        yellowLight3_3->setGeometry(QRect(667, 467, 147, 177));
        yellowLight3_3->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border:5px solid rgb(218, 218, 108)"));
        yellowLight3_4 = new QLabel(gameInterface);
        yellowLight3_4->setObjectName(QString::fromUtf8("yellowLight3_4"));
        yellowLight3_4->setGeometry(QRect(857, 467, 147, 177));
        yellowLight3_4->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border:5px solid rgb(218, 218, 108)"));
        yellowLight4_1 = new QLabel(gameInterface);
        yellowLight4_1->setObjectName(QString::fromUtf8("yellowLight4_1"));
        yellowLight4_1->setGeometry(QRect(8, 538, 75, 95));
        yellowLight4_1->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border:5px solid rgb(218, 218, 108)"));
        yellowLight4_2 = new QLabel(gameInterface);
        yellowLight4_2->setObjectName(QString::fromUtf8("yellowLight4_2"));
        yellowLight4_2->setGeometry(QRect(88, 538, 75, 95));
        yellowLight4_2->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border:5px solid rgb(218, 218, 108)"));
        yellowLight4_3 = new QLabel(gameInterface);
        yellowLight4_3->setObjectName(QString::fromUtf8("yellowLight4_3"));
        yellowLight4_3->setGeometry(QRect(168, 538, 75, 95));
        yellowLight4_3->setStyleSheet(QString::fromUtf8("border-radius:15px;\n"
"border:5px solid rgb(218, 218, 108)"));
        name2 = new QLabel(gameInterface);
        name2->setObjectName(QString::fromUtf8("name2"));
        name2->setGeometry(QRect(0, 170, 161, 41));
        name2->setStyleSheet(QString::fromUtf8("background-color:rgba(130, 87, 103,0.8);\n"
"border-radius:15px;\n"
"border:1px solid rgb(197, 197, 98);\n"
"font: 18pt \"\351\232\266\344\271\246\";\n"
"color:white;"));
        name1 = new QLabel(gameInterface);
        name1->setObjectName(QString::fromUtf8("name1"));
        name1->setGeometry(QRect(10, 755, 161, 41));
        name1->setStyleSheet(QString::fromUtf8("background-color:rgba(130, 87, 103,0.8);\n"
"border-radius:15px;\n"
"border:1px solid rgb(197, 197, 98);\n"
"font: 18pt \"\351\232\266\344\271\246\";\n"
"color:white;"));
        musicC = new QToolButton(gameInterface);
        musicC->setObjectName(QString::fromUtf8("musicC"));
        musicC->setGeometry(QRect(1250, 20, 61, 61));
        musicC->setStyleSheet(QString::fromUtf8(""));
        background->raise();
        gold_num->raise();
        black_num->raise();
        red_num->raise();
        green_num->raise();
        blue_num->raise();
        white_num->raise();
        label->raise();
        selectBlack->raise();
        selectRed->raise();
        selectGreen->raise();
        selectBlue->raise();
        selectWhite->raise();
        changeMan->raise();
        money->raise();
        gold_have->raise();
        green_have->raise();
        black_have->raise();
        blue_have->raise();
        white_have->raise();
        red_have->raise();
        re->raise();
        oppo_turn->raise();
        oppo_turn_2->raise();
        oppo1->raise();
        black_card->raise();
        blue_card->raise();
        green_card->raise();
        red_card->raise();
        white_card->raise();
        noble1->raise();
        noble2->raise();
        noble3->raise();
        yellowLight1_1->raise();
        yellowLight1_2->raise();
        yellowLight1_3->raise();
        yellowLight1_4->raise();
        yellowLight2_1->raise();
        yellowLight2_2->raise();
        yellowLight2_3->raise();
        yellowLight2_4->raise();
        yellowLight3_1->raise();
        yellowLight3_2->raise();
        yellowLight3_3->raise();
        yellowLight3_4->raise();
        yellowLight4_1->raise();
        yellowLight4_2->raise();
        yellowLight4_3->raise();
        highlight1_1->raise();
        highlight1_2->raise();
        highlight1_3->raise();
        highlight1_4->raise();
        highlight2_1->raise();
        highlight2_2->raise();
        highlight2_3->raise();
        highlight2_4->raise();
        highlight3_1->raise();
        highlight3_2->raise();
        highlight3_3->raise();
        highlight3_4->raise();
        highlight4_1->raise();
        highlight4_2->raise();
        highlight4_3->raise();
        card1_1->raise();
        card1_2->raise();
        card1_3->raise();
        card2_2->raise();
        card2_3->raise();
        card2_1->raise();
        card1_4->raise();
        card3_1->raise();
        card2_4->raise();
        card3_3->raise();
        card3_4->raise();
        card3_2->raise();
        reserved1->raise();
        reserved2->raise();
        reserved3->raise();
        name2->raise();
        gradePeople2->raise();
        name1->raise();
        gradePeople1->raise();
        musicC->raise();

        retranslateUi(gameInterface);

        QMetaObject::connectSlotsByName(gameInterface);
    } // setupUi

    void retranslateUi(QWidget *gameInterface)
    {
        gameInterface->setWindowTitle(QApplication::translate("gameInterface", "gameInterface", nullptr));
        card1_1->setText(QString());
        card1_2->setText(QString());
        card1_3->setText(QString());
        card1_4->setText(QString());
        card2_1->setText(QString());
        card2_2->setText(QString());
        card2_3->setText(QString());
        card2_4->setText(QString());
        card3_1->setText(QString());
        card3_2->setText(QString());
        card3_3->setText(QString());
        card3_4->setText(QString());
        gold_num->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#ffffff;\">5</span></p></body></html>", nullptr));
        black_num->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#ffffff;\">5</span></p></body></html>", nullptr));
        red_num->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; color:#ffffff;\">5</span></p></body></html>", nullptr));
        green_num->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#ffffff;\">5</span></p></body></html>", nullptr));
        blue_num->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#ffffff;\">5</span></p></body></html>", nullptr));
        white_num->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#ffffff;\">5</span></p></body></html>", nullptr));
        money->setText(QString());
        white_have->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", nullptr));
        blue_have->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", nullptr));
        green_have->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", nullptr));
        red_have->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", nullptr));
        black_have->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", nullptr));
        label->setText(QString());
        gold_have->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", nullptr));
        selectBlack->setText(QString());
        selectRed->setText(QString());
        selectGreen->setText(QString());
        selectBlue->setText(QString());
        selectWhite->setText(QString());
        gradePeople2->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", nullptr));
        gradePeople1->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", nullptr));
        re->setText(QString());
        changeMan->setText(QApplication::translate("gameInterface", "\347\273\223\346\235\237\345\233\236\345\220\210", nullptr));
        background->setText(QString());
        oppo1->setText(QString());
        oppo_turn->setText(QString());
        oppo_turn_2->setText(QString());
        highlight1_1->setText(QString());
        highlight1_2->setText(QString());
        highlight1_3->setText(QString());
        highlight1_4->setText(QString());
        highlight2_1->setText(QString());
        highlight2_2->setText(QString());
        highlight2_3->setText(QString());
        highlight2_4->setText(QString());
        highlight3_1->setText(QString());
        highlight3_2->setText(QString());
        highlight3_3->setText(QString());
        highlight3_4->setText(QString());
        white_card->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        reserved1->setText(QString());
        reserved2->setText(QString());
        reserved3->setText(QString());
        noble1->setText(QString());
        noble2->setText(QString());
        noble3->setText(QString());
        highlight4_1->setText(QString());
        highlight4_2->setText(QString());
        highlight4_3->setText(QString());
        yellowLight1_1->setText(QString());
        yellowLight1_2->setText(QString());
        yellowLight1_3->setText(QString());
        yellowLight1_4->setText(QString());
        yellowLight2_1->setText(QString());
        yellowLight2_2->setText(QString());
        yellowLight2_3->setText(QString());
        yellowLight2_4->setText(QString());
        yellowLight3_1->setText(QString());
        yellowLight3_2->setText(QString());
        yellowLight3_3->setText(QString());
        yellowLight3_4->setText(QString());
        yellowLight4_1->setText(QString());
        yellowLight4_2->setText(QString());
        yellowLight4_3->setText(QString());
        name2->setText(QString());
        name1->setText(QString());
        musicC->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gameInterface: public Ui_gameInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_INTERFACE_H
