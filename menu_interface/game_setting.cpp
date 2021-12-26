#include "game_setting.h"
#include "ui_game_setting.h"
#include "game_interface.h"
#include <QMessageBox>

game_setting::game_setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game_setting)
{
    ui->setupUi(this);
}

game_setting::~game_setting()
{
    delete ui;
}

void game_setting::on_buttonBox_accepted()
{
//    if (ui->nb_jouers->text()>5){
//        QMessageBox::warning(this,"Waring","Quatre joueurs au maximum",QMessageBox::Yes);
//        ui->nb_jouers->clear();
//      }else{
    game = new game_interface(nullptr);
    game->show();


}

