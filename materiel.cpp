#include "materiel.h"
#include <string>
#include <iostream>
#include <splendor>

using namespace materiel;

std::ostream &operator<<(std::ostream &f, Prix c) {
    f << "Vert:" << c.vert << "Bleu:" << c.bleu << "Noir:" << c.noir << "Rouge:" << c.rouge << "Blanc:" << c.blanc;
    return f;
}

std::ostream &operator<<(std::ostream &f, const carte &c) {
    f << "(" << "ID:" << c.getID() << "," << "Nom:" << c.getNom() << "," << "Prix:" << c.getPrix() << ","
      << "ID:Perstige" << c.getPrestige() << ")";
    return f;
}

Pioche &Pioche::operator<<(carte &e) {
    cartes.push_back(&e);
    nbCartes++;
    return *this;
}

carte* Pioche::piocher() {
    if (estVide()) {
        throw materielException("erreur: impossible de piocher dans une pioche vide");
    }
    auto target = cartes.back();
    cartes.pop_back();
    nbCartes -= 1;
    return target;
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


void Pile::ajouterJeton(Jeton *j) {
    if (j->getCouleur() != this->getCouleur()) {
        throw materielException("erreur: impossible de d'ajouter un jeton dans une pile de couleur différente");
    }
    nbJetons++;
    jetons.push_back(j);
}


Pile& Pile::operator<<(materiel::Jeton &e) {
    jetons.push_back(&e);
    nbJetons++;
    return *this;
}


void Pioche::printPioche(ostream &f) const {
    for (size_t i = 0; i < nbCartes; i++) {
         cout <<*cartes[i] << "\n";
    }
}