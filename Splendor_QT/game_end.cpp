#include "game_end.h"
#include "ui_game_end.h"

game_end::game_end(QString winner,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game_end)
{
    ui->setupUi(this);
    player_name= winner;
}

game_end::~game_end()
{
    delete ui;
}

void game_end::showNo1(QString PlayerImg)
{

}

void game_end::showName()
{
     ui->name1->setText(player_name);
}
void game_end::showScore1()
{
    ui->score1->setText("15");
}



void game_end::on_pushButton_clicked()
{

}

