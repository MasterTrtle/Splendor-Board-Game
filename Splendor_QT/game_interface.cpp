#include <QPainter>
#include <QHBoxLayout>
#include "game_interface.h"
#include "ui_game_interface.h"
#include "splendor.h"
#include "vuecarte.h"
#include "materiel.h"

game_interface::game_interface(int nb, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game_interface),
    vuecartes(12,nullptr)
{
    couche = new QVBoxLayout;
    ui->setupUi(this);
    setWindowTitle("Splendor!");
    setFixedSize(1400,800);
    ui->name1->setText("player1");
    ui->name2->setText("player2");

    //test
    materiel::Prix *p = new materiel::Prix(0,0,0,0,0);
    materiel::Carte c1 = materiel::Carte("s",p,materiel::Couleur::blanc,3,materiel::TypeCarte::N1);
    layoutCartes = new QGridLayout;
    layoutCartes->setSpacing(0);
    layoutCartes->setHorizontalSpacing(10);
    std::cout << "test game interface "<< endl;
    for(size_t i=0; i<12;i++)
        vuecartes[i] = new vuecarte(c1,this);
    for(size_t i=0; i<12;i++){
        layoutCartes->addWidget(vuecartes[i],i/4,i%4);
    }
    couche->addLayout(layoutCartes);
    setLayout(couche);

    //Splendor::Regles r = Splendor::Regles(nb);
}

game_interface::~game_interface()
{
    delete ui;
}

void game_interface::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("../menu_interface/image/background.png");
    painter.drawPixmap(0, 0, 1400, 800, pix);
}


