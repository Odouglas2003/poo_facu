#include "Login.h"
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

Login::Login(QWidget *parent) : QWidget(parent) {
    this->setFixedSize(250, 120);
    this->setWindowTitle("Login");

    QGridLayout *loginLayout = new QGridLayout(this);

    QLabel *userLabel = new QLabel("Usuario:", this);
    userLabel->setAlignment(Qt::AlignRight);

    usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("Ingrese su usuario");

    QLabel *passwordLabel = new QLabel("Clave:", this);
    passwordLabel->setAlignment(Qt::AlignRight);

    passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("Ingrese su contraseña");
    passwordEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Entrar", this);

    loginLayout->addWidget(userLabel, 0, 0);
    loginLayout->addWidget(usernameEdit, 0, 1);
    loginLayout->addWidget(passwordLabel, 1, 0);
    loginLayout->addWidget(passwordEdit, 1, 1);
    loginLayout->addWidget(loginButton, 2, 0, 1, 2);

    connect(loginButton, &QPushButton::clicked, this, [=]() {
        if (usernameEdit->text() == "admin" && passwordEdit->text() == "1111") {
            emit loginRequested(usernameEdit->text(), passwordEdit->text());
        } else {
            this->close();
        }
        this->close();
    });
}
