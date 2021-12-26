#include "splendor.h"
#include "ostream.cpp"
using namespace std;
using namespace materiel;
namespace Splendor {

    Partie::Handler Partie::handler = Handler();




    size_t Partie::getNbCartes(TypeCarte t) const {
        if (t == TypeCarte::N1) return nb_cartesN1;
        if (t == TypeCarte::N2) return nb_cartesN2;
        if (t == TypeCarte::N3) return nb_cartesN3;
        else return 0;
    }

      materiel::Carte& Partie::getCarte(size_t i) {
        return *cartes[i];
    }
    Partie::Partie() { // Plus tard construire à partir de données de stockage externe.
        cout << "Constructeur de Partie, generation des cartes de la partie: plutard à importer depuis un fichier json (par exemple) \n ";
        unsigned int i = 0;

        for (i; i < nb_cartesN1; i++) {

            cartes[i] = new materiel::Carte("la muerta", new materiel::Prix(1, 1, 1, 1, 1), materiel::Couleur::bleu, 2, TypeCarte::N1);
            cout << *cartes[i] << "\n";
        }
        for (i; i < nb_cartesN1 + nb_cartesN2; i++) {

            cartes[i] = new materiel::Carte("la vida", new materiel::Prix(2, 3, 4, 1, 1), materiel::Couleur::bleu, 5, TypeCarte::N2);

            cout << *cartes[i] << "\n";
        }
        for (i; i < nb_cartesN1 + nb_cartesN2 + nb_cartesN3; i++) {

            cartes[i] = new materiel::Carte("poco loco", new materiel::Prix(1, 3, 5, 1, 1), materiel::Couleur::bleu, 7, TypeCarte::N3);
            cout << *cartes[i] << "\n";
        }

        cout << "\n" << " --- fin constructeur de partie et de la génération des cartes --- " << "\n";
    }
    Partie::~Partie() {
        for (size_t i = 0; i < nb_cartes; i++) {

            delete cartes[i];

        }

    }

    Plateau::Plateau() : cartesN1(new const materiel::Carte* [4]), cartesN2(new const materiel::Carte* [4]),
        cartesN3(new const materiel::Carte* [4]) {}

    Plateau::~Plateau() {
        delete[] cartesN1;
        delete[] cartesN2;
        delete[] cartesN3;
    }

    Controleur::Controleur() {

        piocheN1 = new materiel::Pioche(materiel::TypeCarte::N1);
        piocheN2 = new materiel::Pioche(materiel::TypeCarte::N2);
        piocheN3 = new materiel::Pioche(materiel::TypeCarte::N3);
    };

    void Plateau::ajouterCarte( const materiel::Carte& c) {

        if (c.materiel::Carte::getType() == TypeCarte::N1) {
            if (nbCartesN1 < nbMax) {

                cartesN1[nbCartesN1] = &c;
                nbCartesN1++;
            }
            else throw SplendorException("trop de cartes sur le plateau N1 pour piocher");
        }
        else if (c.getType() == TypeCarte::N2) {

            if (nbCartesN2 < nbMax) {
                cartesN2[nbCartesN2] = &c;

                nbCartesN2++;
            }
            else throw SplendorException("trop de cartes sur le plateau N2 pour piocher");
        }
        else if (c.getType() == TypeCarte::N3) {
            if (nbCartesN3 < nbMax) {

                cartesN3[nbCartesN3] = &c;
                nbCartesN3++;
            }
            else throw SplendorException("trop de cartes sur le plateau N3 pour piocher");
        }


    }

    void Controleur::distribuerCarte() {
        cout<<" \n \n--Debut de la distribution--";
        
        if (plateau.getNbCartesN1() < 4 || plateau.getNbCartesN2() < 4 || plateau.getNbCartesN3() < 4) {

            
            while (!piocheN1->estVide() && plateau.getNbCartesN1() < 4) {
                plateau.ajouterCarte(piocheN1->piocher());
               

            }
            while (!piocheN2->estVide() && plateau.getNbCartesN2() < 4) {

                plateau.ajouterCarte(piocheN2->piocher());

            }
            while (!piocheN3->estVide() && plateau.getNbCartesN3() < 4) {
                plateau.ajouterCarte(piocheN3->piocher());

            }

            cout << "--fin distribution--";

        }
        else
            throw SplendorException("Impossible de distribuer des cartes, le plateau est plein");

    }

    void Plateau::printCarte(ostream& f) const {
        f << " \n Plateau::printcarte(), Cartes presentes sur le plateau: \n";
        f << "Cartes  N1: \n";
        for (size_t i = 0; i < nbCartesN1; i++) {
            f << *cartesN1[i] << "\n ";
            
        }
        f << "\n ";
        f << "Cartes  N2: \n";
        for (size_t i = 0; i < nbCartesN2; i++) {
            f << *cartesN2[i] << "\n ";
        }
        f << "\n";
        f << "Cartes  N3: \n";
        for (size_t i = 0; i < nbCartesN3; i++) {
            f << *cartesN3[i] << " \n";
        }
        f << "fin de Plateau::printcarte()";
        f << "\n";


    }
   

}
