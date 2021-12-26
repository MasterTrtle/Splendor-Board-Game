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

private slots:
    void on_buttonBox_accepted();

private:
    Ui::game_setting *ui;
    game_interface *game;
};

#endif // GAME_SETTING_H
