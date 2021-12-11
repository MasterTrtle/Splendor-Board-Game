#include "cartes.h"

using namespace cartes;

std::ostream &operator<<(std::ostream &f, Cout c) {
    f << "Vert:" << c.vert << "Bleu:" << c.bleu << "Noir:" << c.noir << "Rouge:" << c.rouge << "Blanc:" << c.blanc;
    return f;
}

std::ostream &operator<<(std::ostream &f, const carte &c) {
    f << "(" << "ID:" << c.getID() << "," << "Nom:" << c.getNom() << "," << "Cout:" << c.getCout() << ","
      << "ID:Perstige" << c.getPrestige() << ")";
    return f;
}

cartes::Pioche& cartes::Pioche::operator<<(cartes::carte& e) {
    cartes.push_back(&e);
    nbCartes++;
    return *this;
}

cartes::carte* cartes::Pioche::piocher(){
    if (estVide()){
        throw cartesException("erreur: impossible de piocher dans une pioche vide");
    }
    auto target = cartes.back();
    cartes.pop_back();
    nbCartes -=1;
    return target;
}
