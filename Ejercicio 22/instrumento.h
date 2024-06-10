#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <QString>

class Instrumento {
public:
    Instrumento(const QString& nombre, const QString& marca = "Yamaha")
        : nombre(nombre), marca(marca) {}
    virtual ~Instrumento() {}

    virtual QString sonar() const = 0;
    virtual QString verlo() const {
        return "Marca: " + marca;
    }

    QString getNombre() const { return nombre; }

private:
    QString nombre;
    QString marca;
};

#endif // INSTRUMENTO_H
