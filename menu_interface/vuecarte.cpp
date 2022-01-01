#include "vuecarte.h"
#include <QPainter>
#include <QString>
#include <QStaticText>


vuecarte::vuecarte(const materiel::Carte& c, QWidget *parent) : QPushButton(parent),carte(&c)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(120,200);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(true);
}

vuecarte::vuecarte(QWidget *parent): QPushButton(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(120,200);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}

void vuecarte::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);

    // rectangle autour de la carte
    pen.setColor(QColor("gray"));
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawRect(QRect(2, 2, width() - 2, height() - 2));



    if (carte==nullptr) { // si la vue de carte n'a pas de carte on affiche un message
        painter.drawText(QRect(15,50,100,60), Qt::AlignCenter, tr("cliquer \n pour \n ajouter \n une carte"));
        return;
    }



    switch (carte->getType()){ //carte type printe
    case materiel::TypeCarte::N1:
        painter.drawText(20, 20, "N1 carte");
        break;
    case materiel::TypeCarte::N2:
        painter.drawText(20, 20, "N2 carte");
        break;
    case materiel::TypeCarte::N3:
        painter.drawText(20, 20, "N3 carte");
        break;
    case materiel::TypeCarte::Noble:
        painter.drawText(20, 20, "Noble carte");
        break;

    }

    switch (carte->getBonus()){ //carte type printe
    case materiel::Couleur::blanc:
        painter.setPen(QPen(Qt::gray, 20, Qt::SolidLine, Qt::RoundCap));
        painter.drawPoint(100,20);
        painter.drawText(20, 140, "3");
        break;
    case materiel::Couleur::noir:
        painter.setPen(QPen(Qt::black, 20, Qt::SolidLine, Qt::RoundCap));
        painter.drawPoint(100,20);
        painter.drawText(20, 140, "3");
        break;
    case materiel::Couleur::vert:
        painter.setPen(QPen(Qt::green, 20, Qt::SolidLine, Qt::RoundCap));
        painter.drawPoint(100,20);
        painter.drawText(20, 140, "3");
        break;
    case materiel::Couleur::rouge:
        painter.setPen(QPen(Qt::red, 20, Qt::SolidLine, Qt::RoundCap));
        painter.drawPoint(100,20);
        painter.drawText(20, 140, "3");
        break;
    case materiel::Couleur::bleu:
        painter.setPen(QPen(Qt::blue, 20, Qt::SolidLine, Qt::RoundCap));
        painter.drawPoint(100,20);
        painter.drawText(20, 140, "3");
        break;
    case materiel::Couleur::jaune:
        break;

    }


//    if(carte->getPrix().getBlanc()!=0){
//        painter.setPen(QPen(Qt::gray, 20, Qt::SolidLine, Qt::RoundCap));
//        painter.drawText(20, 140, "3");
//        painter.drawPoint(20,140);
//    }
//    if(carte->getPrix().getBleu()!=0){
//        painter.setPen(QPen(Qt::blue, 20, Qt::SolidLine, Qt::RoundCap));
//        painter.drawPoint(20,160);
//    }
//    if(carte->getPrix().getNoir()!=0){
//        painter.setPen(QPen(Qt::black, 20, Qt::SolidLine, Qt::RoundCap));
//        painter.drawPoint(40,140);
//    }
//    if(carte->getPrix().getRouge()!=0){
//        painter.setPen(QPen(Qt::red, 20, Qt::SolidLine, Qt::RoundCap));
//        painter.drawPoint(40,160);
//    }
//    if(carte->getPrix().getVert()!=0){
//        painter.setPen(QPen(Qt::green, 20, Qt::SolidLine, Qt::RoundCap));
//        painter.drawPoint(60,140);
//    }



    if (isChecked()) { // si la carte est sélectionnée, on ajoute une croix noire
        pen.setColor(QColor("black"));
        painter.setPen(pen);
        painter.drawLine(QPoint(0,0), QPoint(width(),height()));
        painter.drawLine(QPoint(width(),0), QPoint(0,height()));
    }

}
