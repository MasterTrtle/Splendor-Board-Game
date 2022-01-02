#include "vuecarte.h"
#include "materiel.h"
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


    QPainter painter2 (this);
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
        pen.setColor(QColor("gray")); brush.setColor(QColor("gray")); break;
        //painter.setPen(QPen(Qt::gray, 20, Qt::SolidLine, Qt::RoundCap));
        //painter.drawPoint(100,20);
        //painter.drawText(20, 140, "3");
        break;
    case materiel::Couleur::noir:
        pen.setColor(QColor("black")); brush.setColor(QColor("black")); break;
//        painter.setPen(QPen(Qt::black, 20, Qt::SolidLine, Qt::RoundCap));
//        painter.drawPoint(100,20);
//        painter.drawText(20, 140, "3");
        break;
    case materiel::Couleur::vert:
        pen.setColor(QColor("dark green")); brush.setColor(QColor("dark green")); break;
//        painter.setPen(QPen(Qt::green, 20, Qt::SolidLine, Qt::RoundCap));
//        painter.drawPoint(100,20);
//        painter.drawText(20, 140, "3");
        break;
    case materiel::Couleur::rouge:
        pen.setColor(QColor("red")); brush.setColor(QColor("red")); break;
//        painter.setPen(QPen(Qt::red, 20, Qt::SolidLine, Qt::RoundCap));
//        painter.drawPoint(100,20);
//        painter.drawText(20, 140, "3");
        break;
    case materiel::Couleur::bleu:
        pen.setColor(QColor("blue")); brush.setColor(QColor("blue")); break;
//        painter.setPen(QPen(Qt::blue, 20, Qt::SolidLine, Qt::RoundCap));
//        painter.drawPoint(100,20);
//        painter.drawText(20, 140, "3");
        break;
    case materiel::Couleur::jaune:
        break;

    }
    brush.setStyle(Qt::SolidPattern);
    pen.setWidth(2);
    painter2.setPen(pen);
    painter2.setBrush(brush);
    painter2.drawEllipse(QPoint(100,20),15,15);

    QPainter painter3(this);

    if(carte->getPrix().blanc!=0){
        painter3.setPen(QPen(Qt::gray, 20, Qt::SolidLine, Qt::RoundCap));
        painter3.drawText(20, 140, "3");
        painter3.drawPoint(20,140);
    }
    if(carte->getPrix().bleu!=0){
        painter3.setPen(QPen(Qt::blue, 20, Qt::SolidLine, Qt::RoundCap));
       painter3.drawPoint(20,160);
    }
    if(carte->getPrix().noir!=0){
        painter3.setPen(QPen(Qt::black, 20, Qt::SolidLine, Qt::RoundCap));
        painter3.drawPoint(40,140);
    }
   if(carte->getPrix().rouge!=0){
        painter3.setPen(QPen(Qt::red, 20, Qt::SolidLine, Qt::RoundCap));
        painter3.drawPoint(40,160);
    }
    if(carte->getPrix().vert!=0){
        painter3.setPen(QPen(Qt::green, 20, Qt::SolidLine, Qt::RoundCap));
        painter3.drawPoint(60,140);
    }



    if (isChecked()) { // si la carte est sélectionnée, on ajoute une croix noire
//        pen.setColor(QColor("black"));
//        painter.setPen(pen);
//        painter.drawLine(QPoint(0,0), QPoint(width(),height()));
//        painter.drawLine(QPoint(width(),0), QPoint(0,height()));
    }

}
