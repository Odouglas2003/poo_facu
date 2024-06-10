#include "Identificacion.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QTime>

Identificacion::Identificacion(QWidget *parent) : QWidget(parent) {
    QFormLayout *identificacionLayout = new QFormLayout(this);

    legajoEdit = new QLineEdit(this);
    nombreEdit = new QLineEdit(this);
    apellidoEdit = new QLineEdit(this);
    captchaEdit = new QLineEdit(this);

    altaButton = new QPushButton("Alta", this);

    identificacionLayout->addRow("Legajo:", legajoEdit);
    identificacionLayout->addRow("Nombre:", nombreEdit);
    identificacionLayout->addRow("Apellido:", apellidoEdit);
    identificacionLayout->addRow("Captcha:", captchaEdit);

    qsrand(QTime::currentTime().msec()); // Semilla para la generación de números aleatorios
    int captchaNumber = qrand() % 10000 + 1;
    captchaLabel = new QLabel(QString::number(captchaNumber), this);
    identificacionLayout->addRow("", captchaLabel);
    identificacionLayout->addWidget(altaButton);

    connect(altaButton, &QPushButton::clicked, this, [=]() {
        // Validar que los campos legajo, nombre y apellido no estén vacíos
        if (legajoEdit->text().isEmpty() || nombreEdit->text().isEmpty() || apellidoEdit->text().isEmpty()) {
            QMessageBox::critical(this, "Error", "Por favor, complete todos los campos.");
            return;
        }

        if (captchaEdit->text().toInt() != captchaNumber) {
            QMessageBox::critical(this, "Error", "El captcha ingresado es incorrecto. Por favor, inténtelo de nuevo.");
            return;
        }

        this->close();
    });
}

void Identificacion::showWindow() {
    this->show();
}
