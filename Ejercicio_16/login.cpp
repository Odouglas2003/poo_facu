#include "login.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrlQuery>
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QWidget(parent),
      networkManager(new QNetworkAccessManager(this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    leUsuario = new QLineEdit(this);
    leUsuario->setPlaceholderText("Usuario");
    layout->addWidget(leUsuario);

    leClave = new QLineEdit(this);
    leClave->setPlaceholderText("Clave");
    leClave->setEchoMode(QLineEdit::Password);
    layout->addWidget(leClave);

    pbLogin = new QPushButton("Validar", this);
    layout->addWidget(pbLogin);

    statusLabel = new QLabel(this);
    layout->addWidget(statusLabel);

    connect(pbLogin, SIGNAL(clicked()), this, SLOT(BotonLogin()));
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(NetworkReply(QNetworkReply*)));

    setLayout(layout);
}

Login::~Login()
{
}

void Login::BotonLogin()
{
    QString username = leUsuario->text();
    QString password = leClave->text();

    QUrl url("http://127.0.0.1:8000/validate_user");
    QUrlQuery query;
    query.addQueryItem("usuario", username);
    query.addQueryItem("clave", password);
    url.setQuery(query);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    networkManager->post(request, QByteArray());
}

void Login::NetworkReply(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
        QJsonObject jsonObject = jsonResponse.object();

        if (jsonObject.contains("nombre") && jsonObject.contains("apellido")) {
            QString fullName = jsonObject["nombre"].toString() + "::" + jsonObject["apellido"].toString();
            statusLabel->setText(fullName);
        } else {
            statusLabel->setText("Acceso Denegado");
        }
    } else {
        statusLabel->setText("Error de Network: " + reply->errorString());
    }

    reply->deleteLater();
}
