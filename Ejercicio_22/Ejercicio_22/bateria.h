#ifndef BATERIA_H
#define BATERIA_H

#include "instrumento.h"

class Bateria : public Instrumento {
public:
    Bateria() : Instrumento("Bateria"), tambores(5) {}
    QString sonar() const override {
        return "Batería suena...";
    }

    int getTambores() const { return tambores; }
    void setTambores(int value) { tambores = value; }

private:
    int tambores;
};

#endif // BATERIA_H
