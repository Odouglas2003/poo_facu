#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void BotonLogin();
    void NetworkReply(QNetworkReply *reply);

private:
    QLineEdit *leUsuario;
    QLineEdit *leClave;
    QPushButton *pbLogin;
    QLabel *statusLabel;
    QNetworkAccessManager *networkManager;
};

#endif // LOGIN_H
