#ifndef LIENZO_H
#define LIENZO_H

#include <QVector>
#include <QPoint>
#include <QColor>

// Clase base para gestionar el lienzo
class Lienzo {
protected:
    struct PointWithColor {
        QPoint point;
        QColor color;
        int penWidth;
    };

    QVector<PointWithColor> path;
    QColor fondo;

public:
    Lienzo() : fondo(Qt::white) {}

    void limpiar() {
        path.clear();
    }

    friend class Pintura; // Declarar Pintura como friend para permitir el acceso a los miembros protegidos
};

#endif // LIENZO_H
