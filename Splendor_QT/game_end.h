#ifndef GAME_END_H
#define GAME_END_H

#include <QDialog>
#include <QString>

namespace Ui {
class game_end;
}

class game_end : public QDialog
{
    Q_OBJECT

public:
    explicit game_end(QString winner,QWidget *parent = nullptr);
    ~game_end();
    void showNo1(QString);
    void showName();
    void showScore1();
signals:
    void end();

private slots:

    void on_pushButton_clicked();

private:
    Ui::game_end *ui;
    QString player_name;
};

#endif // GAME_END_H
