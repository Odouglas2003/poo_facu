#include <QApplication>
#include "login.h"
#include "ventana.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login loginWindow;
    Ventana ventana;

    // Conectar la señal usuarioValido() de la ventana de inicio de sesión con la apertura de la ventana Ventana
    QObject::connect(&loginWindow, &Login::usuarioValido, [&]() {
        ventana.show();
    });

    loginWindow.show();

    return a.exec();
}
