#include "splendor.h"
using namespace std;
namespace Splendor {



	Partie::Handler Partie::handler = Handler();


	std::ostream& operator<<(std::ostream& f, Prix c) {
		f << "Vert:" << c.vert << "Bleu:" << c.bleu << "Noir:" << c.noir << "Rouge:" << c.rouge << "Blanc:" << c.blanc;
		return f;
		
	}
	
	std::ostream& operator<<(std::ostream& f, TypeCarte t) {
		if (t == TypeCarte::N1) f << "N1";
		else if (t == TypeCarte::N2) f << "N2";
		else if (t == TypeCarte::N3) f << "N3";
		else cout << "erreur";
		return f;

	}
	


	std::ostream& operator<<(std::ostream& f, const Carte& c) {
		f << "(" << "ID:" << c.getID() << "," << "Nom:" << c.getNom() << "," << c.getCout() << "A ajouter" << "," << "ID:Perstige" << c.getPrestige() << "type: " << c.getType();
		return f;
	}
	Carte::Carte(unsigned int id, std::string nom, Prix* c, int p, TypeCarte t) :ID(id), Nom(nom), prestige(p), type(t), prix(c) {};
	
	size_t Partie::getNbCartes(TypeCarte t ) const 
	{ 
		if (t == TypeCarte::N1) return nb_cartesN1;
		if (t == TypeCarte::N2) return nb_cartesN2;
		if (t == TypeCarte::N3) return nb_cartesN3;
	}
	const Carte& Partie::getCarte(size_t i) { 
		return *cartes[i]; 
	}

	
	Pioche::Pioche(TypeCarte t) : type_cartes(t), cartes(new const Carte* [Partie::getInstance().getNbCartes(t)]), nbCartes(Partie::getInstance().getNbCartes(t))
	{
		cout << "Debut de la génération de la pioche: " << t<< ": \n";
		size_t fin = 1;
		size_t debut = 0;
		if (t == TypeCarte::N1) {
			debut = 0;
			fin = 40;
		}
		else if (t == TypeCarte::N2) {
			debut = 40;
			fin = 70;
		}
		else if (t == TypeCarte::N3) {
			debut = 70;
			fin = 90;
			

		}
		size_t i = 0;
		for (debut; debut < fin; debut++) {
			
			cartes[i] = &Partie::getInstance().getCarte(debut);
			cout << *cartes[i] << " " << debut;
			cout << "\n";
			i++;
		}

	}
	Pioche::~Pioche() {
		/*
		cout << "\n pioche type: " << type_cartes << "\n";
		for (size_t i = 0; i < nbCartes; i++) {
			cout << "suppresion pioche" << i;
			cout << "carte cout: " << *cartes[i] << cartes[i];
			delete cartes[i];
			cout << "fin suppresion pioche" << i << "\n";
		}
		*/
		delete[] cartes;


	}
	void Pioche::printCarte(ostream& f ) const {
		cout << "affichage de la pioche " << type_cartes << ": ";
		for (size_t i = 0; i < nbCartes; i++) {
			cout << *cartes[i] << "\n";
		}
	}
	const Carte& Pioche::piocher() {
		
		
		if (nbCartes == 0) throw SetException("Pioche vide");
		size_t x = rand() % nbCartes;
		
		const Carte* c = cartes[x];
		
		for (size_t i = x + 1; i < nbCartes; i++) cartes[i - 1] = cartes[i];
		nbCartes--;
		
		return *c;

	}
	Partie::~Partie() {
		for (size_t i = 0; i < nb_cartes; i ++) {
			
			delete cartes[i];
			
		}
		
	}
	Partie::Partie() {
		cout << "generation des cartes de la partie: \n ";
		unsigned int i = 0;
		
		
		for (i; i < nb_cartesN1; i++) {

			cartes[i] = new Carte(i, "la muerta", new Prix(1, 1, 1, 1, 1), 2, TypeCarte::N1);
			cout << *cartes[i] << "\n";
		}
		for (i; i < nb_cartesN1+ nb_cartesN2; i++) {

			cartes[i] = new Carte(i, "la vida", new Prix(2, 3, 4, 1, 1), 5, TypeCarte::N2);
			
			cout << *cartes[i] << "\n";
		}
		for (i; i < nb_cartesN1 + nb_cartesN2 + nb_cartesN3; i++) {

			cartes[i] = new Carte(i, "poco loco", new Prix(1, 3, 5, 1, 1), 7, TypeCarte::N3);
			cout << *cartes[i] << "\n";
		}
		
		cout<< "\n" <<" --- fin de la génération des cartes --- "<< "\n";
	}
	
