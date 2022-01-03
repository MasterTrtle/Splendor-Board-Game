#include <QPainter>
#include <QHBoxLayout>
#include "game_interface.h"
#include "ui_game_interface.h"
#include "splendor.h"
#include "vuecarte.h"
#include "materiel.h"

game_interface::game_interface(int nb,QString player1,QString player2,QString player3,QString player4,int AI,QWidget *parent) : //
    QWidget(parent),
    ui(new Ui::game_interface),
    vuecartes(100,nullptr),
    regle(nb)//nb personne pour regle;
{
    ui->setupUi(this);
    AI_switch = AI;
    player1_nom = player1;
    player2_nom = player2;
    player2_nom = player3;
    player4_nom = player4;
    nb_players = nb;
    //couche = new QVBoxLayout;

    setWindowTitle("Splendor!");
    setFixedSize(1400,800);

    ui->name1->setText(player1_nom);
    ui->name2->setText(player1_nom);

    ui->name3->setVisible(false);
    ui->name4->setVisible(false);
    if (nb_players==3){
        ui->name3->setText(player3_nom);
        ui->name3->setVisible(true);
    }
    if (nb_players==4){
        ui->name4->setText(player4_nom);
        ui->name3->setText(player3_nom);
        ui->name3->setVisible(true);
        ui->name3->setVisible(true);
    }


    //Splendor::Regles reg = Splendor::Regles(2);
    //Splendor::Controleur&c = reg.getControleur();

    Splendor::Controleur&c = regle.getControleur();
    Splendor::Plateau&p = c.getPlateau();
    //test
    materiel::Prix *p1 = new materiel::Prix(0,0,0,0,0);
    materiel::Carte c1 = materiel::Carte("s",p1,materiel::Couleur::blanc,3,materiel::TypeCarte::N1);
   // layoutCartes_DEV = new QGridLayout;
    //layoutCartes_DEV->setSpacing(0);
    //layoutCartes_DEV->setHorizontalSpacing(10);
    std::cout << "test game interface "<< endl;
    for(size_t i=0; i<12;i++)  //12 cartes de développement
        vuecartes[i] = new vuecarte(c1,this);

    for(size_t i=0; i<12;i++){
       ui->carte_dev_layout->addWidget(vuecartes[i],i/4,i%4);
        //connect(vuecartes[i],SIGNAL(carteClicked(VueCarte*)),this,SLOT(carteClique(VueCarte*)));
    }

    c.distribuerCarte();
    //c.getPioche(materiel::TypeCarte::N1);
   // c.getPioche(materiel::TypeCarte::N2);
   // c.getPioche(materiel::TypeCarte::N3);


    //layoutCartes_NOBLE =  new QHBoxLayout;
    for(size_t i=13; i<16;i++)  //3 cartes noble
        vuecartes[i] = new vuecarte(c1,this);
    for(size_t i=13; i<16;i++){
        ui->noble_layout->addWidget(vuecartes[i]);
        connect(vuecartes[i],SIGNAL(carteDevClicked(VueCarte*)),this,SLOT(carteDevClique(VueCarte*)));
    }
   // c.getPioche(materiel::TypeCarte::Noble);
   // couche->addLayout(layoutCartes_NOBLE);
   // couche->addLayout(layoutCartes_DEV);
   // setLayout(couche);

    //Splendor::Regles r = Splendor::Regles(nb);

    for(size_t i=16; i<19;i++)  //3 Cartes réservées
        vuecartes[i] = new vuecarte(c1,this);
    for(size_t i=16; i<19;i++){
        ui->Reserve_layout->addWidget(vuecartes[i]);
        connect(vuecartes[i],SIGNAL(carteDevClicked(VueCarte*)),this,SLOT(carteDevClique(VueCarte*)));
    }
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


void carteDevClicked(VueCarte*)
{

}




void game_interface::game_over(bool Flag){
    if(Flag==0){
        QString winner;
        end = new game_end(winner,this);
        end->show();
    }
}


void game_interface::on_gold_num_textChanged()
{
    ui->gold_num->setText(QString::number(regle.getControleur().getPlateau().getPile(materiel::Couleur::blanc).getNombre()));
}


void game_interface::on_black_num_textChanged()
{
    ui->black_num->setText(QString::number(regle.getControleur().getPlateau().getPile(materiel::Couleur::noir).getNombre()));

}


void game_interface::on_red_num_textChanged()
{
   ui->red_num->setText(QString::number(regle.getControleur().getPlateau().getPile(materiel::Couleur::rouge).getNombre()));
}


void game_interface::on_green_num_textChanged()
{
    ui->green_num->setText(QString::number(regle.getControleur().getPlateau().getPile(materiel::Couleur::vert).getNombre()));
}


void game_interface::on_blue_num_textChanged()
{
    ui->blue_num->setText(QString::number(regle.getControleur().getPlateau().getPile(materiel::Couleur::bleu).getNombre()));
}


void game_interface::on_white_num_textChanged()
{
    ui->white_num->setText(QString::number(regle.getControleur().getPlateau().getPile(materiel::Couleur::blanc).getNombre()));
}


void game_interface::textChanged()
{
    void on_gold_num_textChanged();

    void on_black_num_textChanged();

    void on_red_num_textChanged();

    void on_green_num_textChanged();

    void on_blue_num_textChanged();

    void on_white_num_textChanged();
}

void game_interface::player1_textChanged(){

    // Mettre à jour des jetons possédés par le joueur
    ui->gold_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::jaune).getNombre()));
    ui->blue_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::bleu).getNombre()));
    ui->green_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::vert).getNombre()));
    ui->black_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::noir).getNombre()));
    ui->white_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::blanc).getNombre()));

    // Mettre à jour des cartes achetée par le joueur //À résoudre : Problème : affichage des cartes

    //regle.getControleur().getCurrentJoueur().printCarte(regle.getControleur().getCurrentJoueur().getCarteAchetes());

    // Mettre à jour des cartes réservées par le joueur /À résoudre : Problème : affichage des cartes

    //regle.getControleur().printCarte(c.getCurrentJoueur().getCarteReserve());
}

