#ifndef ELECTRICO_H
#define ELECTRICO_H

#include <QString>
#include <QDebug>

class Electrico {
public:
    Electrico() : voltaje(220) {}
    ~Electrico() {
        qDebug() << "Desenchufado";
    }

protected:
    int voltaje;
};

#endif // ELECTRICO_H
