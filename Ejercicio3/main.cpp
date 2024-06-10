#include <QString>
#include <QDebug>

// Espacio de nombres MyLibrary
namespace MyLibrary {
    QString getVersion() {
        return "v0.0.1 - 20240610";
    }
}

int main() {
    QString version = MyLibrary::getVersion();
    qDebug() << version;  // Imprime la versión en la salida de depuración
    return 0;
}
