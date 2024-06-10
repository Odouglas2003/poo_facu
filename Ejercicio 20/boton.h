// boton.h
#ifndef BOTON_H
#define BOTON_H

#include <QWidget>

class Boton : public QWidget
{
    Q_OBJECT

public:
    enum Color { Azul, Verde, Magenta };

    Boton(QWidget *parent = nullptr);
    void colorear(Color color);
    void setText(const QString& text); // Método para establecer el texto del botón

signals:
    void signal_clic();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    QColor m_color;
    QString m_text; // Variable para almacenar el texto del botón
};

#endif // BOTON_H
