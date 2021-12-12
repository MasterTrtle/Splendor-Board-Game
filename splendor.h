#pragma once
#ifndef _SPLENDOR_H
#define _SPLENDOR_H

#include <iostream>
#include <string>
#include <initializer_list>
#include <array>
#include <cstdlib>
#include <ctime>
#include "cartes.h"
#include <set>
#include <vector>

using namespace std;

namespace Splendor {

    // classe pour gerer les exceptions dans le set
    class SetException {
    public:
        SetException(const string &i) : info(i) {}

        string getInfo() const { return info; }

    private:
        string info;
    };


    enum class Couleur {
        vert, bleu, rouge, blanc, noir, jaune
    };
    enum class TypeCarte {
        N1, N2, N3, Noble
    };

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
        //const Jetons ** jetons = nullptr;  //on gerer touts les adress de jetons dans un pile ?
    public:
        Pile(const Couleur c, unsigned int n) : couleur(c), nombre(n) {};

        Couleur getCouleur() const { return couleur; }

        unsigned int getNombre() const { return nombre; }
        // Jeton depiler(){};pour prendre une jeton
        //void empile(){}; ; pour ajouter une jeton
    };

    ostream &operator<<(ostream &f, const cartes::carte &c);

    class Partie {
    private:

        static size_t nb_cartes;
        cartes::carte *cartes[90];

        Jeton *jetons[40];

        ~Partie() {
            delete[] cartes;
            delete *jetons;
        }

        Partie(const Partie &) = delete;

        Partie &operator=(const Partie &) = delete;

    public:
        const cartes::carte &getCarte(size_t i) { return *cartes[i]; }

        const Jeton &getJeton(size_t i) { return *jetons[i]; }

        friend class Iterator;

        size_t getNbCartes() const { return nb_cartes; }

        class Iterator {
        public:
            void next() {
                if (isDone()) throw SetException("Iterateur en fin de sequence");
                i++;
            }

            bool isDone() const { return i == nb_cartes; }

            const cartes::carte &currentItem() const {
                if (isDone()) throw SetException("Iterateur en fin de sequence");
                return getCarte(i);
            }

        private:
            size_t i = 0;

            friend class Partie;

            Iterator() = default;

        };

        Iterator getIterator() const { return Iterator(); }

    };

    class Plateau {
    private:

        const cartes::carte **cartesN1 = nullptr;
        const cartes::carte **cartesN2 = nullptr;
        const cartes::carte **cartesN3 = nullptr;
        const Jeton **jetons = nullptr;
        size_t nbCartesN1;
        size_t nbCartesN2;
        size_t nbCartesN3;

    public:
        Plateau();

        ~Plateau() {
            delete[] cartesN1;
            delete[] cartesN2;
            delete[] cartesN3;
        }

        void ajouterCarte(const cartes::carte &c);

        void retirerCarte(const cartes::carte &c);

        void ajouterJeton(const Jeton &c);

        void retirerJeton(const Jeton &c);

        const int getNbCartesN1() { return nbCartesN1; }

        const int getNbCartesN2() { return nbCartesN2; }

        const int getNbCartesN3() { return nbCartesN3; }

    };

    class Controleur {
        static const int nb_joueurs;
        cartes::Pioche *piocheN1 = nullptr;
        cartes::Pioche *piocheN2 = nullptr;
        cartes::Pioche *piocheN3 = nullptr;
        Pile *pile = nullptr;
        Plateau plateau;
        //Joueur* joueurs;

    public:
        Controleur();

        ~Controleur() {
            delete piocheN1;
            delete piocheN2;
            delete piocheN3;
        }

        Controleur(const Controleur &c) = delete;

        Controleur &operator=(const Controleur &c) = delete;

        const cartes::Pioche &getPiocheN1() { return *piocheN1; }

        const cartes::Pioche &getPiocheN2() { return *piocheN2; }

        const cartes::Pioche &getPiocheN3() { return *piocheN3; }

        const Pile &getPile() { return *pile; }

        Plateau &getPlateau() { return plateau; }

        void getCurrentJoueur();

        void joueurSuivant();

        void distribuerJeton();

        void distribuerCarte();
    };


    class Pioche {
    private:
        size_t nbCartes;
        TypeCarte type_cartes;
        const cartes::carte **cartes = nullptr;

    public:
        bool estVide() const { return nbCartes == 0; }

        Pioche(TypeCarte t) : type_cartes(t) {};

        const size_t getNbCartes() { return nbCartes; }

        const cartes::carte &piocher();
    };

		class  Joueur
	{
		friend class Controleur;
	public:
		Joueur(unsigned int id, std::string nom) :ID(id), Nom(nom),prestige(0){
			for (int i = 0; i < 10; i++)
			{
				Jetons[i] = nullptr;
			}
		};
		~Joueur() {
			for (int i = 0; i < 10; i++)
			{
				if (Jetons[i] != nullptr)
				{
					delete Jetons[i];
					Jetons[i] = nullptr;
				}
			}
		};

		// functions pour afficher 
		const int getJoueurID() const{ return ID; };
		void ShowJetons(); //a voir comment on va gerer les jetons
		void ShowCartes();
		void ShowReserved();
		Couleur GetBonus(); // pour calculer le bonus de joueur
		int GetPrestige() { return prestige; };

		//methods pour joueur
		bool ReserveCartre(Carte c, Jeton jetons) {};
		bool BuyCarte(Carte*) {};
		bool VisitNobles(); 
		bool GetJetons(); //prendre des jetons
		bool giveJetons(); // si les jetons depasser 10 on doit rendre les jetons

		//functions set
		void AddPrestige(int i) { prestige = prestige+ i;}

		// fonctions de controle


	private:
		
		const unsigned int ID;
		const std::string Nom;
		std::vector<Carte> Reserved;
		std::vector<Carte> Cartes;
		Jeton* Jetons[10];
		int prestige;

	};


#endif
}
