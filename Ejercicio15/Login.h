#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

class QLineEdit;
class QPushButton;

class Login : public QWidget {
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);

signals:
    void loginRequested(const QString &username, const QString &password);

private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
};

#endif // LOGIN_H
