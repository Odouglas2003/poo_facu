#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QWidget ventana;
    ventana.setWindowTitle("Control de Volumen");
    ventana.resize(300, 50);

    QSpinBox spinBox;
    QSlider slider(Qt::Horizontal);
    spinBox.setRange(0, 100);
    slider.setRange(0, 100);

    QObject::connect(&spinBox, SIGNAL(valueChanged(int)), &slider, SLOT(setValue(int)));
    QObject::connect(&slider, SIGNAL(valueChanged(int)), &spinBox, SLOT(setValue(int)));

    spinBox.setValue(15);

    QHBoxLayout layout;
    layout.addWidget(&spinBox);
    layout.addWidget(&slider);

    ventana.setLayout(&layout);
    ventana.show();

    // Ejecutamos la aplicación
    return app.exec();
}
