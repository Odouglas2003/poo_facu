#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QPainter>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Ventana : public QWidget {
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void slot_descargaFinalizada(QNetworkReply *reply);

private:
    QImage im;
    QNetworkAccessManager *manager;
};

#endif // VENTANA_H
