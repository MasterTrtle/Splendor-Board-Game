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
   
    r.getControleur().distribuerCarte();

    r.getControleur().getPlateau().printCarte();
    
    r.getControleur().getPiocheN1().printPioche();

    r.getControleur().action(r.getControleur().getCurrentJoueur().ChoisirAction());

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
