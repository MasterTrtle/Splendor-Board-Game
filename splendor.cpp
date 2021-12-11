#include "splendor.h"

namespace Splendor {


    Controleur::Controleur() {
        piocheN1 = &Pioche(TypeCarte::N1);
        piocheN2 = &Pioche(TypeCarte::N2);
        piocheN3 = &Pioche(TypeCarte::N3);
    };

}