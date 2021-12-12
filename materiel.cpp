#include "materiel.h"

using namespace materiel;

std::ostream &operator<<(std::ostream &f, Cout c) {
    f << "Vert:" << c.vert << "Bleu:" << c.bleu << "Noir:" << c.noir << "Rouge:" << c.rouge << "Blanc:" << c.blanc;
    return f;
}

std::ostream &operator<<(std::ostream &f, const carte &c) {
    f << "(" << "ID:" << c.getID() << "," << "Nom:" << c.getNom() << "," << "Cout:" << c.getCout() << ","
      << "ID:Perstige" << c.getPrestige() << ")";
    return f;
}

materiel::Pioche& materiel::Pioche::operator<<(materiel::carte& e) {
    cartes.push_back(&e);
    nbCartes++;
    return *this;
}

materiel::carte* materiel::Pioche::piocher(){
    if (estVide()){
        throw materielException("erreur: impossible de piocher dans une pioche vide");
    }
    auto target = cartes.back();
    cartes.pop_back();
    nbCartes -=1;
    return target;
}

materiel::Jeton* materiel::Pile::retirerJeton(){
    if (estVide()){
        throw materielException("erreur: impossible de retirer un jeton dans une pile vide");
    }
    auto target = jetons.back();
    jetons.pop_back();
    nbJetons -=1;
    return target;
}


void materiel::Pile::ajouterJeton (Jeton * j){
    if (j->getCouleur() != this->getCouleur()){
        throw materielException("erreur: impossible de d'ajouter un jeton dans une pile de couleur différente");
    }
    nbJetons++;
    jetons.push_back(j);
}


materiel::Pile& materiel::Pile::operator<<(materiel::Jeton& e) {
    jetons.push_back(&e);
    nbJetons++;
    return *this;
}
