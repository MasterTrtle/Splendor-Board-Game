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
		Pile(const couleur c, unsigned int n) : couleur(c), nombre(n) {}
		Couleur getCouleur() const { return couleur; }
		unsigned int getNombre() const { return nombre; }
		// Jeton depiler(){};pour prendre une jeton
		//void empile(){}; ; pour ajouter une jeton
	};



	class Cout {
		public:
			int vert;
			int bleu;
			int rouge;
			int blanc;
			int noir;
	};

	class Carte {
		public:
			TypeCarte type;
			const unsigned int getID() const { return ID; }
			std::string getNom() const { return Nom; }
			Cout getCout() const { return cout; }
			int getPrestige() const { return prestige; }
			~Carte() = default;
			Carte(const Carte& c) = default;
			Carte& operator=(const Carte& c) = default;
		private:
			Carte(std::string id, std::string nom, Cout c, int p, TypeCarte t) :ID(id), Nom(nom), cout(c), prestige(p),type(t) {}
			const unsigned int ID;
			std::string Nom;
			Cout cout;
			int prestige;
	};





	ostream& operator<<(ostream& f, const Carte& c);

	class Partie {
	private:
		
		static size_t nb_cartes;
		Carte* cartes[90];
		
		Jeton* jetons[40];
		~Partie() { delete[] cartes; delete* jetons; }
		Partie(const Partie&) = delete;
		Partie& operator=(const Partie&) = delete;
	
		const Carte& getCarte(size_t i) { return *cartes[i]; }
		const Jeton& getJeton(size_t i) { return *jetons[i]; }
		friend class Iterator;
	public:
		
		size_t getNbCartes() const { return nb_cartes; }
		class Iterator {
		public:
			void next() { if (isDone()) throw SetException("Iterateur en fin de sequence"); i++; }
			bool isDone() const { return i == nb_cartes; }
			const Carte& currentItem() const { if (isDone()) throw SetException("Iterateur en fin de sequence"); return getCarte(i); }
		private:
			size_t i = 0;
			friend class Partie;
			Iterator() = default;
			 
		};
	
		Iterator getIterator() const { return Iterator(); }

	};

	class Controleur {
		static const int nb_joueurs;
		Pioche* piocheN1 = nullptr;
		Pioche* piocheN2 = nullptr;
		Pioche* piocheN3 = nullptr;
		Pile* pile = nullptr;
		Plateau plateau;
		Joueur* joueurs;

	public:
		Controleur();
		~Controleur() { delete piocheN1; delete piocheN2; delete piocheN3; }
		Controleur(const Controleur& c) = delete;
		Controleur& operator=(const Controleur& c) = delete;
		const Pioche& getPiocheN1() { return *piocheN1; }
		const Pioche& getPiocheN1() { return *piocheN2; }
		const Pioche& getPiocheN1() { return *piocheN3; }
		const Pile& getPile() { return *pile; }
		Plateau& getPlateau() { return plateau; }

		void getCurrentJoueur();
		void joueurSuivant();
		void distribuerJeton();
		void distribuerCarte();
	};

	class Plateau {
	private:
		
		const Carte** cartesN1 = nullptr;
		const Carte** cartesN2 = nullptr;
		const Carte** cartesN3 = nullptr;
		const Jeton** jetons = nullptr;
		size_t nbCartesN1;
		size_t nbCartesN2;
		size_t nbCartesN3;

	public:
		Plateau();
		~Plateau() { delete[] cartesN1; delete[] cartesN2; delete[] cartesN3; }
		void ajouterCarte(const Carte& c);
		void retirerCarte(const Carte& c);
		void ajouterJeton(const Jeton& c);
		void retirerJeton(const Jeton& c);

		const int getNbCartesN1() { return nbCartesN1; }
		const int getNbCartesN2() { return nbCartesN2; }
		const int getNbCartesN3() { return nbCartesN3; }
		
	};

	class Pioche {
	private:
		size_t nbCartes;
		TypeCarte type_cartes;
		const Carte** cartes = nullptr;
	
	public:
		bool estVide() const { return nbCartes == 0; }
		Pioche(TypeCarte t) : type_cartes(t) {};
		const size_t getNbCartes() { return nbCartes; }
		const Carte& piocher();
	};

	#endif
}