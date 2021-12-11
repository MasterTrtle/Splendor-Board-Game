#include "splendor.h"

namespace Splendor {






	std::ostream& operator<<(std::ostream& f, Cout c) {
		f << "Vert:" << c.vert << "Bleu:" << c.bleu << "Noir:" << c.noir << "Rouge:" << c.rouge << "Blanc:" << c.blanc;
	}
	std::ostream& operator<<(std::ostream& f, const Carte& c) {
		f << "(" << "ID:" << c.getID() << "," << "Nom:" << c.getNom() << "," << "Cout:" << c.getCout() << "," << "ID:Perstige" << c.getPrestige() << ")";
		return f;
	}

	Controleur::Controleur() {
		piocheN1 = &Pioche(TypeCarte::N1);
		piocheN2 = &Pioche(TypeCarte::N2);
		piocheN3 = &Pioche(TypeCarte::N3);
	};

}