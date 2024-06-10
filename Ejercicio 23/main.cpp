#include <QApplication>
#include "pintura.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    Pintura ventana;
    ventana.show();
    return app.exec();
}
