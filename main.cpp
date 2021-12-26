#include "splendor.h"

using namespace Splendor;

int main() {
    try {

    }
    catch (SplendorException& e) {
        std::cout << e.getInfo() << "\n";
    }
    Controleur c;
    c.distribuerCarte();

    c.getPlateau().printCarte();
    
    c.getPiocheN1().printPioche();

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
