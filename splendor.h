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
#include <stack>
#include <fstream>
#include "json.hpp"

// for convenience
using json = nlohmann::json;

using namespace std;
using namespace materiel;

namespace Splendor {

    // classe pour gerer les exceptions dans le jeu
    class SplendorException {
    public:
        SplendorException(const string& i) : info(i) {}

        string getInfo() const { return info; }

    private:
        string info;
    };




    class Partie {
    private:

        const size_t nb_cartes = 106;
        const size_t nb_cartesN1 = 40;
        const size_t nb_cartesN2 = 30;
        const size_t nb_cartesN3 = 20;
        const size_t nb_cartesNoble = 10;
        const size_t nb_cartesCite = 6;
        const size_t nb_jetons = 40;
        materiel::Carte* cartes[106];
        materiel::Jeton* jetons[40];
        //Jeton* jetons[40];

        //const Jeton& getJeton(size_t i) { return *jetons[i]; }
        friend class Iterator;

        struct Handler {
            Partie* instance;

            Handler() : instance(nullptr) {}

            ~Handler() { delete instance; }
        };

        static Handler handler;

        Partie();

        ~Partie();

        Partie(const Partie&) = delete;

        Partie& operator=(const Partie&) = delete;

    public:
        static Partie& getInstance() {

            if (handler.instance == nullptr) handler.instance = new Partie;
            return *handler.instance;
        }

        static void libererInstance() {
            delete handler.instance;
            handler.instance = nullptr;
        }

        size_t getNbCartes(TypeCarte t) const;

        materiel::Carte& getCarte(size_t i);
        materiel::Jeton& getJeton(size_t i);
        class Iterator { //Iterator qui itère toutes les cartes d'un type en particulier ex Iterator(N1) itere toutes les cartes de type N1
        public:
            void next() {
                if (isDone()) throw SplendorException("Iterateur en fin de sequence");
                i++;
                if (!parcourtTout) {
                    while (!isDone() && getInstance().getCarte(i).getType() != type) {
                        i++;
                    }
                }
                //cout << "\n " << i << "\n";
            }
            bool isDone() const {
                return getInstance().nb_cartes == i;

            }
            materiel::Carte& currentItem() {
                if (isDone()) throw SplendorException("Iterateur en fin de sequence");
                return Partie::getInstance().getCarte(i);
            }

            size_t i = 0;
            TypeCarte type;
            bool parcourtTout;
            friend class Partie;

            Iterator(TypeCarte t) : type(t), parcourtTout(false) {
                while (getInstance().getCarte(i).getType() != type && !isDone()) {

                    i++;
                }

            };
            //defaut le type est inutile ici
            Iterator() : type(TypeCarte::N1), parcourtTout(true) { };


        };

        class IteratorJeton { //Iterator qui itère toutes les cartes d'un type en particulier ex Iterator(N1) itere toutes les cartes de type N1
        public:
            void next() {
                if (isDone()) throw SplendorException("Iterateur en fin de sequence");
                i++;
                if (!parcourtTout) {
                    while (!isDone() && getInstance().getJeton(i).getCouleur() != couleur) {
                        i++;
                    }
                }
                //cout << "\n " << i << "\n";
            }
            bool isDone() const {
                return getInstance().nb_jetons == i;

            }
            materiel::Jeton& currentItem() {
                if (isDone()) throw SplendorException("Iterateur en fin de sequence");
                return Partie::getInstance().getJeton(i);
            }

            size_t i = 0;
            Couleur couleur;
            bool parcourtTout;
            friend class Partie;

            IteratorJeton(Couleur c) : couleur(c), parcourtTout(false) {
                while (getInstance().getJeton(i).getCouleur() != couleur && !isDone()) {

                    i++;
                }

            };
            IteratorJeton() : couleur(Couleur::bleu), parcourtTout(true) { };


        };
        //parcourir qu'un type de couleur
        IteratorJeton getIteratorJeton(Couleur c) const { return IteratorJeton(c); }
        IteratorJeton getIteratorJeton() const { return IteratorJeton(); }
        //tout parcourir
        Iterator getIterator(TypeCarte t) const { return Iterator(t); }
        Iterator getIterator() const { return Iterator(); }
    };


    class Plateau {
    private: // pour debug
        std::vector<Carte*> cartesN1;
        std::vector<Carte*> cartesN2;
        std::vector<Carte*> cartesN3;
        std::vector<Carte*> cartesNoble;
        std::vector<Carte*> cartesCite;
        int nombre_joueurs;


        materiel::Pile* pileJaune;
        materiel::Pile* pileRouge;
        materiel::Pile* pileBleu;
        materiel::Pile* pileVert;
        materiel::Pile* pileNoir;
        materiel::Pile* pileBlanc;
        //const Jeton** jetons = nullptr;

        const size_t nbMax = 4;

    public:
        Plateau();
        Plateau(int nbjoueurs);

       
        ~Plateau();
        std::vector<Carte*>& getCarte(materiel::TypeCarte t);
        materiel::Pile& getPile(materiel::Couleur c);
        void ajouterCarte(materiel::Carte& c);

        void printCarte(ostream& f = std::cout) const;

        const size_t getNbCartesN1() const { return cartesN1.size(); }

        const size_t getNbCartesN2()const { return cartesN2.size(); }

        const size_t getNbCartesN3() const { return cartesN3.size(); }
        const size_t getNbCartesCite() const { return cartesCite.size(); }

