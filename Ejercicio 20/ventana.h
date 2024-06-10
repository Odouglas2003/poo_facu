#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include "boton.h"

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();

private slots:
    void onBotonClicado();

private:
    Ui::Ventana *ui;
};

#endif // VENTANA_H
