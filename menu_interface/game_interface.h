#ifndef GAME_INTERFACE_H
#define GAME_INTERFACE_H

#include <QWidget>

namespace Ui {
class game_interface;
}

class game_interface : public QWidget
{
    Q_OBJECT

public:
    explicit game_interface(QWidget *parent = nullptr);
    ~game_interface();

protected:
    void paintEvent(QPaintEvent *);

private slots:

    void on_card1_clicked();
    void on_card2_clicked();
    void on_card3_clicked();
    void on_card4_clicked();
    void on_card5_clicked();
    void on_card6_clicked();
    void on_card7_clicked();
    void on_card8_clicked();
    void on_card9_clicked();
    void on_card10_clicked();
    void on_card11_clicked();
    void on_card12_clicked();

private:
    Ui::game_interface *ui;
};

#endif // GAME_INTERFACE_H
