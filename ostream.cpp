
#include "splendor.h"
#include <string>
#include <iostream>
using namespace std;
using namespace materiel;
using namespace Splendor;


inline std::ostream& operator<<(std::ostream& f, TypeCarte t) {
    if (t == TypeCarte::N1) f << "N1";
    else if (t == TypeCarte::N2) f << "N2";
    else if (t == TypeCarte::N3) f << "N3";
    else throw SplendorException("Il faut ajouter les autres types de carte  dans l'affichage");
    return f;
}
inline std::ostream& operator<<(std::ostream& f, Couleur c) {
    if (c == Couleur::bleu) f << "bleu";
    else if (c == Couleur::blanc) f << "blanc";
    else if (c == Couleur::vert) f << "vert";
    else if (c == Couleur::rouge) f << "rouge";
    else if (c == Couleur::jaune) f << "joker(jaune)";
    else if (c == Couleur::noir) f << "noir";
    else throw SplendorException("Couleur à ajouter dans l'affichage");
    return f;
}

inline std::ostream& operator<<(std::ostream& f, Prix c) {
    f << "Vert:" << c.vert << "Bleu:" << c.bleu << "Noir:" << c.noir << "Rouge:" << c.rouge << "Blanc:" << c.blanc;
    return f;
}

inline std::ostream& operator<<(std::ostream& f, const materiel::Carte& c) {
    f << "(" << "ID:" << c.getID() << "," << "Nom:" << c.getNom() << "," << "Prix:" << c.getPrix() << ", Bonus:  "<<c.getBonus()<< ", "
        << "Perstige:" << c.getPrestige() << ")";
    return f;
}
inline std::ostream& operator<<(std::ostream& f, const materiel::Jeton& j) {
    f << "(" << "jeton " << j.getCouleur()<< ")";
    return f;
}
