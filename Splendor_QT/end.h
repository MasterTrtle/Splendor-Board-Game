#ifndef END_H
#define END_H

#include <QDialog>

namespace Ui {
class end;
}

class end : public QDialog
{
    Q_OBJECT

public:
    explicit end(QWidget *parent = nullptr);
    ~end();
    void showNo1(QString);
    void showNo2(QString);
    void showPlayer11Name(QString);
    void showPlayer2Name(QString);
    void showScore1(int);
    void showScore2(int);

private:
    Ui::end *ui;
private slots:
    void on_back_clicked();
};

#endif // END_H
