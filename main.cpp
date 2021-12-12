#include "splendor.h"
using namespace Splendor;

int main() {
	try {
		Controleur c;
		/*
		Plateau* a = new Plateau();
		Carte* c1 = new Carte(2, "la vida", new Prix(2, 3, 4, 1, 1), 5, TypeCarte::N2);
		Carte* c2 = new Carte(2, "la vida", new Prix(2, 3, 4, 1, 1), 5, TypeCarte::N2);
		Carte* c3 = new Carte(2, "la vida", new Prix(2, 3, 4, 1, 1), 5, TypeCarte::N2);
		Carte* c4 = new Carte(2, "la vida", new Prix(2, 3, 4, 1, 1), 5, TypeCarte::N2);
		Carte* c5 = new Carte(2, "la vida", new Prix(2, 3, 4, 1, 1), 5, TypeCarte::N2);
		a->ajouterCarte(*c1);
		a->ajouterCarte(*c2);
		a->ajouterCarte(*c3);
		a->ajouterCarte(*c4);
		*/
		c.distribuerCarte();
		
		c.getPlateau().printCarte();
		c.getPiocheN1().printCarte();
		

	}
	catch (SetException& e) {
		std::cout << e.getInfo() << "\n";
	}
	
	std::cout << "fin programme";
	
	return 0;
}
