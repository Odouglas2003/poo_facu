#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);

private slots:
    void cargarPagina();

private:
    QVBoxLayout *layout;
    QTextEdit *textoHTML;
    QLineEdit *urlInput;
    QNetworkAccessManager *manager;
};

#endif // VENTANA_H
