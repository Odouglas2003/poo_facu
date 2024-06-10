
#include "login.h"

#include <QDebug>
#include <QPainter>

Login::Login(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Login");
    setFixedSize(600, 400);


    // Crear los elementos de la interfaz
    lUsuario = new QLabel("Usuario:");
    lClave = new QLabel("Clave:");
    leUsuario = new QLineEdit();
    leClave = new QLineEdit();
    leClave->setEchoMode( QLineEdit::Password );
    pbIngresar = new QPushButton("Ingresar"); // Cambiando el nombre del QPushButton

    // Crear el layout y añadir los elementos
    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->addWidget(lUsuario, 0, 0);
    gridLayout->addWidget(leUsuario, 0, 1, 1, 2);
    gridLayout->addWidget(lClave, 1, 0);
    gridLayout->addWidget(leClave, 1, 1, 1, 2);
    gridLayout->addWidget(pbIngresar, 2, 1, 1, 1);

    // Conectar el clic del botón al slot_validarUsuario
    connect(pbIngresar, SIGNAL(pressed()), this, SLOT(slot_validarUsuario()));

    manager = new QNetworkAccessManager( this );

    connect( manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(slot_descargaFinalizada(QNetworkReply*)));

    QNetworkRequest request( QUrl( "https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEjqKFbXPLmoTaXmgvFDJxcT2L3KWCdLrwI4FIi8rLxVAYBkmofOvzIpPXEAkU9Oba4OD2VF1zWVGQPMPnBcwojztewxcevaalMMEFWrFPq7UrEVsL-PmzGHbNgbUPipCmk2LUraHmBjNBg/s1600/Captura+de+pantalla+de+2016-07-19+23-58-04.png") );

    manager->get( request );
}

void Login::paintEvent(QPaintEvent *)  {
    QPainter painter( this );
    painter.drawImage( 0, 0, im.scaled(this->width(), this->height()) );

}

void Login::slot_validarUsuario() {
    if (leUsuario->text() == "admin" && leClave->text() == "1234") {
        Ventana *ventana = new Ventana();
        ventana->show();
        this->close();
    } else {
        leClave->clear();
    }
}

void Login::slot_descargaFinalizada(QNetworkReply *reply)  {
    im = QImage::fromData( reply->readAll() );
    this->repaint();
}
