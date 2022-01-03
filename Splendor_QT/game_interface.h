#ifndef GAME_INTERFACE_H
#define GAME_INTERFACE_H

#include <QWidget>
#include <vector>
#include "vuecarte.h"
#include "splendor.h"
#include "materiel.h"
#include "game_end.h"

class QLabel;
class QLineEdit;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class QProgressBar;
class QLCDNumber;
class VueCarte;

namespace Ui {
class game_interface;
}

class game_interface : public QWidget
{
    Q_OBJECT

public:
     explicit game_interface(int nb,QString player1,QString player2,QString player3,QString player4,int AI,QWidget *parent = nullptr);
    ~game_interface();
    void game_over(bool Flag);

protected:
    void paintEvent(QPaintEvent *);

private slots:

private:
    Ui::game_interface *ui;
    //vuecarte* vuecartes;
    QString player1_nom;
    QString player2_nom;
    QString player3_nom;
    QString player4_nom;
    int AI_switch;
    unsigned int nb_players;
    vector<vuecarte*> vuecartes;
    QGridLayout* layoutCartes_DEV;
    QHBoxLayout* layoutCartes_NOBLE;
    QVBoxLayout* couche;
    bool flag= false;  // Est-ce que le jeu continue
    int toursRestant = 5;
    Splendor::Regles regle;
    game_end* end;



};

#endif // GAME_INTERFACE_H
