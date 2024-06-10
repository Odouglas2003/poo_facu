#include "pintura.h"
#include <QPainter>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>

Pintura::Pintura(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Pintura");
    setGeometry(100, 100, 800, 600);
}

void Pintura::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    for (const auto &p : path) {
        QPen pen(p.color, p.penWidth, Qt::SolidLine);
        painter.setPen(pen);
        painter.drawPoint(p.point);
    }
}

void Pintura::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        PointWithColor newPoint;
        newPoint.point = event->pos();
        newPoint.color = penColor;
        newPoint.penWidth = penWidth;
        path.append(newPoint);
        update();
    }
}

void Pintura::wheelEvent(QWheelEvent *event) {
    int delta = event->angleDelta().y() / 120;
    penWidth += delta;
    if (penWidth < 1) {
        penWidth = 1;
    }
    cambiarGrosor(penWidth);
    update();
}

void Pintura::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_R:
        cambiarColor(Qt::red);
        break;
    case Qt::Key_G:
        cambiarColor(Qt::green);
        break;
    case Qt::Key_B:
        cambiarColor(Qt::blue);
        break;
    case Qt::Key_Y:
        cambiarColor(Qt::yellow);
        break;
    case Qt::Key_N:
        cambiarColor(Qt::black);
        break;
    case Qt::Key_Escape:
        limpiar();
        update();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}
