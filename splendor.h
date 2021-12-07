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


}

enum class Couleur {vert,bleu,rouge,blanc, noir, jaune};
enum class TypeCarte {'carte developpement N1',  'carte developpement N2', 'carte developpement N3', 'tuile noble'};

// a voir si la classe jeton est utile, ou si on la supprime
class Jeton {
private:
    const Couleur couleur;
public:
    Jeton(const couleur c): couleur (c) {}
    Couleur getCouleur() const { return couleur; }
};

class Pile {
private:
    const Couleur couleur;
    unsigned int nombre;
public:
    Pile(const couleur c, unsigned int n ): couleur(c), nombre(n) {}
    Couleur getCouleur() const { return couleur; }
    unsigned int getNombre() const {return nombre;}
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
    const unsigned int getID() const{ return ID;}
	std::string getNom() const { return Nom; }
	Cout getCout() const{ return cout; }
	int getPrestige() const{ return prestige; }
	~Carte() = default;
	Carte(const Carte& c) = default;
	Carte& operator=(const Carte& c) = default;
private:
	Carte(std::string id, std::string nom, Cout c, int p) :ID(id), Nom(nom), cout(c), prestige(p) {}
	const unsigned int ID;
	std::string Nom;
	Cout cout;
	int prestige;
};

class Pioche {
private:
    TypeCarte typePioche;
    const Carte** cartes = nullptr;
    size_t nb =0;
public:
    size_t getNombreCarte() const { return nb; }
    const Carte& piocher();
};



ostream& operator<<(ostream& f, const Carte& c);


#endif
