#include "pintura.h"
#include <QPainter>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>

Pintura::Pintura(QWidget *parent)
    : QWidget(parent), penColor(Qt::black), penWidth(2)
{
    setWindowTitle("Pintura");
    setGeometry(100, 100, 800, 600);
}

void Pintura::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen pen(penColor, penWidth, Qt::SolidLine);
    painter.setPen(pen);

    for (const auto &p : path) {
        painter.drawPoint(p);
    }
}

void Pintura::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        path.append(event->pos());
        update();
    }
}

void Pintura::wheelEvent(QWheelEvent *event) {
    int delta = event->angleDelta().y() / 120;
    penWidth += delta;
    if (penWidth < 1) {
        penWidth = 1;
    }
    update();
}

void Pintura::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_R:
        penColor = Qt::red;
        break;
    case Qt::Key_G:
        penColor = Qt::green;
        break;
    case Qt::Key_B:
        penColor = Qt::blue;
        break;
    case Qt::Key_Escape:
        path.clear();
        update();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}
