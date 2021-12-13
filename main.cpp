#include "splendor.h"

using namespace Splendor;

int main() {
    try {

    }
    catch (SplendorException &e) {
        std::cout << e.getInfo() << "\n";
    }
    Controleur c;
    c.distribuerCarte();

    c.getPlateau().printCarte();
    c.getPiocheN1().printPioche();

    system("pause");
    return 0;
}
