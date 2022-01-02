#ifndef GAME_SETTING_H
#define GAME_SETTING_H

#include <QDialog>
#include "game_interface.h"
namespace Ui {
class game_setting;
}

class game_setting : public QDialog
{
    Q_OBJECT

public:
    explicit game_setting(QWidget *parent = nullptr);
    ~game_setting();
    game_interface* getGame()const {return game;};

private slots:
    void on_buttonBox_accepted();

    void on_nb_jouers_valueChanged(int arg1);

    void on_AI_checkBox_stateChanged(int arg1);

private:
    Ui::game_setting *ui;
    game_interface *game;
};

#endif // GAME_SETTING_H
