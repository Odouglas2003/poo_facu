#ifndef GUITARRA_H
#define GUITARRA_H

#include "instrumento.h"

class Guitarra : public Instrumento {
public:
    Guitarra() : Instrumento("Guitarra"), cuerdas(6) {}
    QString sonar() const override {
        return "Guitarra suena...";
    }

    int getCuerdas() const { return cuerdas; }
    void setCuerdas(int value) { cuerdas = value; }

private:
    int cuerdas;
};

#endif // GUITARRA_H
