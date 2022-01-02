#include "game_setting.h"
#include "ui_game_setting.h"
#include "game_interface.h"
#include <QMessageBox>
#include <QString>

game_setting::game_setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game_setting)
{
    ui->setupUi(this);
    setWindowTitle("Splendor settings");
}

game_setting::~game_setting()
{
    delete ui;
}

void game_setting::on_buttonBox_accepted()
{
//   QString player1 = ui->usename1->text();
//   QString player2 = ui->usename1->text();
//   QString player3 = ui->usename1->text();
//   QString player4 = ui->usename1->text();
   int nb = ui->nb_jouers->value();
   game = new game_interface(nb);
   game->show();
}




void game_setting::on_nb_jouers_valueChanged(int arg1)
{
   //setFocusPolicy(Qt::NoFocus)
    if(arg1==2){
        ui->usename1->setEnabled(true);
        ui->usename1_2->setEnabled(true);
        ui->usename1_3->setEnabled(false);
        ui->usename1_4->setEnabled(false);
    } else if (arg1==3){
        ui->usename1->setEnabled(true);
        ui->usename1_2->setEnabled(true);
        ui->usename1_3->setEnabled(true);
        ui->usename1_4->setEnabled(false);
    }else{
        ui->usename1->setEnabled(true);
        ui->usename1_2->setEnabled(true);
        ui->usename1_3->setEnabled(true);
        ui->usename1_4->setEnabled(true);
    }
}


void game_setting::on_AI_checkBox_stateChanged(int arg1)
{
    if(arg1!=0){
        ui->usename1->setEnabled(true);
        ui->usename1_2->setEnabled(false);
        ui->usename1_3->setEnabled(false);
        ui->usename1_4->setEnabled(false);
        ui->usename1_2->setPlaceholderText("Tom(AI)");
        ui->usename1_3->setPlaceholderText("Tommy(AI)");
        ui->usename1_4->setPlaceholderText("Tomas(AI)");

    }if(arg1==0){
        ui->usename1->setEnabled(true);
        ui->usename1_2->setEnabled(true);
        ui->usename1_3->setEnabled(false);
        ui->usename1_4->setEnabled(false);
        ui->usename1_2->clear();
        ui->usename1_3->clear();
        ui->usename1_4->clear();
    }
}

