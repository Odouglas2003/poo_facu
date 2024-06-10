#include "ventana.h"

Ventana::Ventana(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Ventana");
    setWindowState(Qt::WindowFullScreen);

    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(slot_descargaFinalizada(QNetworkReply*)));

    QNetworkRequest request(QUrl("https://www.shutterstock.com/image-vector/abstract-modern-graphic-element-dynamical-260nw-1447608500.jpg"));

    manager->get(request);
}

void Ventana::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    if (!im.isNull()) {
        QRect targetRect = rect(); // Rectángulo que abarca toda la ventana

        // Escalar la imagen manteniendo su relación de aspecto
        QImage scaledImage = im.scaled(targetRect.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

        // Centrar la imagen en la ventana
        int x = (width() - scaledImage.width()) / 2;
        int y = (height() - scaledImage.height()) / 2;

        painter.drawImage(x, y, scaledImage);
    }
}

void Ventana::slot_descargaFinalizada(QNetworkReply *reply) {
    im = QImage::fromData(reply->readAll());
    this->repaint();
}
