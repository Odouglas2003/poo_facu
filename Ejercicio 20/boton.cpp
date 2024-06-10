
// boton.cpp
#include "boton.h"
#include <QPainter>

Boton::Boton(QWidget *parent)
    : QWidget(parent)
{
    // Configurar el botón aquí
}

void Boton::colorear(Color color)
{
    switch (color) {
    case Azul:
        m_color = Qt::blue;
        break;
    case Verde:
        m_color = Qt::green;
        break;
    case Magenta:
        m_color = Qt::magenta;
        break;
    }
    update(); // Actualizar la apariencia del botón
}

void Boton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    QImage fondo("../Users/tomas/OneDrive/Documents/Facultad/SEMESTRE 5/POO/Ejercicio_20/images.jpeg");
    painter.drawImage(rect(), fondo, fondo.rect());
    painter.fillRect(rect(), m_color); // Dibujar el botón con el color especificado

    // Dibujar el texto en el centro del botón
    painter.drawText(rect(), Qt::AlignCenter, m_text);
}

void Boton::mousePressEvent(QMouseEvent *event)
{
    emit signal_clic(); // Emitir la señal cuando se hace clic en el botón
    QWidget::mousePressEvent(event); // Propagar el evento para el procesamiento predeterminado
}

void Boton::setText(const QString& text)
{
    m_text = text; // Establecer el texto del botón
    update(); // Actualizar el botón para reflejar el cambio de texto
}
