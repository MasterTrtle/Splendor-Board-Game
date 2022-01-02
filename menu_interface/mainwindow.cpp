#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game_interface.h"
#include "game_setting.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Splendor MainSurface");
    setFixedSize(1400,800);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("../menu_interface/image/menu.png");
    painter.drawPixmap(0, 0, 1400, 800, pix);
}

void MainWindow::on_pushButton_2_clicked()
{
    gameSetting = new game_setting(this);
    gameSetting->show();

}



void MainWindow::on_pushButton_3_clicked()
{
    exit(0);
}

