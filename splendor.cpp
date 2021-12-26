#include "splendor.h"
#include "ostream.cpp"
using namespace std;
using namespace materiel;
namespace Splendor {

    Partie::Handler Partie::handler = Handler();




    size_t Partie::getNbCartes(TypeCarte t) const {
        if (t == TypeCarte::N1) return nb_cartesN1;
        if (t == TypeCarte::N2) return nb_cartesN2;
        if (t == TypeCarte::N3) return nb_cartesN3;
        else return 0;
    }

      materiel::Carte& Partie::getCarte(size_t i) {
        return *cartes[i];
    }
    Partie::Partie() {

        std::ifstream ifs(R"(D:\Alex\Etude\Superieur\UTC\Informatique\LO21\lo21-projet-splendor-a21\cartes.json)");
        json jf = json::parse(ifs);

        unsigned int i = 0;
        for (i; i < nb_cartesN1; i++) {
            string vert =jf[i]["vert"];
            string bleu =jf[i]["bleu"];
            string rouge =jf[i]["rouge"];
            string blanc =jf[i]["blanc"];
            string noir =jf[i]["noir"];
            string Prestige =jf[i]["Prestige"];
            string couleur = jf[i]["Gem color"];
            materiel::Couleur temp;
            if (couleur == "red")
                temp = materiel::Couleur::rouge;
            if (couleur == "blue")
                temp = materiel::Couleur::bleu;
            if (couleur == "green")
                temp = materiel::Couleur::vert;
            if (couleur == "white")
                temp = materiel::Couleur::blanc;
            if (couleur == "black")
                temp = materiel::Couleur::noir;

            cartes[i] = new materiel::Carte(jf[i]["name"], new materiel::Prix(stoi(vert), stoi(bleu), stoi(rouge), stoi(blanc), stoi(noir)),
                                            temp, stoi(Prestige), TypeCarte::N1);
            //cout << *cartes[i] << "\n";
        }
        for (i; i < nb_cartesN1 + nb_cartesN2; i++) {

            string vert =jf[i]["vert"];
            string bleu =jf[i]["bleu"];
            string rouge =jf[i]["rouge"];
            string blanc =jf[i]["blanc"];
            string noir =jf[i]["noir"];
            string Prestige =jf[i]["Prestige"];
            string couleur = jf[i]["Gem color"];
            materiel::Couleur temp;
            if (couleur == "red")
                temp = materiel::Couleur::rouge;
            if (couleur == "blue")
                temp = materiel::Couleur::bleu;
            if (couleur == "green")
                temp = materiel::Couleur::vert;
            if (couleur == "white")
                temp = materiel::Couleur::blanc;
            if (couleur == "black")
                temp = materiel::Couleur::noir;

            cartes[i] = new materiel::Carte(jf[i]["name"], new materiel::Prix(stoi(vert), stoi(bleu), stoi(rouge), stoi(blanc), stoi(noir)),
                                            temp, stoi(Prestige), TypeCarte::N2);

            //cout << *cartes[i] << "\n";
        }
        for (i; i < nb_cartesN1 + nb_cartesN2 + nb_cartesN3; i++) {

            string vert =jf[i]["vert"];
            string bleu =jf[i]["bleu"];
            string rouge =jf[i]["rouge"];
            string blanc =jf[i]["blanc"];
            string noir =jf[i]["noir"];
            string Prestige =jf[i]["Prestige"];
            string couleur = jf[i]["Gem color"];
            materiel::Couleur temp;
            if (couleur == "red")
                temp = materiel::Couleur::rouge;
            if (couleur == "blue")
                temp = materiel::Couleur::bleu;
            if (couleur == "green")
                temp = materiel::Couleur::vert;
            if (couleur == "white")
                temp = materiel::Couleur::blanc;
            if (couleur == "black")
                temp = materiel::Couleur::noir;

            cartes[i] = new materiel::Carte(jf[i]["name"], new materiel::Prix(stoi(vert), stoi(bleu), stoi(rouge), stoi(blanc), stoi(noir)),
                                            temp, stoi(Prestige), TypeCarte::N3);
            //cout << *cartes[i] << "\n";
        }

        cout << "\n" << " --- fin constructeur de partie et de la génération des cartes --- " << "\n";
    }
    Partie::~Partie() {
        for (size_t i = 0; i < nb_cartes; i++) {

            delete cartes[i];

        }

    }

