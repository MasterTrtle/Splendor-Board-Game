#include "splendor.h"

using namespace Splendor;

int main() {
    try {

    }
    catch (SplendorException& e) {
        std::cout << e.getInfo() << "\n";
    }
    //1 joueur
    Regles r = Regles(1);
    //uniquement pour ne pas avoir à écrire r.getControleur(), le controleur est géré par la règle.
    Controleur& c = r.getControleur();


   c.distribuerCarte();
    
    
    //affichage des cartes de chaque pioche (pour debug).
    c.getPiocheN1().printPioche();
    c.getPiocheN2().printPioche();
    c.getPiocheN3().printPioche();

    //affichage des cartes du plateau
    c.getPlateau().printCarte();
    //action pour le current_player
    c.action();


    //Idée de déroulé
    /*
    * input combien de joueurs voulez vous ?
    * Pour n = nombre de joueur:
    *   c.AddPlayer();
    *
      Tant que partie non finie
        tant que ! c.action (c.getcurrentJoueur().choisirAction()) //Au cas ou l'action n'est pas faisable, on la redemande
        
        c.distribuerCarte() //Au cas ou de nouvelles cartes doivent être distribuées sur le plateau
        c.getPlateau().printCarte();
        c.joueur_suivant();
        
    
    */
    // Dans un premier temps, Pour l'IA il faut juste que choisiraction() retourne une action au pif, de toute façon le controleur regardera si elle est jouable
    system("pause");
    return 0;
}
