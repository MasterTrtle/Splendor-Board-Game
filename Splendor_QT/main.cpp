#include "splendor.h"
#include "mainwindow.h"
#include "game_interface.h"
#include "game_setting.h"
#include <QApplication>

using namespace Splendor;

int main(int argc, char *argv[]) {
    try {
        QApplication a(argc, argv);
         MainWindow w;
          w.show();
          return a.exec();

    }
    catch (SplendorException& e) {
        std::cout << e.getInfo() << "\n";
    }
//    //Choix du nombre de joueur
//    bool flag = false; // flag qui indique la fin de partie
//    int toursRestant = 5;
//    int nb = -1;
//    cout << "Choisissez un nombre de joueur: \n";
//    while (nb != 2 && nb != 3 && nb != 4) {

//        cin >> nb;
//    }
//    cin.clear();
//    fflush(stdin);
//    //Creation de notre partie
//    Regles r = Regles(nb);

//    //uniquement pour ne pas avoir à écrire r.getControleur(), le controleur est géré par la règle.
//    Controleur& c = r.getControleur();
//    Plateau& p = c.getPlateau();

//    //affichage des cartes de chaque pioche pour debug ( non visible par les joueurs)
//   /*
//    c.getPioche(materiel::TypeCarte::N1).printPioche();
//    c.getPioche(materiel::TypeCarte::N2).printPioche();
//    c.getPioche(materiel::TypeCarte::N3).printPioche();
//    */
//    while (toursRestant>0) {
//        if (flag){
//            toursRestant-=1;
//        }
//        //on distribue les cartes sur le plateau ( si besoin)
//        c.distribuerCarte();

//        //affichage des piles de jetons du plateau
//        cout << "\njetons en jeu sur le plateau";
//        p.getPile(materiel::Couleur::blanc).printPile();
//        p.getPile(materiel::Couleur::bleu).printPile();
//        p.getPile(materiel::Couleur::noir).printPile();
//        p.getPile(materiel::Couleur::jaune).printPile();
//        p.getPile(materiel::Couleur::vert).printPile();
//        p.getPile(materiel::Couleur::rouge).printPile();

//        //affichage des cartes du plateau
//        cout << "\nCartes sur le plateau";
//        p.printCarte();

//        //Affichage des jetons possédés par le joueur
//        cout << "\njetons possédés par le joueur";
//        c.getCurrentJoueur().getPile(materiel::Couleur::blanc).printPile();
//        c.getCurrentJoueur().getPile(materiel::Couleur::bleu).printPile();
//        c.getCurrentJoueur().getPile(materiel::Couleur::noir).printPile();
//        c.getCurrentJoueur().getPile(materiel::Couleur::jaune).printPile();
//        c.getCurrentJoueur().getPile(materiel::Couleur::vert).printPile();
//        c.getCurrentJoueur().getPile(materiel::Couleur::rouge).printPile();
//        //Affichage des cartes achetée par le joueur
//        cout << "\nCartes achetées: ";
//        c.getCurrentJoueur().printCarte(c.getCurrentJoueur().getCarteAchetes());
//        //affichage des cartes réservées par le joueur
//        cout << "\nCartes réservées: ";
//        c.getCurrentJoueur().printCarte(c.getCurrentJoueur().getCarteReserve());
//        cout << "\n" << c.getCurrentJoueur().GetNom() << " à vous de jouer! \n";

//        c.visiteNoble();

//        //on check si joueur est une ia pour on appele l'action correspondante
//        if (c.getCurrentJoueur().isIa()) { cout <<"test"; c.actionIa();}
//        else {while (!c.action());}         //On fait jouer le joueur tant que on action est invalide


//        if (c.getCurrentJoueur().GetPrestige()>=15 && !flag) {
//            flag =true;
//            toursRestant = nb- c.getCurrentJoueur().getJoueurID()-1;
//        }


//        //passage au joueur suivant
//        c.joueursuivant();
//    }
//    system("pause");
//    return 0;
}
