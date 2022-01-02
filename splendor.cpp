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
        if (t == TypeCarte::Noble) return nb_cartesNoble;

        else return 0;
    }

    materiel::Carte& Partie::getCarte(size_t i) {
        return *cartes[i];
    }
    materiel::Jeton& Partie::getJeton(size_t i) {
        return *jetons[i];
    }
    Partie::Partie() {

        cout << "\n" << " ---  constructeur de partie et de la génération des cartes --- " << "\n";
        //std::ifstream ifs(R"(D:\Alex\Etude\Superieur\UTC\Informatique\LO21\lo21-projet-splendor-a21\cartes.json)");
        std::ifstream ifs("cartes.json");
        json jf = json::parse(ifs);
        string vert, bleu, rouge, blanc, noir, Prestige, couleur, type;
        materiel::Couleur tempCouleur;
        materiel::TypeCarte tempType;


        unsigned int i = 0;
        for (i; i < jf.size(); i++) {
            vert = jf[i]["vert"]; // on doit convertir le string json en string sinon on ne peut pas stoi
            bleu = jf[i]["bleu"];
            rouge = jf[i]["rouge"];
            blanc = jf[i]["blanc"];
            noir = jf[i]["noir"];
            Prestige = jf[i]["Prestige"];
            type = jf[i]["Level"];

            if (type == "1")
                tempType = materiel::TypeCarte::N1;
            if (type == "2")
                tempType = materiel::TypeCarte::N2;
            if (type == "3")
                tempType = materiel::TypeCarte::N3;
            if (type == "noble") { // creatition des cartes nobles
                tempType = materiel::TypeCarte::Noble;
                cartes[i] = new materiel::Carte(jf[i]["name"],
                    new materiel::Prix(stoi(vert), stoi(bleu), stoi(rouge), stoi(blanc),
                        stoi(noir)), stoi(Prestige));
            }
            else { // creation des cartes de developpement
                couleur = jf[i]["Gem color"];
                if (couleur == "red")
                    tempCouleur = materiel::Couleur::rouge;
                if (couleur == "blue")
                    tempCouleur = materiel::Couleur::bleu;
                if (couleur == "green")
                    tempCouleur = materiel::Couleur::vert;
                if (couleur == "white")
                    tempCouleur = materiel::Couleur::blanc;
                if (couleur == "black")
                    tempCouleur = materiel::Couleur::noir;
                cartes[i] = new materiel::Carte(jf[i]["name"],
                    new materiel::Prix(stoi(vert), stoi(bleu), stoi(rouge), stoi(blanc),
                        stoi(noir)),
                    tempCouleur, stoi(Prestige), tempType);
            }
            cout << *cartes[i] << "\n";
        }
        for (i; i < nb_cartesN1 + nb_cartesN2; i++) {

            string vert = jf[i]["vert"];
            string bleu = jf[i]["bleu"];
            string rouge = jf[i]["rouge"];
            string blanc = jf[i]["blanc"];
            string noir = jf[i]["noir"];
            string Prestige = jf[i]["Prestige"];
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

            string vert = jf[i]["vert"];
            string bleu = jf[i]["bleu"];
            string rouge = jf[i]["rouge"];
            string blanc = jf[i]["blanc"];
            string noir = jf[i]["noir"];
            string Prestige = jf[i]["Prestige"];
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

        //generation des jeton
        for (int i = 0; i < 7; i++) {
            jetons[i] = new materiel::Jeton(materiel::Couleur::rouge);
        }
        for (int i = 7; i < 14; i++) {
            jetons[i] = new materiel::Jeton(materiel::Couleur::vert);
        }
        for (int i = 14; i < 21; i++) {
            jetons[i] = new materiel::Jeton(materiel::Couleur::bleu);
        }
        for (int i = 21; i < 28; i++) {
            jetons[i] = new materiel::Jeton(materiel::Couleur::noir);
        }
        for (int i = 28; i < 35; i++) {
            jetons[i] = new materiel::Jeton(materiel::Couleur::blanc);
        }
        for (int i = 35; i < 40; i++) {
            jetons[i] = new materiel::Jeton(materiel::Couleur::jaune);
        }

        cout << "\n" << " --- fin constructeur de partie et de la génération des cartes --- " << "\n";
    }
    Partie::~Partie() {
        for (size_t i = 0; i < nb_cartes; i++) {

            delete cartes[i];

        }

    }

    Plateau::Plateau() {
        pileRouge = new materiel::Pile(materiel::Couleur::rouge);
        pileRouge->remplir();
        pileVert = new materiel::Pile(materiel::Couleur::vert);
        pileVert->remplir();
        pileBleu = new materiel::Pile(materiel::Couleur::bleu);
        pileBleu->remplir();
        pileBlanc = new materiel::Pile(materiel::Couleur::blanc);
        pileBlanc->remplir();
        pileNoir = new materiel::Pile(materiel::Couleur::noir);
        pileNoir->remplir();
        pileJaune = new materiel::Pile(materiel::Couleur::jaune);
        pileJaune->remplir();
    }
    Plateau::Plateau(int nbjoueurs) {
        pileRouge = new materiel::Pile(materiel::Couleur::rouge);
        pileRouge->remplir();
        pileVert = new materiel::Pile(materiel::Couleur::vert);
        pileVert->remplir();
        pileBleu = new materiel::Pile(materiel::Couleur::bleu);
        pileBleu->remplir();
        pileBlanc = new materiel::Pile(materiel::Couleur::blanc);
        pileBlanc->remplir();
        pileNoir = new materiel::Pile(materiel::Couleur::noir);
        pileNoir->remplir();
        pileJaune = new materiel::Pile(materiel::Couleur::jaune);
        pileJaune->remplir();
        nombre_joueurs = nbjoueurs;
    }


    Plateau::~Plateau() {
        cartesN1.clear();
        cartesN2.clear();
        cartesN3.clear();
        delete pileBlanc;
        delete pileBleu;
        delete pileRouge;
        delete pileNoir;
        delete pileVert;
        delete pileJaune;
    }

    void Controleur::verifierRendreJetons() {
        while (
            getCurrentJoueur().getPile(Couleur::bleu).getNombre() +
            getCurrentJoueur().getPile(Couleur::rouge).getNombre() +
            getCurrentJoueur().getPile(Couleur::vert).getNombre() +
            getCurrentJoueur().getPile(Couleur::jaune).getNombre() +
            getCurrentJoueur().getPile(Couleur::blanc).getNombre() +
            getCurrentJoueur().getPile(Couleur::noir).getNombre() > 10)
        {
            cout << "\n Vous avez trop de jetons, il faut en rendre: ";
            Couleur c = getCurrentJoueur().choisirJeton();
            if (!getCurrentJoueur().getPile(c).estVide()) {
                getPlateau().getPile(c).ajouterJeton(getCurrentJoueur().getPile(c).retirerJeton());
            }
            else {
                cout << "\n Vous ne possedez pas de jeton de cette couleur, impossible d'en rendre";
            }
        }



    }
    // vert(v), bleu(b), rouge(r), blanc(bl), noir(n)
    Prix* Joueur::GetReduction() {
        delete reduction;
        reduction = new Prix(0, 0, 0, 0, 0);

        auto vachete = getCarteAchetes();
        for (size_t i = 0; i < vachete.size(); i++) {
            switch (vachete[i]->getBonus()) {
            case Couleur::blanc:
                reduction->blanc += 1;
                break;
            case Couleur::bleu:
                reduction->bleu += 1;
                break;
            case Couleur::vert:
                reduction->vert += 1;
                break;
            case Couleur::rouge:
                reduction->rouge += 1;
                break;
            case Couleur::noir:
                reduction->noir += 1;
                break;
            }
        }
        return reduction;
    }
    bool Controleur::verification_couleur(const int prix, Couleur couleur, int& joker) {

        if (prix <= getCurrentJoueur().getPile(couleur).getNombre() + joker) {
            //on enlève les joker si besoin
            if (prix > getCurrentJoueur().getPile(Couleur::vert).getNombre()) {
                joker -= prix - getCurrentJoueur().getPile(Couleur::vert).getNombre();
            }
            return true;
        }
        return false;
    }

    bool Controleur::acheterDansPile(std::vector<Carte*>& v, Carte& c) {
        std::vector<materiel::Carte*>& vachete = getCurrentJoueur().getCarteAchetes();
        int* joker = new int;
        *joker = getCurrentJoueur().getPile(Couleur::jaune).getNombre();

        if (std::count(v.begin(), v.end(), &c)) {
            //verification que le joueur à assez pour acheter
            Prix p = (c.getPrix());
            Prix* prixReduit = new Prix(
                p.vert - getCurrentJoueur().GetReduction()->vert,
                p.bleu - getCurrentJoueur().GetReduction()->bleu,
                p.rouge - getCurrentJoueur().GetReduction()->rouge,
                p.blanc - getCurrentJoueur().GetReduction()->blanc,
                p.noir - getCurrentJoueur().GetReduction()->noir
            );

            Couleur vert = Couleur::vert;
            Couleur bleu = Couleur::bleu;
            Couleur blanc = Couleur::blanc;
            Couleur rouge = Couleur::rouge;
            Couleur noir = Couleur::noir;
            //verification si le joueur a assez de jetons ( joker pour prendre en  compte les jetons dorés)

                //si il y a assez de jetons verts en prenant en compte les joker

                    //on les enlève
            while (prixReduit->vert > 0) {
                if (getCurrentJoueur().getPile(Couleur::vert).getNombre() != 0)
                {
                    getCurrentJoueur().getPile(Couleur::vert).retirerJeton();

                }
                //si plus de jetons, on doit enlever un jeton joker
                else {
                    getCurrentJoueur().getPile(Couleur::jaune).retirerJeton();
                }
                prixReduit->vert -= 1;
            }
            while (prixReduit->rouge > 0) {
                if (getCurrentJoueur().getPile(Couleur::rouge).getNombre() != 0)
                {
                    getCurrentJoueur().getPile(Couleur::rouge).retirerJeton();

                }
                //si plus de jetons, on doit enlever un jeton joker
                else {
                    getCurrentJoueur().getPile(Couleur::jaune).retirerJeton();
                }
                prixReduit->rouge -= 1;
            }
            while (prixReduit->bleu > 0) {
                if (getCurrentJoueur().getPile(Couleur::bleu).getNombre() != 0)
                {
                    getCurrentJoueur().getPile(Couleur::bleu).retirerJeton();

                }
                //si plus de jetons, on doit enlever un jeton joker
                else {
                    getCurrentJoueur().getPile(Couleur::jaune).retirerJeton();
                }
                prixReduit->bleu -= 1;
            }
            while (prixReduit->blanc > 0) {
                if (getCurrentJoueur().getPile(Couleur::blanc).getNombre() != 0)
                {
                    getCurrentJoueur().getPile(Couleur::blanc).retirerJeton();

                }
                //si plus de jetons, on doit enlever un jeton joker
                else {
                    getCurrentJoueur().getPile(Couleur::jaune).retirerJeton();
                }
                prixReduit->blanc -= 1;
            }
            while (prixReduit->noir > 0) {
                if (getCurrentJoueur().getPile(Couleur::noir).getNombre() != 0)
                {
                    getCurrentJoueur().getPile(Couleur::noir).retirerJeton();

                }
                //si plus de jetons, on doit enlever un jeton joker
                else {
                    getCurrentJoueur().getPile(Couleur::jaune).retirerJeton();
                }
                prixReduit->noir -= 1;
            }
            cout << "Vous achetez la carte " << c.getNom();
            v.erase(std::find(v.begin(), v.end(), &c));
            vachete.push_back(&c);
            return true;
        }




        return false;

    }
    bool Controleur::verifierDansPile(std::vector<Carte*>& v, Carte& c) {

        int* joker = new int;
        *joker = getCurrentJoueur().getPile(Couleur::jaune).getNombre();

        if (std::count(v.begin(), v.end(), &c)) {
            //verification que le joueur à assez pour acheter
            Prix p = (c.getPrix());
            Prix* prixReduit = new Prix(
                p.vert - getCurrentJoueur().GetReduction()->vert,
                p.bleu - getCurrentJoueur().GetReduction()->bleu,
                p.rouge - getCurrentJoueur().GetReduction()->rouge,
                p.blanc - getCurrentJoueur().GetReduction()->blanc,
                p.noir - getCurrentJoueur().GetReduction()->noir
            );

            Couleur vert = Couleur::vert;
            Couleur bleu = Couleur::bleu;
            Couleur blanc = Couleur::blanc;
            Couleur rouge = Couleur::rouge;
            Couleur noir = Couleur::noir;
            //verification si le joueur a assez de jetons ( joker pour prendre en  compte les jetons dorés)
            if (verification_couleur(prixReduit->vert, vert, *joker) &&
                verification_couleur(prixReduit->bleu, bleu, *joker) &&
                verification_couleur(prixReduit->blanc, blanc, *joker) &&
                verification_couleur(prixReduit->rouge, rouge, *joker) &&
                verification_couleur(prixReduit->noir, noir, *joker))
            {

                return true;
            }
            else {

                return false;
            }

        }

        return false;



    }
    bool Controleur::verifier_possibilite_achat(Carte& c) {
        std::vector<materiel::Carte*>& v1 = getPlateau().getCarte(TypeCarte::N1);
        std::vector<materiel::Carte*>& v2 = getPlateau().getCarte(TypeCarte::N2);
        std::vector<materiel::Carte*>& v3 = getPlateau().getCarte(TypeCarte::N3);
        std::vector<materiel::Carte*>& vreserved = getCurrentJoueur().getCarteReserve();

        if (
            verifierDansPile(v1, c) ||
            verifierDansPile(v2, c) ||
            verifierDansPile(v3, c) ||
            verifierDansPile(vreserved, c)
            ) return true;



        return false;

    }
    void Controleur::visiteNoble() {
        std::vector<materiel::Carte*>& vachete = getCurrentJoueur().getCarteAchetes();
        std::vector<materiel::Carte*>& v = getPlateau().getCarte(TypeCarte::Noble);
        for (int i = 0; i < v.size(); i++) {
            if (verifier_possibilite_achat(*v[i])) {
                v.erase(std::find(v.begin(), v.end(), v[i]));
                vachete.push_back(v[i]);
                cout << " \n Un noble vous a réndu visite \n";
            }

        }
    }
    bool Controleur::acheterCarte(Carte& c) {
        if (verifier_possibilite_achat(c)) {
            std::vector<materiel::Carte*>& v1 = getPlateau().getCarte(TypeCarte::N1);
            std::vector<materiel::Carte*>& v2 = getPlateau().getCarte(TypeCarte::N2);
            std::vector<materiel::Carte*>& v3 = getPlateau().getCarte(TypeCarte::N3);
            std::vector<materiel::Carte*>& vreserved = getCurrentJoueur().getCarteReserve();

            if (
                acheterDansPile(v1, c) ||
                acheterDansPile(v2, c) ||
                acheterDansPile(v3, c) ||
                acheterDansPile(vreserved, c)
                ) return true;

        }
        cout << "\nLa carte que vous voulez acheter n'est ni sur le plateau, ni dans vos réservations ou alors vous n'avez pas assez pour l'acheter\n";
        return false;
    }


    bool Controleur::donnerJeton(Couleur c) {
        if (getPlateau().getPile(c).getNombre() > 0) {
            cout << getCurrentJoueur().GetNom() << " a pioché un jeton " << c;
            getCurrentJoueur().getPile(c).ajouterJeton(getPlateau().getPile(c).retirerJeton());
            return true;
        }
        cout << "Il n'y a pas assez de jetons dans la pile des jetons joker  (" << getPlateau().getPile(c).getNombre() << "), aucun ne vous sera donc distribuer";
        return false;
    }
    bool Controleur::donner2jetons(Couleur c) {
        if (getPlateau().getPile(c).getNombre() >= 4) {
            cout << getCurrentJoueur().GetNom() << " a pioché deux jetons " << c;
            getCurrentJoueur().getPile(c).ajouterJeton(getPlateau().getPile(c).retirerJeton());
            getCurrentJoueur().getPile(c).ajouterJeton(getPlateau().getPile(c).retirerJeton());
            return true;
        }
        cout << "Il n'y a pas assez de jetons  (" << getPlateau().getPile(c).getNombre() << "), il en faut au minimum 4 pour en piocher 2";
        return false;
    }
    bool Controleur::donner3jetons() {
        cout << "\nChoisissez le premier jeton:";
        Couleur c1 = getCurrentJoueur().choisirJeton();
        while (getPlateau().getPile(c1).estVide()) {
            cout << "\n Il ne reste plus de jetons de cette couleur, veuillez en choisir un autre: ";
            int choix = 3;
            cout << " \nSi vous voulez changer d'action, entrez 1, si vous voulez continuer votre choix, entrez 2\n";
            while (choix != 1 && choix != 2) {
                cin >> choix;
                if (choix == 1) return false;

            }
            c1 = getCurrentJoueur().choisirJeton();
        }
        cout << "\nChoisissez un second jeton d'une couleur différente:";
        Couleur c2 = getCurrentJoueur().choisirJeton();
        while (getPlateau().getPile(c2).estVide() || c2 == c1) {
            cout << "\n Il ne reste plus de jetons de cette couleur ou alors vous avez deja choisi un jeton de cette couleur, veuillez en choisir un autre: ";
            int choix = 3;
            cout << "\n Si vous voulez changer d'action, entrez 1, si vous voulez continuer votre choix, entrez 2\n";
            while (choix != 1 && choix != 2) {
                cin >> choix;
                if (choix == 1) return false;
            }
            c2 = getCurrentJoueur().choisirJeton();
        }
        cout << "\nChoisissez un troisième jeton d'une couleur différente des deux autres:";
        Couleur c3 = getCurrentJoueur().choisirJeton();

        while (getPlateau().getPile(c3).estVide() || c3 == c2 || c3 == c1) {
            cout << "\n Il ne reste plus de jetons de cette couleur ou alors vous avez deja choisi un jeton de cette couleur, veuillez en choisir un autre: ";
            int choix = 3;
            cout << "\n Si vous voulez changer d'action, entrez 1, si vous voulez continuer votre choix, entrez 2\n";
            while (choix != 1 && choix != 2) {
                cin >> choix;
                if (choix == 1) return false;
            }
            c3 = getCurrentJoueur().choisirJeton();
        }
        getCurrentJoueur().getPile(c1).ajouterJeton(getPlateau().getPile(c1).retirerJeton());
        getCurrentJoueur().getPile(c2).ajouterJeton(getPlateau().getPile(c2).retirerJeton());
        getCurrentJoueur().getPile(c3).ajouterJeton(getPlateau().getPile(c3).retirerJeton());

        cout << "\n Don de trois jetons à " << getCurrentJoueur().GetNom();
        return true;
    }
    bool Controleur::reserverCarte(Carte& c) {
        std::vector<materiel::Carte*>& v1 = getPlateau().getCarte(TypeCarte::N1);
        std::vector<materiel::Carte*>& v2 = getPlateau().getCarte(TypeCarte::N2);
        std::vector<materiel::Carte*>& v3 = getPlateau().getCarte(TypeCarte::N3);
        std::vector<materiel::Carte*>& vreserved = getCurrentJoueur().getCarteReserve();

        if (vreserved.size() < 3) {
            if (std::count(v1.begin(), v1.end(), &c)) {
                cout << "Vous réservez la carte " << c.getNom() << " présente sur le plateau";
                v1.erase(std::find(v1.begin(), v1.end(), &c));
                vreserved.push_back(&c);
                return true;
            }

            if (std::count(v2.begin(), v2.end(), &c)) {
                cout << "Vous réservez la carte " << c.getNom() << " présente sur le plateau";
                v2.erase(std::find(v2.begin(), v2.end(), &c));
                vreserved.push_back(&c);
                return true;
            }
            if (std::count(v3.begin(), v3.end(), &c)) {
                cout << "Vous réservez la carte " << c.getNom() << " présente sur le plateau";
                v3.erase(std::find(v3.begin(), v3.end(), &c));
                vreserved.push_back(&c);
                donnerJeton(Couleur::jaune);
                return true;
            }
            cout << "\nLa carte que vous voulez réserver n'est pas sur le plateau\n";
            return false;
        }
        else {
            cout << "\nVous avez déjà 3 réservations, impossible d'en reserver plus\n";
            return false;
        }

    }
    bool Controleur::action() {
        materiel::typeActions t = getCurrentJoueur().ChoisirAction();
        cout << "action effectuée par le joueur: " << getCurrentJoueur().GetNom(); //id incorrecte ??
        switch (t) {
        case materiel::typeActions::acheter:
            if (!acheterCarte(getCurrentJoueur().choisirCarte()))  return false;
            break;
        case materiel::typeActions::reserver:
            if (!reserverCarte(getCurrentJoueur().choisirCarte())) return false;
            break;
        case materiel::typeActions::piocher2jetons:
            if (!donner2jetons(getCurrentJoueur().choisirJeton())) return false;
            break;
        case materiel::typeActions::piocher3jetons:
            if (!donner3jetons()) return false;
            break;

        }
        verifierRendreJetons();
        return true;
    }
    void Controleur::actionIa() {
        materiel::typeActions t = materiel::typeActions::acheter;
        cout << "action effectuée par le joueur: " << getCurrentJoueur().GetNom(); //id incorrecte ??

        //on essaye d'acheter chaque carte
        for (Partie::Iterator it = Partie::getInstance().getIterator(); !it.isDone(); it.next()) {
            if (acheterCarte(it.currentItem())) return;
        }
        // on essaye de piocher chaque jeton
        if (donner2jetons(materiel::Couleur::vert)) { verifierRendreJetons(); return; }
        if (donner2jetons(materiel::Couleur::bleu)) { verifierRendreJetons(); return; }
        if (donner2jetons(materiel::Couleur::rouge)) { verifierRendreJetons(); return; }
        if (donner2jetons(materiel::Couleur::noir)) { verifierRendreJetons(); return; }
        if (donner2jetons(materiel::Couleur::blanc)) { verifierRendreJetons(); return; }
    }


    materiel::Pioche& Controleur::getPioche(materiel::TypeCarte t) {
        switch (t) {
        case TypeCarte::N1:
            return *piocheN1;
        case TypeCarte::N2:
            return *piocheN2;
        case TypeCarte::N3:
            return *piocheN3;


        }
        throw SplendorException("le type de pioche n'a pas ete defini dans la fonction getPioche");

    }
    std::vector<Carte*>& Plateau::getCarte(materiel::TypeCarte t) {
        switch (t) {
        case TypeCarte::N1:
            return cartesN1;
        case TypeCarte::N2:
            return cartesN2;
        case TypeCarte::N3:
            return cartesN3;
        case TypeCarte::Noble:
            return cartesNoble;

        }
    }
    std::vector<Carte*>& Joueur::getCarteReserve() {
        return Reserved;

    }
    std::vector<Carte*>& Joueur::getCarteAchetes() {
        return Cartes;

    }
    materiel::Pile& Plateau::getPile(materiel::Couleur c) {
        switch (c) {
        case Couleur::blanc:

            return *pileBlanc;
        case Couleur::bleu:
            return *pileBleu;
        case Couleur::noir:
            return *pileNoir;
        case Couleur::vert:
            return *pileVert;
        case Couleur::rouge:
            return *pileRouge;
        case Couleur::jaune:
            return *pileJaune;

        }

    }
    materiel::Pile& Joueur::getPile(materiel::Couleur c) {
        switch (c) {
        case Couleur::blanc:

            return *pileBlanc;
        case Couleur::bleu:
            return *pileBleu;
        case Couleur::noir:
            return *pileNoir;
        case Couleur::vert:
            return *pileVert;
        case Couleur::rouge:
            return *pileRouge;
        case Couleur::jaune:
            return *pileJaune;

        }
    }
    Controleur::Controleur(int nb_joueurs) :nombre_joueurs(nb_joueurs) {
        current_joueur = 0;
        for (int i = 0; i < nombre_joueurs; i++) {
            string nomJoueur;
            string Ia;
            cout << "Nom du joueur " << i + 1 << ": ";
            cin.ignore();
            getline(cin, nomJoueur);
            cout << "Le joueur est-il une IA  ?,\n Entrez [0] si oui \n Entrez [1] si non ";
            cin >> nomJoueur;

            Joueur* j = new Joueur(i, nomJoueur, Ia);
            //cout << j.getJoueurID();
            joueurs.push_back(j);
        }
        cout << (*joueurs[0]).getJoueurID(); // ici pas de pbs dans l'ID
        piocheN1 = new materiel::Pioche(materiel::TypeCarte::N1);
        piocheN2 = new materiel::Pioche(materiel::TypeCarte::N2);
        piocheN3 = new materiel::Pioche(materiel::TypeCarte::N3);
        piocheNoble = new materiel::Pioche(materiel::TypeCarte::Noble);


        //on adapte la pile de jeton en fonction du nombre de joueur
        int nb_retirer = 0;
        if (nb_joueurs == 2) nb_retirer = 3;
        else if (nb_joueurs == 3) nb_retirer = 2;
        for (int i = 0; i < nb_retirer; i++) {
            getPlateau().getPile(Couleur::rouge).retirerJeton();
            getPlateau().getPile(Couleur::vert).retirerJeton();
            getPlateau().getPile(Couleur::bleu).retirerJeton();
            getPlateau().getPile(Couleur::blanc).retirerJeton();
            getPlateau().getPile(Couleur::noir).retirerJeton();
        }



    };

    void Plateau::ajouterCarte(materiel::Carte& c) {
        if (c.materiel::Carte::getType() == TypeCarte::N1) {
            if (getNbCartesN1() < nbMax) {
                cartesN1.push_back(&c);
            }
            else throw SplendorException("trop de cartes sur le plateau N1 pour piocher");
        }
        else if (c.getType() == TypeCarte::N2) {

            if (getNbCartesN2() < nbMax) {
                cartesN2.push_back(&c);

            }
            else throw SplendorException("trop de cartes sur le plateau N2 pour piocher");
        }
        else if (c.getType() == TypeCarte::N3) {
            if (getNbCartesN3() < nbMax) {
                cartesN3.push_back(&c);
            }
            else throw SplendorException("trop de cartes sur le plateau N3 pour piocher");
        }
        else if (c.getType() == TypeCarte::Noble) {
            if (getNbCartesNoble() < nbMax) {
                cartesNoble.push_back(&c);
            }
            else throw SplendorException("trop de cartes sur le plateau N3 pour piocher");
        }


    }

    void Controleur::distribuerCarte() {
        cout << " \n \n--Debut de la distribution--";

        if (plateau.getNbCartesN1() < 4 || plateau.getNbCartesN2() < 4 || plateau.getNbCartesN3() < 4 || plateau.getNbCartesNoble() < 4) {

            while (!piocheN1->estVide() && plateau.getNbCartesN1() < 4) {
                plateau.ajouterCarte(piocheN1->piocher());
            }
            while (!piocheN2->estVide() && plateau.getNbCartesN2() < 4) {

                plateau.ajouterCarte(piocheN2->piocher());
            }
            while (!piocheN3->estVide() && plateau.getNbCartesN3() < 4) {

                plateau.ajouterCarte(piocheN3->piocher());
            }
            while (!piocheNoble->estVide() && plateau.getNbCartesNoble() < 4) {
                plateau.ajouterCarte(piocheNoble->piocher());
            }


            cout << "--fin distribution--";

        }


    }
    void Joueur::printCarte(std::vector<materiel::Carte*>& v, ostream& f) {

        f << "\nles cartes: \n";
        for (size_t i = 0; i < v.size(); i++) {
            f << *v[i] << "\n ";

        }

    }
    void Plateau::printCarte(ostream& f) const {
        f << " \n Plateau::printcarte(), Cartes presentes sur le plateau: \n";
        f << "Cartes N1: \n";
        for (size_t i = 0; i < getNbCartesN1(); i++) {
            f << *cartesN1[i] << "\n ";

        }
        f << "\n ";
        f << "Cartes N2: \n";
        for (size_t i = 0; i < getNbCartesN2(); i++) {
            f << *cartesN2[i] << "\n ";
        }
        f << "\n";
        f << "Cartes N3: \n";
        for (size_t i = 0; i < getNbCartesN3(); i++) {
            f << *cartesN3[i] << " \n";
        }
        f << "\n";
        f << "Cartes Nobles: \n";
        for (size_t i = 0; i < getNbCartesN3(); i++) {
            f << *cartesNoble[i] << " \n";
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
