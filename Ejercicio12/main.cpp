#include <QApplication>
#include <QLabel>
#include <QImage>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear un objeto QLabel
    QLabel label;

    // Cargar la imagen desde un archivo
    QImage image("C:/Users/octav/OneDrive/Imágenes/facultad/POO/Todo los trabajos/Ejercicio12/website.jpg");

    // Verificar si hay algún error al cargar la imagen
    if(image.isNull()) {
        qDebug() << "Error al cargar la imagen";
    }

    // Configurar la imagen en el QLabel sin deformarla
    label.setPixmap(QPixmap::fromImage(image).scaled(label.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // Mostrar el QLabel de forma maximizada
    label.showMaximized();

    // Configurar un temporizador para cerrar la aplicación después de 3 segundos
    QTimer::singleShot(3000, &app, SLOT(quit()));

    return app.exec();
}
