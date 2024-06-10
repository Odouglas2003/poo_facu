#include "login.h"
#include "ventana.h"
#include <QGridLayout>
#include <QDebug>

Login::Login(QWidget *parent)
    : QWidget(parent)
{
    lUsuario = new QLabel("Usuario:");
    lClave = new QLabel("Clave:");
    leUsuario = new QLineEdit();
    leClave = new QLineEdit();
    pbValidar = new QPushButton("Validar");

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(lUsuario, 0, 0);
    layout->addWidget(leUsuario, 0, 1);
    layout->addWidget(lClave, 1, 0);
    layout->addWidget(leClave, 1, 1);
    layout->addWidget(pbValidar, 2, 0, 1, 2);

    connect(pbValidar, SIGNAL(pressed()), this, SLOT(slot_ValidarUsuario()));
    connect(leClave, SIGNAL(returnPressed()), this, SLOT(slot_ValidarUsuario()));
}

Login::~Login()
{
    delete lUsuario;
    delete lClave;
    delete leUsuario;
    delete leClave;
    delete pbValidar;
}

void Login::slot_ValidarUsuario()
{
    QString usuario = leUsuario->text();
    QString clave = leClave->text();

    if (usuario == "admin" && clave == "1234") {
        qDebug() << "Usuario válido";
        emit usuarioValido();
        this->close();
    } else {
        qDebug() << "Usuario inválido";
    }
}
