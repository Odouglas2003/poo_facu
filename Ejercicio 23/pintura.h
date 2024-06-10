#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include "pincel.h"
#include "lienzo.h"

// Clase Pintura que hereda de QWidget, Pincel y Lienzo
class Pintura : public QWidget, public Pincel, public Lienzo {
    Q_OBJECT

public:
    Pintura(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // PINTURA_H
