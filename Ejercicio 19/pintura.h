#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include <QPoint>
#include <QVector>

class Pintura : public QWidget {
    Q_OBJECT

public:
    Pintura(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    QVector<QPoint> path;
    QColor penColor;
    int penWidth;
};

#endif // PINTURA_H
