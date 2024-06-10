#ifndef TECLADO_H
#define TECLADO_H

#include "instrumento.h"
#include "electrico.h"

class Teclado : public Instrumento, public Electrico {
public:
    Teclado() : Instrumento("Teclado"), teclas(61) {}
    QString sonar() const override {
        return "Teclado suena...";
    }

    int getTeclas() const { return teclas; }
    void setTeclas(int value) { teclas = value; }

private:
    int teclas;
};

#endif // TECLADO_H