    Plateau::Plateau() : cartesN1(new const materiel::Carte* [4]), cartesN2(new const materiel::Carte* [4]),
        cartesN3(new const materiel::Carte* [4]) {}

    Plateau::~Plateau() {
        delete[] cartesN1;
        delete[] cartesN2;
        delete[] cartesN3;
    }

    
    bool Controleur::acheterCarte(Carte& c) {
        cout << "achat de carte de";
        return true;
    }
    bool Controleur::donner2jetons(Couleur c) {
        cout << "Don de deux jetons à ";
        return true;
    }
    bool Controleur::donner3jetons(Couleur c) {
        cout << "Don de trois jetons à ";
        return true;
    }
    bool Controleur::reserverCarte(Carte& c) {
        cout << "Reservation de carte de ";
        return true;
    }
    bool Controleur::action(materiel::typeActions t) {
        
        cout << "action effectuée par le joueur: " << getCurrentJoueur().GetNom(); //id incorrecte ??
        switch (t) {
        case materiel::typeActions::acheter:
            if (!acheterCarte(getCurrentJoueur().choisirCarte()))  return false;
            break;
        case materiel::typeActions::reserver:
            if(!reserverCarte(getCurrentJoueur().choisirCarte())) return false;
            break;
        case materiel::typeActions::piocher2jetons:
            if(! donner2jetons(getCurrentJoueur().choisirJeton())) return false;
            break;
        case materiel::typeActions::piocher3jetons:
            if(!donner3jetons(getCurrentJoueur().choisirJeton())) return false;
            break;
        }
    }
    Controleur::Controleur(int nb_joueurs):nombre_joueurs(nb_joueurs) {
        current_joueur = 0;
        for (int i = 0; i < nombre_joueurs;i++) {
            string nomJoueur;
            cout << "Nom du joueur " << i+1 << ": ";
            getline(cin, nomJoueur);
            Joueur* j = new Joueur(i, nomJoueur);
            //cout << j.getJoueurID();
            joueurs.push_back(j);
        }
        cout << (*joueurs[0]).getJoueurID(); // ici pas de pbs dans l'ID
        piocheN1 = new materiel::Pioche(materiel::TypeCarte::N1);
        piocheN2 = new materiel::Pioche(materiel::TypeCarte::N2);
        piocheN3 = new materiel::Pioche(materiel::TypeCarte::N3);
    };

    void Plateau::ajouterCarte( const materiel::Carte& c) {

        if (c.materiel::Carte::getType() == TypeCarte::N1) {
            if (nbCartesN1 < nbMax) {

                cartesN1[nbCartesN1] = &c;
                nbCartesN1++;
            }
            else throw SplendorException("trop de cartes sur le plateau N1 pour piocher");
        }
        else if (c.getType() == TypeCarte::N2) {

if (nbCartesN2 < nbMax) {
    cartesN2[nbCartesN2] = &c;

    nbCartesN2++;
}
else throw SplendorException("trop de cartes sur le plateau N2 pour piocher");
        }
        else if (c.getType() == TypeCarte::N3) {
        if (nbCartesN3 < nbMax) {

            cartesN3[nbCartesN3] = &c;
            nbCartesN3++;
        }
        else throw SplendorException("trop de cartes sur le plateau N3 pour piocher");
        }


    }

