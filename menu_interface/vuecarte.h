#ifndef VUECARTE_H
#define VUECARTE_H
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include "materiel.h"

class vuecarte : public QPushButton
{
    Q_OBJECT

public:
    vuecarte(const materiel::Carte& c, QWidget *parent = nullptr);
    explicit vuecarte(QWidget *parent = nullptr);
    // affecter une nouvelle carte 鑴la vue
    void setCarte(const materiel::Carte& c) { setCheckable(true); setChecked(false); carte=&c; update(); }
    // vue sans carte
    void setNoCarte() { carte=nullptr; setCheckable(false); update(); }
    const materiel::Carte& getCarte() const { return *carte; }
    bool cartePresente() const { return carte!=nullptr; }

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    const materiel::Carte* carte=nullptr;
    QPen pen;
    QBrush brush;
signals:
    // quand la vude de carte est cliqu鑼卐, elle 鑼卪et un signal en transmettant son adresse
    void carteClicked(vuecarte*);
public slots:

private slots:

    void clickedEvent() { emit carteClicked(this); }


};








#endif // VUECARTE_H
