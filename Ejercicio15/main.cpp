#include <QApplication>
#include "Login.h"
#include "Identificacion.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Ventana de login
    Login loginWindow;
    loginWindow.setWindowTitle("Login");

    // Ventana de identificacion
    Identificacion identificacionWindow;
    identificacionWindow.setWindowTitle("Identificacion");

    QObject::connect(&loginWindow, &Login::loginRequested, &identificacionWindow, &Identificacion::showWindow);

    loginWindow.show();

    return app.exec();
}
