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
        materielException(const string &i) : info(i) {}

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
        vector<Jeton *> jetons = {};
    public:
        bool estVide() const { return nbJetons == 0; }

        Pile(const Couleur c) : couleur(c) {};

        Couleur getCouleur() const { return couleur; }

        size_t getNombre() const { return nbJetons; }

        Jeton * retirerJeton ();

        void ajouterJeton (Jeton * j);

        Pile &operator<<(Jeton &e);

    };


};



#endif //LO21_PROJET_SPLENDOR_A21_V1_NICO_MATERIEL_H
