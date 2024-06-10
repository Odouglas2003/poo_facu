// ventana.cpp
#include "ventana.h"
#include "ui_ventana.h"
#include <QDebug>

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);

    // Colorear los botones
    ui->boton_1->colorear(Boton::Azul);
    ui->boton_2->colorear(Boton::Verde);
    ui->boton_3->colorear(Boton::Magenta);
    ui->boton_4->colorear(Boton::Azul);
    ui->boton_5->colorear(Boton::Verde);

    // Conectar la señal de clic de los botones a un slot
    connect(ui->boton_1, SIGNAL(signal_clic()), this, SLOT(onBotonClicado()));
    connect(ui->boton_2, SIGNAL(signal_clic()), this, SLOT(onBotonClicado()));
    connect(ui->boton_3, SIGNAL(signal_clic()), this, SLOT(onBotonClicado()));
    connect(ui->boton_4, SIGNAL(signal_clic()), this, SLOT(onBotonClicado()));
    connect(ui->boton_5, SIGNAL(signal_clic()), this, SLOT(onBotonClicado()));

    // Agregar espacio adicional arriba y abajo de los botones

}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::onBotonClicado()
{
    Boton *boton = qobject_cast<Boton*>(sender()); // Obtener el botón que emitió la señal
    if (boton) {
        // Realizar alguna acción basada en el botón que se ha clicado
        qDebug() << "Se hizo clic en un botón: " << boton->objectName();
    }
}
