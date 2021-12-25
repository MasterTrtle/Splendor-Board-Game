#pragma once
#include "materiel.h"
#include <string>
#include <iostream>
#include "ostream.cpp"
//#include <splendor>

using namespace materiel;

//initialisation dans le cpp de la variable statique
int Carte::current_id = 0;



Pioche& Pioche::operator<<(materiel::Carte& e) {
    cartes.push_back(&e);
    nbCartes++;
    return *this;
}
Pioche::Pioche(TypeCarte t) : type_cartes(t),  nbCartes(Partie::getInstance().getNbCartes(t))
{
    cout << "Constructeur pioche: Debut de la génération de la pioche: " << t << ": \n";
    
    //iterator qui ne parcourt que les cartes du type demandé
    
    for (Partie::Iterator it = Partie::getInstance().getIterator(t); !it.isDone(); it.next()) {
        cartes.push_back(&it.currentItem());
        cout << it.currentItem();
        cout << "\n";

    }
    
    cout << "Fin constructeur de la pioche: " << t << "\n";

}


const Carte& Pioche::piocher() {
    if (estVide()) {
        throw materielException("erreur: impossible de piocher dans une pioche vide");
    }
    auto target = cartes.back();
    cartes.pop_back();
    nbCartes -= 1;
    return *target;
}

Jeton* Pile::retirerJeton() {
    if (estVide()) {
        throw materielException("erreur: impossible de retirer un jeton dans une pile vide");
    }
    auto target = jetons.back();
    jetons.pop_back();
    nbJetons -= 1;
    return target;
}


void Pile::ajouterJeton(Jeton* j) {
    if (j->getCouleur() != this->getCouleur()) {
        throw materielException("erreur: impossible de d'ajouter un jeton dans une pile de couleur différente");
    }
    nbJetons++;
    jetons.push_back(j);
}


Pile& Pile::operator<<(materiel::Jeton& e) {
    jetons.push_back(&e);
    nbJetons++;
    return *this;
}


void Pioche::printPioche(ostream& f) const {
    cout << " \n Pioche::printPioche, Affichage des cartes de la pioche N1 \n";
    for (size_t i = 0; i < nbCartes; i++) {
        f << *cartes[i] << "\n";
    }
    cout << "\n fin Pioche::printPioche() \n";
}
