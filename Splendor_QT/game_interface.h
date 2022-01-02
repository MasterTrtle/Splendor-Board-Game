#ifndef GAME_INTERFACE_H
#define GAME_INTERFACE_H

#include <QWidget>
#include "vuecarte.h"


namespace Ui {
class game_interface;
}

class game_interface : public QWidget
{
    Q_OBJECT

public:
    explicit game_interface(int nb,QWidget *parent = nullptr);
    ~game_interface();

protected:
    void paintEvent(QPaintEvent *);

private slots:

private:
    Ui::game_interface *ui;
    vuecarte* vuecartes;
    QString player1_nom;
    QString player2_nom;
    QString player3_nom;
    QString player4_nom;
    unsigned int nb_players;
};

#endif // GAME_INTERFACE_H