    void Controleur::distribuerCarte() {
        cout << " \n \n--Debut de la distribution--";

        if (plateau.getNbCartesN1() < 4 || plateau.getNbCartesN2() < 4 || plateau.getNbCartesN3() < 4) {


            while (!piocheN1->estVide() && plateau.getNbCartesN1() < 4) {
                plateau.ajouterCarte(piocheN1->piocher());


            }
            while (!piocheN2->estVide() && plateau.getNbCartesN2() < 4) {

                plateau.ajouterCarte(piocheN2->piocher());

            }
            while (!piocheN3->estVide() && plateau.getNbCartesN3() < 4) {
                plateau.ajouterCarte(piocheN3->piocher());

            }

            cout << "--fin distribution--";

        }
        else
            throw SplendorException("Impossible de distribuer des cartes, le plateau est plein");

    }

    void Plateau::printCarte(ostream& f) const {
        f << " \n Plateau::printcarte(), Cartes presentes sur le plateau: \n";
        f << "Cartes  N1: \n";
        for (size_t i = 0; i < nbCartesN1; i++) {
            f << *cartesN1[i] << "\n ";

        }
        f << "\n ";
        f << "Cartes  N2: \n";
        for (size_t i = 0; i < nbCartesN2; i++) {
            f << *cartesN2[i] << "\n ";
        }
        f << "\n";
        f << "Cartes  N3: \n";
        for (size_t i = 0; i < nbCartesN3; i++) {
            f << *cartesN3[i] << " \n";
        }
        f << "fin de Plateau::printcarte()";
        f << "\n";


    }
    materiel::typeActions Joueur::ChoisirAction() {
       
        int x = 0;
        cout << "\nQuelle action voulez vous effectuer: \n";
        cout << "1: Piocher 3 jetons differents\n";
        cout << "2: Piocher 2 jetons identiques\n";
        cout << "3: Acheter une carte\n";
        cout << "4: Réserver une carte\n";
        cin >> x;
        while (x != 1 && x != 2 && x != 3 && x != 4) {
            cout << "Veuillez choisir un nombre valide";
            
            cin >> x;
        }
        switch (x)
        {
        case 1:
            return materiel::typeActions::piocher3jetons;
        case 2:
            return materiel::typeActions::piocher2jetons;
        case 3:
            return materiel::typeActions::acheter;
        case 4:
            return materiel::typeActions::reserver;
        }
    }
    //Ici, on verifie juste que l'ID soit valide (carte existante), c'est le controleur qui verifie la faisabilité du choix de la carte
    materiel::Carte& Joueur::choisirCarte() {
        int id;
        cout << "\nVous devez choisir une carte, donnez son ID: \n";
        cin >> id;
        
        //tant que la carte n'existe pase
        while (true) {
            for (Partie::Iterator it = Partie::getInstance().getIterator(); !it.isDone(); it.next()) {
                if (it.currentItem().getID() == id) return it.currentItem();
            }
            cout << "\nL'ID ne correspond à aucune carte, renseignez un ID valide: \n";
            cin >> id;
        }


    }

    materiel::Couleur Joueur::choisirJeton() {
        cout << "\nVous devez choisir un jeton, donnez sa couleur: \n";
        cout << "1: vert\n";
        cout << "2: bleu\n";
        cout << "3: rouge\n";
        cout << "4: blanc\n";
        cout << "5: noir\n";
        materiel::Couleur c;
        int x = -1;
        cin >> x;
        while (x != 1 && x != 2 && x != 3 && x != 4 && x != 5) {
            cout << "Veuillez choisir un nombre valide";
            cin >> x;
        }
        switch (x)
        {
        case 1:
            return materiel::Couleur::vert;
        case 2:
            return  materiel::Couleur::bleu;
        case 3:
            return  materiel::Couleur::rouge;
        case 4:
            return materiel::Couleur::blanc;
        case 5:
            return materiel::Couleur::noir;
        }

    }
   

}