void game_interface::player2_textChanged(){
    // Mettre à jour des jetons possédés par le joueur
    ui->gold_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::jaune).getNombre()));
    ui->blue_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::bleu).getNombre()));
    ui->green_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::vert).getNombre()));
    ui->black_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::noir).getNombre()));
    ui->white_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::blanc).getNombre()));



    //regle.getControleur().getCurrentJoueur().printCarte(regle.getControleur().getCurrentJoueur().getCarteAchetes());


    //regle.getControleur().printCarte(c.getCurrentJoueur().getCarteReserve());
}

void game_interface::player3_textChanged(){
    // Mettre à jour des jetons possédés par le joueur
    ui->gold_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::jaune).getNombre()));
    ui->blue_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::bleu).getNombre()));
    ui->green_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::vert).getNombre()));
    ui->black_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::noir).getNombre()));
    ui->white_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::blanc).getNombre()));



    //regle.getControleur().getCurrentJoueur().printCarte(regle.getControleur().getCurrentJoueur().getCarteAchetes());



    //regle.getControleur().printCarte(c.getCurrentJoueur().getCarteReserve());
}

void game_interface::player4_textChanged(){
    // Mettre à jour des jetons possédés par le joueur
    ui->gold_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::jaune).getNombre()));
    ui->blue_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::bleu).getNombre()));
    ui->green_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::vert).getNombre()));
    ui->black_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::noir).getNombre()));
    ui->white_have->setText(QString::number(regle.getControleur().getCurrentJoueur().getPile(materiel::Couleur::blanc).getNombre()));



    //regle.getControleur().getCurrentJoueur().printCarte(regle.getControleur().getCurrentJoueur().getCarteAchetes());



    //regle.getControleur().printCarte(c.getCurrentJoueur().getCarteReserve());
}

void game_interface::on_Pioche3_clicked()
{


}


void game_interface::on_pioche2_clicked()
{

}


void game_interface::on_Acheter_clicked()
{

}


void game_interface::on_Reserver_clicked()
{

}

