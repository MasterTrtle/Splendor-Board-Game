#pragma once
#ifndef LO21_PROJET_SPLENDOR_A21_V1_NICO_MATERIEL_H
#define LO21_PROJET_SPLENDOR_A21_V1_NICO_MATERIEL_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>


using namespace std;

namespace materiel {

    class materielException {
    public:
        materielException(const string& i) : info(i) {}

        string getInfo() const { return info; }

    private:
        string info;
    };


    class Prix {
    public:
        Prix(int v, int b, int r, int bl, int n) : vert(v), bleu(b), rouge(r), blanc(bl), noir(n) {};
        int vert;
        int bleu;
        int rouge;
        int blanc;
        int noir;
    };

    enum class Couleur {
        vert, bleu, rouge, blanc, noir, jaune
    };

    enum class typeActions {
        piocher2jetons, piocher3jetons, reserverCarte, acheterCarte
    };

    enum class TypeCarte {
        N1, N2, N3, Noble
    };


    class Carte {
    private:
        const unsigned int ID;

         std::string Nom;
         Prix* prix;
         int prestige;
         TypeCarte type;
         Couleur bonus;

    public:
        static int current_id;
        unsigned int getID() const { return ID; }

        std::string getNom() const { return Nom; }

        Prix getPrix() const { return *prix; }

        Couleur getBonus() const { return bonus; }  // on a oublie ce truc

        int getPrestige() const { return prestige; }

        TypeCarte getType() const { return type; }

        ~Carte() = default;

        Carte(string n, Prix* c, Couleur b, int p, TypeCarte t) : ID(current_id++), Nom(n), prix(c), bonus(b), prestige(p), type(t) {};
    };


    class Pioche {
    private:
        size_t nbCartes = 0;
        TypeCarte type_cartes;
        vector<Carte*> cartes = {};

    public:
        bool estVide() const { return nbCartes == 0; }

        Pioche(TypeCarte t) ; // on construit uniquement avec le type, les cartes sont choisies dans le constructeur directement

        //Pioche(TypeCarte t, vector<Carte*> c) : type_cartes(t), cartes(c) {};


        size_t getNbCartes() { return nbCartes; }


        const Carte& piocher();

        Pioche& operator<<(Carte& e);

        void shufflePioche() {
            shuffle(std::begin(cartes), std::end(cartes), std::default_random_engine());
        }

        void printPioche(ostream& f = cout) const;
    };


    // a voir si la classe jeton est utile, ou si on la supprime
    class Jeton {
    private:
        const Couleur couleur;

    public:
        explicit Jeton(const Couleur c) : couleur(c) {}

        Couleur getCouleur() const { return couleur; }
    };

    class Pile {
    private:
        const Couleur couleur;
        size_t nbJetons = 0;
        vector<Jeton*> jetons = {};
    public:
        bool estVide() const { return nbJetons == 0; }

        Pile(const Couleur c) : couleur(c) {};

        Couleur getCouleur() const { return couleur; }

        size_t getNombre() const { return nbJetons; }

        Jeton* retirerJeton();

        void ajouterJeton(Jeton* j);

        Pile& operator<<(Jeton& e);

    };



}


#endif //LO21_PROJET_SPLENDOR_A21_V1_NICO_MATERIEL_H

