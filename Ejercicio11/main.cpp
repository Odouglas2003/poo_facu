#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear objetos
    QLabel label("Etiqueta");
    QWidget widget;
    QPushButton button("Botón");
    QLineEdit lineEdit;

    // Mostrar los objetos
    label.show();
    widget.show();
    button.show();
    lineEdit.show();

    return app.exec();
}
