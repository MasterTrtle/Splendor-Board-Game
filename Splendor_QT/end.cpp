#include "end.h"
#include "ui_end.h"

end::end(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::end)
{
    ui->setupUi(this);
}

end::~end()
{
    delete ui;
}

void end::showNo1(QString PlayerImg)
{
    ui->no1->setStyleSheet(PlayerImg);
}

void end::showNo2(QString PlayerImg)
{
    ui->no2->setStyleSheet(PlayerImg);
}

void end::showPlayer11Name(QString name)
{
    ui->name1->setText(name);
}

void end::showPlayer2Name(QString name)
{
    ui->name2->setText(name);
}

void end::showScore1(int score)
{
    ui->score1->setText(QString::number(score));
}

void end::showScore2(int score)
{
    ui->score2->setText(QString::number(score));
}

void end::on_back_clicked()
{
    close();
    emit end();
}