        const size_t getNbCartesNoble() const { return cartesNoble.size(); }


    };



    class Joueur {
    private:

        const unsigned int ID;
        bool Ia;
        const std::string nom;
        std::vector<materiel::Carte*> Reserved;
        std::vector<materiel::Carte*> Cartes = {};
        materiel::Pile* pileJaune;
        materiel::Pile* pileRouge;
        materiel::Pile* pileBleu;
        materiel::Pile* pileVert;
        materiel::Pile* pileNoir;
        materiel::Pile* pileBlanc;
        Prix* reduction;
        int prestige = 0;
        materiel::Carte& choisirCarte();
        materiel::Couleur choisirJeton();
        friend class Controleur;
        bool hasciteCard;
        /*
        void ajouterJeton(Jeton* j) { Jetons.push(j); };
        Jeton* retirerJeton();
        void acheterCarte(Carte* c);
        void reserverCarte(Carte* c);
        */

    public:
        void printCarte(std::vector<materiel::Carte*>& v, ostream& f = cout);
        bool isIa()const { return Ia; }
        bool hasCite() { return hasciteCard; }
        Joueur(int i, string& n, string& ia) :nom(n), ID(i),hasciteCard(false) {
            cout << ia;
            pileRouge = new materiel::Pile(materiel::Couleur::rouge);
            pileVert = new materiel::Pile(materiel::Couleur::vert);
            pileBleu = new materiel::Pile(materiel::Couleur::bleu);
            pileBlanc = new materiel::Pile(materiel::Couleur::blanc);
            pileNoir = new materiel::Pile(materiel::Couleur::noir);
            pileJaune = new materiel::Pile(materiel::Couleur::jaune);
            Ia = ia == "0";
            Prix* reduction = new Prix(0, 0, 0, 0, 0);
        }
        ~Joueur() {
            delete pileBlanc;
            delete pileBleu;
            delete pileRouge;
            delete pileNoir;
            delete pileVert;
            delete pileJaune;
            Cartes.clear();
            Reserved.clear();
        };

        std::vector<Carte*>& getCarteReserve();
        std::vector<Carte*>& getCarteAchetes();
        // -------------functions pour afficher------------------------
        const int getJoueurID() const { return ID; };
        materiel::Pile& getPile(materiel::Couleur c);


        Prix* GetReduction();
        //Couleur GetBonus(); // pour calculer le bonus de joueur
        int GetPrestige() const;
        const  string  GetNom() const {
            return nom;
        };

        // -------------fin de functions pour afficher------------------------

        //----------------Methodes de choix d'actions//
        materiel::typeActions  ChoisirAction();

        //----------------fin de Methodes de choix d'actions//


    };
    class Controleur {
        
        bool someoneHasCite = false;
        int nombre_joueurs;
        materiel::Pioche* piocheN1;
        materiel::Pioche* piocheN2;
        materiel::Pioche* piocheN3;
        materiel::Pioche* piocheNoble;
        materiel::Pioche* piocheCite;
        bool isExtension;

        std::vector<Joueur*> joueurs;
        //Pile* pile;

        Plateau plateau;
        //Joueur* joueurs;


        bool donnerJeton(Couleur c);
        bool donner2jetons(Couleur c);
        bool donner3jetons();
        void donner3jetonsIa();

        bool reserverCarte(Carte& c);
        bool verifier_possibilite_cite(Carte& c);
        bool verifier_possibilite_achat(Carte& c);
        bool acheterCarte(Carte& c);
        //fonction pour aidant a la construction des deux fonctions du dessus
        bool verifierDansPile(std::vector<Carte*>& v, Carte& c);
        bool acheterDansPile(std::vector<Carte*>& v, Carte& c);


        bool verification_couleur(const int prix, Couleur couleur, int& joker);
        Controleur(int nb_joueurs,bool ext);
        friend class Regles;

        int current_joueur;

    public:
        bool hasSomeoneWon();
        void printPlayerWinner();
        void visiteNoble();
        int getNombreJoueurs() const { return nombre_joueurs; };
        void verifierRendreJetons();
        Controleur(const Controleur& c) = delete;

        Controleur& operator=(const Controleur& c) = delete;

        ~Controleur() {
            delete piocheN1;
            delete piocheN2;
            delete piocheN3;
            delete piocheNoble;
            joueurs.clear();
        }//delete pile; }

        materiel::Pioche& getPioche(materiel::TypeCarte t);



        Plateau& getPlateau() { return plateau; }
        void addPlayer();
        Joueur& getCurrentJoueur() { return *joueurs[current_joueur]; };
        void joueursuivant() {
            if (current_joueur < nombre_joueurs - 1) current_joueur++; else current_joueur = 0;
        }

        bool action(); //distinction des cas de chaque action puis apeler les fonctions privées void donner2jetons(); void donner3jetons(); void reserverCarte();void acheterCarte(); Retourne true ou false, selon si l'action a pu ou non être effectuée
        void actionIa();


        void distribuerCarte(); //distribue (si besoin) des cartes sur le plateau
    };
    class Regles {
        friend class Controleur;
        int nombre_joueurs;
        bool isExtension;
        Controleur* controleur = new Controleur(nombre_joueurs,isExtension);
        

    public:


        Regles(int nb_joueurs, bool ext) :nombre_joueurs(nb_joueurs),isExtension(ext) {
          

        };
        Controleur& getControleur() {

            return *controleur;
        }
    };

#endif
}


