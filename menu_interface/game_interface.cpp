#include <QPainter>
#include "game_interface.h"
#include "ui_game_interface.h"

game_interface::game_interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game_interface)
{
    ui->setupUi(this);
    setWindowTitle("Splendor!");
    setFixedSize(1400,800);
}

game_interface::~game_interface()
{
    delete ui;
}

void game_interface::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("../menu_interface/image/background.png");
    painter.drawPixmap(0, 0, 1400, 800, pix);
}


void game_interface::on_card1_clicked()
{

}
void game_interface::on_card2_clicked()
{

}

void game_interface::on_card3_clicked()
{

}

void game_interface::on_card4_clicked()
{

}

void game_interface::on_card5_clicked()
{

}

void game_interface::on_card6_clicked()
{

}

void game_interface::on_card7_clicked()
{

}

void game_interface::on_card8_clicked()
{

}

void game_interface::on_card9_clicked()
{

}

void game_interface::on_card10_clicked()
{

}

void game_interface::on_card11_clicked()
{

}

void game_interface::on_card12_clicked()
{

}