	Plateau::Plateau():cartesN1(new const Carte*[4]), cartesN2(new const Carte* [4]), cartesN3(new const Carte* [4]) {} // nbMAx -> 4 pour fixer le pb du memoire
	Plateau::~Plateau() {
		/*
		for (size_t i = 0; i < nbMax; i++) {
			cout << "suppression: " << i;
			delete cartesN1[i];
			cout << "fin suppression: " << i << "\n";
		}
		for (size_t i = 0; i < nbMax; i++) {
			cout << "suppression: " << i;
			delete cartesN2[i];
			cout << "fin suppression: " << i << "\n";
		}
		for (size_t i = 0; i < nbMax; i++) {
			cout << "suppression: " << i;
			delete cartesN3[i];
			cout << "fin suppression: " << i << "\n";
		}
		 */
		delete[] cartesN1;
		delete[] cartesN2;
		delete[] cartesN3;
	}
	Controleur::Controleur() {

		piocheN1 = new Pioche(TypeCarte::N1);
		piocheN2 = new Pioche(TypeCarte::N2);
		piocheN3 = new Pioche(TypeCarte::N3);
	};
	void Plateau::ajouterCarte(const Carte& c) {
		
		if (c.getType() == TypeCarte::N1) {
			if (nbCartesN1 < nbMax) {
			
				cartesN1[nbCartesN1] = &c;
				nbCartesN1++;
			}
			else throw  SetException("trop de cartes sur le plateau N1 pour piocher");
		}
		
		else if (c.getType() == TypeCarte::N2) {
			
			if (nbCartesN2 < nbMax) {			
				cartesN2[nbCartesN2] = &c;
				
				nbCartesN2++;
			}
		
			else throw  SetException("trop de cartes sur le plateau N2 pour piocher");
		}
		else if (c.getType() == TypeCarte::N3) {
			if (nbCartesN3 < nbMax) {
				
				cartesN3[nbCartesN3] = &c;
				nbCartesN3++;
				}
			else throw SetException("trop de cartes sur le plateau N3 pour piocher");
		}
		

	}
	void Controleur::distribuerCarte() {
		
		if (plateau.getNbCartesN1() < 4 || plateau.getNbCartesN2() < 4 || plateau.getNbCartesN3() < 4) {
			plateau.ajouterCarte(piocheN1->piocher());
			/*
			while (!piocheN1->estVide() && plateau.getNbCartesN1() < 4) {
				plateau.ajouterCarte(piocheN1->piocher());
				
			}
			while (!piocheN2->estVide() && plateau.getNbCartesN2() < 4) {
				
				plateau.ajouterCarte(piocheN2->piocher());
				
			}
			while (!piocheN3->estVide() && plateau.getNbCartesN3() < 4) {
				plateau.ajouterCarte(piocheN3->piocher());
				
			}
			
			cout << "fin distribution";
			*/
		}
		else
			throw SetException("Impossible de distribuer des cartes, le plateau est plein");
			
	}
	
	void Plateau::printCarte(ostream& f ) const  {
		f << " \n Cartes presentes sur le plateau: \n";
		f<< "Cartes  N1: \n";
		for (size_t i = 0; i < nbCartesN1; i++) {
			f << *cartesN1[i] << "\n ";
		}
		f << "\n ";
		f << "Cartes  N2: \n";
		for (size_t i = 0; i < nbCartesN2; i++) {
			f << *cartesN2[i] << "\n ";
		}
		f << "\n";
		f << "Cartes  N3: \n";
		for (size_t i = 0; i < nbCartesN3; i++) {
			f << *cartesN3[i] << " \n";
		}
		f << "\n";
		

	}
}
