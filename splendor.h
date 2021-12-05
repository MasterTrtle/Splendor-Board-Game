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
class Jetons {
	int vert;
	int bleu;
	int rouge;
	int blanc;
	int noir;
	int joker;
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
	std::string getID() const{ return ID;}
	std::string getNom() const { return Nom; }
	Cout getCout() const{ return cout; }
	int getPrestige() const{ return prestige; }
	~Carte() = default;
	Carte(const Carte& c) = default;
	Carte& operator=(const Carte& c) = default;
private:
	Carte(std::string id, std::string nom, Cout c, int p) :ID(id), Nom(nom), cout(c), prestige(p) {}
	std::string ID;
	std::string Nom;
	Cout cout;
	int prestige;

	class Jeu {
};





};


ostream& operator<<(ostream& f, const Carte& c);


#endif
