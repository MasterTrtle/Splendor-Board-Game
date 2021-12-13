#pragma once
#ifndef _SPLENDOR_H
#define _SPLENDOR_H

#include <iostream>
#include <string>
#include <initializer_list>
#include <array>
#include <cstdlib>
#include <ctime>
#include "materiel.h"
#include <set>
#include <vector>

using namespace std;

namespace Splendor {

    // classe pour gerer les exceptions dans le set
    class SplendorException {
    public:
        SplendorException(const string &i) : info(i) {}

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


    ostream &operator<<(ostream &f, const materiel::carte &c);

    class Partie {
    private:
        const size_t nb_cartes = 90;
        const size_t nb_cartesN1 = 40;
        const size_t nb_cartesN2 = 30;
        const size_t nb_cartesN3 = 20;
        const materiel::carte *cartes[90];
        //Jeton* jetons[40];

        //const Jeton& getJeton(size_t i) { return *jetons[i]; }
        friend class Iterator;

        struct Handler {
            Partie *instance;

            Handler() : instance(nullptr) {}

            ~Handler() { delete instance; }
        };

        static Handler handler;

        Partie();

        ~Partie();

        Partie(const Partie &) = delete;

        Partie &operator=(const Partie &) = delete;

    public:
        static Partie &getInstance() {
            if (handler.instance == nullptr) handler.instance = new Partie;
            return *handler.instance;
        }

        static void libererInstance() {
            delete handler.instance;
            handler.instance = nullptr;
        }

        size_t getNbCartes(TypeCarte t) const;

        const materiel::carte &getCarte(
                size_t i); // provisoire en attendant d'avoir un iterateur qui ne parcourt que les cartes du type souhaité
        class Iterator {
        public:
            void next() {
                if (isDone()) throw SplendorException("Iterateur en fin de sequence");
                i++;
            }

            bool isDone() const { return i == getInstance().nb_cartes; }

            const materiel::carte &currentItem() {
                if (isDone()) throw SplendorException("Iterateur en fin de sequence");
                return Partie::getInstance().getCarte(i);
            }

        private:
            size_t i = 0;

            friend class Partie;

            Iterator() = default;

        };

        Iterator getIterator() const { return Iterator(); }
    };


    class Plateau {
    private: // pour debug
        materiel::Pioche cartesN1;
        materiel::Pioche cartesN2;
        materiel::Pioche cartesN3;
        //const Jeton** jetons = nullptr;
        size_t nbCartesN1 = 0;
        size_t nbCartesN2 = 0;
        size_t nbCartesN3 = 0;
        const size_t nbMax = 4;

    public:
        Plateau();

        ~Plateau();

        void ajouterCarte(const materiel::carte &c);

        void printCarte(ostream &f = std::cout) const;

        //void retirerCarte(const Carte& c);
        //void ajouterJeton(const Jeton& c);
        //void retirerJeton(const Jeton& c);

        const int getNbCartesN1() { return nbCartesN1; }

        const int getNbCartesN2() { return nbCartesN2; }

        const int getNbCartesN3() { return nbCartesN3; }

    };

    class Controleur {
        static const int nb_joueurs;
        materiel::Pioche *piocheN1;
        materiel::Pioche *piocheN2;
        materiel::Pioche *piocheN3;
        //Pile* pile;

        Plateau plateau;
        //Joueur* joueurs;

    public:
        Controleur();

        Controleur(const Controleur &c) = delete;

        Controleur &operator=(const Controleur &c) = delete;

        ~Controleur() {
            delete piocheN1;
            delete piocheN2;
            delete piocheN3;
        }//delete pile; }

        materiel::Pioche &getPiocheN1() { return *piocheN1; }

        materiel::Pioche &getPiocheN2() { return *piocheN2; }

        materiel::Pioche &getPiocheN3() { return *piocheN3; }

        //Pile& getPile() { return *pile; }
        Plateau &getPlateau() { return plateau; }

        //void getCurrentJoueur();
        //void joueurSuivant();
        //void distribuerJeton();
        void distribuerCarte();
    };


    class Joueur {
    private:

        const unsigned int ID;
        const std::string Nom;
        std::vector<materiel::carte *> Reserved;
        std::vector<materiel::carte *> Cartes = {};
        std::vector<materiel::Jeton *> Jetons = {};
        int prestige = 0;

        friend class Controleur;

    public:
        ~Joueur() {
            Jetons.clear();
            Cartes.clear();
        };

        // functions pour afficher
        const int getJoueurID() const { return ID; };

        void ShowJetons(); //a voir comment on va gerer les jetons
        void ShowCartes();

        void ShowReserved();

        Couleur GetBonus(); // pour calculer le bonus de joueur
        int GetPrestige() { return prestige; };

        //methods pour joueur
        bool ReserveCartre(materiel::carte c, materiel::Jeton jetons) {};

        bool BuyCarte(materiel::carte *) {};

        bool VisitNobles();

        bool GetJetons(); //prendre des jetons
        bool giveJetons(); // si les jetons depasser 10 on doit rendre les jetons

        //functions set
        void AddPrestige(int i) { prestige = prestige + i; }

        // fonctions de controle




    };


#endif
}
