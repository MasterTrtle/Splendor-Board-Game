#include "splendor.h"

using namespace Splendor;

int main() {
    try {

    }
    catch (SplendorException& e) {
        std::cout << e.getInfo() << "\n";
    }
    //Choix du nombre de joueur
    bool flag = false; // flag qui indique la fin de partie
    int toursRestant = 5;
    int extension = -1;
    cout << "Voulez vous activer l'extension: 0 oui, 1 non \n";
    while (extension != 0 && extension != 1 ) {

        cin >> extension;
    }
    int nb = -1;
    cout << "Choisissez un nombre de joueur: \n";
    while (nb != 2 && nb != 3 && nb != 4) {

        cin >> nb;
    }
    cin.clear();
    fflush(stdin);
    bool extBool;
    //Creation de notre partie 
    if (extension == 0)
        extBool = true;
    else extBool = false;
       
    Regles r = Regles(nb, extBool);

    //uniquement pour ne pas avoir à écrire r.getControleur(), le controleur est géré par la règle.
    Controleur& c = r.getControleur();
    Plateau& p = c.getPlateau();

    //affichage des cartes de chaque pioche pour debug ( non visible par les joueurs)
   /*
    c.getPioche(materiel::TypeCarte::N1).printPioche();
    c.getPioche(materiel::TypeCarte::N2).printPioche();
    c.getPioche(materiel::TypeCarte::N3).printPioche();
    */
    while (toursRestant > 0) {
        if (flag) {
            toursRestant -= 1;
        }
        //on distribue les cartes sur le plateau ( si besoin)
        c.distribuerCarte();

        //affichage des piles de jetons du plateau
        cout << "\njetons en jeu sur le plateau";
        p.getPile(materiel::Couleur::blanc).printPile();
        p.getPile(materiel::Couleur::bleu).printPile();
        p.getPile(materiel::Couleur::noir).printPile();
        p.getPile(materiel::Couleur::jaune).printPile();
        p.getPile(materiel::Couleur::vert).printPile();
        p.getPile(materiel::Couleur::rouge).printPile();

        //affichage des cartes du plateau
        cout << "\nCartes sur le plateau";
        p.printCarte();

        //Affichage des jetons possédés par le joueur
        cout << "\njetons possédés par le joueur";
        c.getCurrentJoueur().getPile(materiel::Couleur::blanc).printPile();
        c.getCurrentJoueur().getPile(materiel::Couleur::bleu).printPile();
        c.getCurrentJoueur().getPile(materiel::Couleur::noir).printPile();
        c.getCurrentJoueur().getPile(materiel::Couleur::jaune).printPile();
        c.getCurrentJoueur().getPile(materiel::Couleur::vert).printPile();
        c.getCurrentJoueur().getPile(materiel::Couleur::rouge).printPile();
        //Affichage des cartes achetée par le joueur
        cout << "\nCartes achetées: ";
        c.getCurrentJoueur().printCarte(c.getCurrentJoueur().getCarteAchetes());
        //affichage des cartes réservées par le joueur
        cout << "\nCartes réservées: ";
        c.getCurrentJoueur().printCarte(c.getCurrentJoueur().getCarteReserve());
        cout << "\n" << c.getCurrentJoueur().GetNom() << " à vous de jouer! \n";

       

         while (!c.action());         //On fait jouer le joueur tant que on action est invalide
        c.visiteNoble();
        cout<< "\nPrestige du joueur: "<< c.getCurrentJoueur().GetPrestige();
        cout << "\n appuyez sur une touche pour passer au joueur suivant";
        system("pause");
        if (c.getCurrentJoueur().GetPrestige() >= 15 && !flag) {
            flag = true;
            toursRestant = nb - c.getCurrentJoueur().getJoueurID() - 1;
        }


        //passage au joueur suivant
        c.joueursuivant();
    }
    
    return 0;
}
