
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
    else throw SplendorException("Il faut ajouter les autres types de carte");
    return f;
}

inline std::ostream& operator<<(std::ostream& f, Prix c) {
    f << "Vert:" << c.vert << "Bleu:" << c.bleu << "Noir:" << c.noir << "Rouge:" << c.rouge << "Blanc:" << c.blanc;
    return f;
}

inline std::ostream& operator<<(std::ostream& f, const materiel::Carte& c) {
    f << "(" << "ID:" << c.getID() << "," << "Nom:" << c.getNom() << "," << "Prix:" << c.getPrix() << ","
        << "ID:Perstige" << c.getPrestige() << ")";
    return f;
}
