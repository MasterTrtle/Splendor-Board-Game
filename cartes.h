#ifndef LO21_PROJET_SPLENDOR_A21_V1_NICO_CARTES_H
#define LO21_PROJET_SPLENDOR_A21_V1_NICO_CARTES_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>


using namespace std;

namespace cartes {

    class cartesException {
    public:
        cartesException(const string &i) : info(i) {}

        string getInfo() const { return info; }

    private:
        string info;
    };


    enum class TypeCarte {
        N1, N2, N3, Noble
    };

    class Cout {
    public:
        int vert;
        int bleu;
        int rouge;
        int blanc;
        int noir;
        int jaune;
    };


    class carte {
    private:
        const unsigned int ID;
        static int current_id;
        std::string Nom;
        Cout cout;
        int prestige;
        TypeCarte type;
        Cout bonus; // on a oublie ce truc
    public:
        unsigned int getID() const { return ID; }

        std::string getNom() const { return Nom; }

        Cout getCout() const { return cout; }

        Cout getBonus() const { return cout; }  // on a oublie ce truc

        int getPrestige() const { return prestige; }

        ~carte() = default;

        carte(string &n, Cout c, int p, TypeCarte t) : ID(current_id++), Nom(n), cout(c), prestige(p), type(t) {};
    };

    class Pioche {
    private:
        size_t nbCartes = 0;
        TypeCarte type_cartes;
        vector<carte *> cartes = {};

    public:
        bool estVide() const { return nbCartes == 0; }

        Pioche(TypeCarte t) : type_cartes(t) {};

        size_t getNbCartes() { return nbCartes; }

        carte* piocher();

        Pioche &operator<<(carte &e);

        void shufflePioche (){
            shuffle(std::begin(cartes), std::end(cartes), std::default_random_engine());
        }
    };
};



#endif //LO21_PROJET_SPLENDOR_A21_V1_NICO_CARTES_H
