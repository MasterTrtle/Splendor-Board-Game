#include "mainwindow.h"
#include "game_interface.h"
#include "game_setting.h"
#include <QApplication>
#include "splendor.h"

using namespace Splendor;
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
 MainWindow w;
  w.show();
  return a.exec();

//    try {
//        Controleur c;
//        c.distribuerCarte();

//        c.getPlateau().printCarte();

//        c.getPiocheN1().printPioche();
//        system("pause");
//        return 0;
//        }
//        catch (SplendorException& e) {
//            std::cout << e.getInfo() << "\n";
//        }


}
