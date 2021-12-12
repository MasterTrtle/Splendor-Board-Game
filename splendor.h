#pragma once
#ifndef _SPLENDOR_H
#define _SPLENDOR_H

#include <iostream>
#include <string>
#include <initializer_list>
#include <array>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace Splendor {

	// classe pour gerer les exceptions dans le set
	class SetException {
	public:
		SetException(const string& i) :info(i) {}
		string getInfo() const { return info; }
	private:
		string info;
	};




	enum class Couleur { vert, bleu, rouge, blanc, noir, jaune };
	enum class TypeCarte {  N1,N2, N3, Noble };

	// a voir si la classe jeton est utile, ou si on la supprime
	class Jeton {
	private:
		const Couleur couleur;
	public:
		Jeton(const Couleur c) : couleur(c) {}
		Couleur getCouleur() const { return couleur; }
	};

	class Pile {
	private:
		const Couleur couleur;
		unsigned int nombre;
		//const Jetons ** jetons = nullptr;  //on gérer touts les adress de jetons dans un pile ?
	public:
		Pile(const Couleur c, unsigned int n) : couleur(c), nombre(n) {}
		Couleur getCouleur() const { return couleur; }
		unsigned int getNombre() const { return nombre; }
		// Jeton depiler(){};pour prendre une jeton
		//void empile(){}; ; pour ajouter une jeton
	};



	class Prix {

		public:
			Prix(int v, int b, int r, int bl, int n) : vert(v),bleu(b),rouge(r),blanc(bl),noir(n) {};
			int vert;
			int bleu;
			int rouge;
			int blanc;
			int noir;
	};

	class Carte { 
		public:
			
			const unsigned int getID() const { return ID; }
			std::string getNom() const { return Nom; }
			Prix getCout() const { return *prix; }
			TypeCarte getType() const { return type; }
			int getPrestige() const { return prestige; }
			Carte(unsigned int id, std::string nom, Prix* c, int p, TypeCarte t);
			~Carte() { delete prix; };
			Carte(const Carte& c) = default;
			Carte& operator=(const Carte& c) = default;
		private:
			TypeCarte type;
			const unsigned int ID;
			std::string Nom;
			Prix* prix;
			int prestige;
	};
	

	


	ostream& operator<<(ostream& f, const Carte& c);
	class Joueur {

	};
	class Partie {
	public:
		static Partie& getInstance() { if (handler.instance == nullptr) handler.instance = new Partie; return *handler.instance;}
		static void libererInstance() {  delete handler.instance;  handler.instance = nullptr; 
		}
		size_t getNbCartes(TypeCarte t) const;
		const Carte& getCarte(size_t i); // provisoire en attendant d'avoir un iterateur qui ne parcourt que les cartes du type souhaité
		class Iterator {
		public:
			void next() { if (isDone()) throw SetException("Iterateur en fin de sequence"); i++; }
			bool isDone() const { return i == getInstance().nb_cartes; }
			const Carte& currentItem() { if (isDone()) throw SetException("Iterateur en fin de sequence"); return Partie::getInstance().getCarte(i); }
		private:
			size_t i = 0;
			
			friend class Partie;
			Iterator() = default;

		};
		Iterator getIterator() const { return Iterator(); }
	private:	
		const  size_t nb_cartes = 90;
		const  size_t nb_cartesN1 = 40;
		const  size_t nb_cartesN2 = 30;
		const  size_t nb_cartesN3 = 20;
		const Carte* cartes[90];
		//Jeton* jetons[40];
		
		//const Jeton& getJeton(size_t i) { return *jetons[i]; }
		friend class Iterator;
		struct Handler {
			Partie* instance;
			Handler() :instance(nullptr) {  }
			~Handler() { delete instance; } 
		};
		static Handler handler;

		Partie();
		~Partie(); 
		Partie(const Partie&) = delete;
		Partie& operator=(const Partie&) = delete;
	

	};
	class Pioche {
	private:
		size_t nbCartes;
		TypeCarte type_cartes;
		const Carte** cartes = nullptr;

	public:
		Pioche(TypeCarte t);
		~Pioche();
		bool estVide() const { return nbCartes == 0; }

		size_t getNbCartes() const { return nbCartes; }
		const Carte& piocher();
	};
	class Plateau {
	private:

		const Carte** cartesN1;
		const Carte** cartesN2;
		const Carte** cartesN3;
		//const Jeton** jetons = nullptr;
		size_t nbCartesN1 = 0;
		size_t nbCartesN2 = 0;
		size_t nbCartesN3= 0;
		const size_t nbMax = 4;
		


	public:
		Plateau();
		~Plateau();
		void ajouterCarte(const Carte& c);

		void printCarte(ostream& f) const;

		//void retirerCarte(const Carte& c);
		//void ajouterJeton(const Jeton& c);
		//void retirerJeton(const Jeton& c);

		const int getNbCartesN1() { return nbCartesN1; }
		const int getNbCartesN2() { return nbCartesN2; }
		const int getNbCartesN3() { return nbCartesN3; }

	};

	
	

	class Controleur {
		static const int nb_joueurs;
		Pioche* piocheN1;
		Pioche* piocheN2;
		Pioche* piocheN3;
		//Pile* pile;
		
		Plateau plateau;
		//Joueur* joueurs;

	public:
		Controleur();
		Controleur(const Controleur& c) = delete;
		Controleur& operator=(const Controleur& c) = delete;
		~Controleur() { delete piocheN1; delete piocheN2; delete piocheN3; }//delete pile; }

		Pioche& getPiocheN1() { return *piocheN1; }
		Pioche& getPiocheN2() { return *piocheN2; }
		Pioche& getPiocheN3() { return *piocheN3; }
		//Pile& getPile() { return *pile; }
		Plateau& getPlateau() { return plateau; }

		//void getCurrentJoueur();
		//void joueurSuivant();
		//void distribuerJeton();
		void distribuerCarte();
	};

	
	

	#endif
}
