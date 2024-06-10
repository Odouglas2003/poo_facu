#include "ventana.h"
#include <QNetworkRequest>
#include <QUrl>

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    textoHTML = new QTextEdit(this);
    urlInput = new QLineEdit(this);
    manager = new QNetworkAccessManager(this);

    connect(urlInput, &QLineEdit::returnPressed, this, &Ventana::cargarPagina);

    layout->addWidget(urlInput);
    layout->addWidget(textoHTML);

    setLayout(layout);
}

void Ventana::cargarPagina()
{
    QUrl url(urlInput->text());
    QNetworkRequest request(url);
    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            textoHTML->setPlainText(reply->readAll());
        } else {
            textoHTML->setPlainText("Error al cargar la página: " + reply->errorString());
        }

        reply->deleteLater();
    });
}
