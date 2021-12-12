#include "splendor.h"

namespace Splendor {
    void Joueur::ShowJetons(){//todo
		for (int i = 0; i < 10; i++)
		{
			
		}
	}

	void Joueur::ShowCartes() {
		for (vector<Carte>::iterator i = Cartes.begin(); i != Cartes.end(); i++)
			cout << *i << endl; 
	};

	void Joueur::ShowReserved() {
		for (vector<Carte>::iterator i = Reserved.begin(); i != Reserved.end(); i++)
			cout << *i << endl;
	};

	Couleur Joueur::GetBonus() { //todo
		}


    Controleur::Controleur() {
        piocheN1 = &Pioche(TypeCarte::N1);
        piocheN2 = &Pioche(TypeCarte::N2);
        piocheN3 = &Pioche(TypeCarte::N3);
    };

}
