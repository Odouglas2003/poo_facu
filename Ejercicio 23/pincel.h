#ifndef PINCEL_H
#define PINCEL_H

#include <QColor>

// Clase base para gestionar el pincel
class Pincel {
public:
    int penWidth;
    QColor penColor;

    Pincel() : penWidth(2), penColor(Qt::black) {}

    inline void cambiarColor(QColor nuevoColor) {
        penColor = nuevoColor;
    }

    inline void cambiarGrosor(int nuevoGrosor) {
        penWidth = nuevoGrosor;
    }
};

#endif // PINCEL_H
