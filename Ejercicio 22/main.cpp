#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <vector>
#include <memory>
#include "guitarra.h"
#include "bateria.h"
#include "teclado.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear y configurar la ventana principal
    QWidget window;
    window.setWindowTitle("Instrumentos Musicales");

    QVBoxLayout *layout = new QVBoxLayout(&window);

    QPushButton *btnSonarInstrumentos = new QPushButton("Sonar Todos los Instrumentos");
    QPushButton *btnVerMarcasInstrumentos = new QPushButton("Ver Marcas de Todos los Instrumentos");

    layout->addWidget(btnSonarInstrumentos);
    layout->addWidget(btnVerMarcasInstrumentos);

    // Crear instrumentos y almacenarlos en un vector
    std::vector<std::unique_ptr<Instrumento>> instrumentos;
    instrumentos.push_back(std::make_unique<Guitarra>());
    instrumentos.push_back(std::make_unique<Bateria>());
    instrumentos.push_back(std::make_unique<Teclado>());
    instrumentos.push_back(std::make_unique<Guitarra>());
    instrumentos.push_back(std::make_unique<Bateria>());

    // Conectar los botones a las funciones correspondientes
    QObject::connect(btnSonarInstrumentos, &QPushButton::clicked, [&]() {
        for (const auto& instrumento : instrumentos) {
            QMessageBox::information(&window, instrumento->getNombre(), instrumento->sonar());
        }
    });

    QObject::connect(btnVerMarcasInstrumentos, &QPushButton::clicked, [&]() {
        QString marcas;
        for (const auto& instrumento : instrumentos) {
            marcas += instrumento->getNombre() + ": " + instrumento->verlo() + "\n";
        }
        QMessageBox::information(&window, "Marcas de los Instrumentos", marcas);
    });

    // Mostrar la ventana
    window.show();

    return app.exec();
}
