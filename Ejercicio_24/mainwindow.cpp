#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Crear widgets
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    layout = new QVBoxLayout(centralWidget);
    label = new QLabel("Ingrese la URL del sitio web:", centralWidget);
    lineEdit = new QLineEdit(centralWidget);
    button = new QPushButton("Analizar web", centralWidget);
    saveButton = new QPushButton("Guardar HTML", centralWidget);
    saveCssButton = new QPushButton("Guardar CSS", centralWidget);

    // Conectar los botones a las funciones correspondientes
    connect(button, &QPushButton::clicked, this, &MainWindow::openWebsite);
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveHtmlToFile);
    connect(saveCssButton, &QPushButton::clicked, this, &MainWindow::saveCssToFile);

    // Añadir widgets al layout
    layout->addWidget(label);
    layout->addWidget(lineEdit);
    layout->addWidget(button);
    layout->addWidget(saveButton);
    layout->addWidget(saveCssButton);

    // Crear un objeto QNetworkAccessManager
    manager = new QNetworkAccessManager(this);

    // Conectar el objeto manager al slot replyFinished
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::replyFinished);
}

MainWindow::~MainWindow()
{
}

void MainWindow::openWebsite()
{
    // Obtener la URL ingresada por el usuario
    QString urlString = lineEdit->text();
    QUrl url(urlString);

    // Si la URL no es válida, mostrar mensaje de error
    if (!url.isValid()) {
        QMessageBox::warning(this, "Error", "URL no válida");
        return;
    }

    // Realizar la solicitud HTTP GET
    QNetworkRequest request(url);
    manager->get(request);
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    // Verificar si hay algún error en la respuesta
    if (reply->error() != QNetworkReply::NoError) {
        QMessageBox::warning(this, "Error", "Error al obtener el contenido de la página");
        reply->deleteLater();
        return;
    }

    // Leer el contenido de la respuesta
    htmlContent = reply->readAll();

    // Limpiar la respuesta
    reply->deleteLater();
}

void MainWindow::saveHtmlToFile()
{
    // Obtener la ubicación del archivo para guardar
    QString filePath = QFileDialog::getSaveFileName(this, tr("Guardar HTML"), QDir::homePath(), tr("Archivos de texto (*.txt)"));

    // Crear un objeto QFile para guardar el HTML en el archivo
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo para escribir");
        return;
    }

    // Escribir el contenido HTML en el archivo
    QTextStream out(&file);
    out << htmlContent;

    // Cerrar el archivo
    file.close();

    QMessageBox::information(this, "Éxito", "El HTML se ha guardado correctamente en el archivo");
}

void MainWindow::saveCssToFile()
{
    // Obtener la ubicación del archivo para guardar
    QString filePath = QFileDialog::getSaveFileName(this, tr("Guardar CSS"), QDir::homePath(), tr("Archivos de texto (*.css)"));

    // Crear un objeto QFile para guardar el CSS en el archivo
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo para escribir");
        return;
    }

    // Extraer bloques CSS del contenido HTML
    QStringList cssBlocks = extractCssBlocks(htmlContent);

    // Escribir los bloques CSS en el archivo
    QTextStream out(&file);
    for (const QString &cssBlock : cssBlocks) {
        out << cssBlock << "\n\n";
    }

    // Cerrar el archivo
    file.close();

    QMessageBox::information(this, "Éxito", "El CSS se ha guardado correctamente en el archivo");
}

QStringList MainWindow::extractCssBlocks(const QString &htmlContent)
{
    QRegExp cssRegex("\\{(.*?)\\}");
    QStringList cssBlocks;
    int pos = 0;

    while ((pos = cssRegex.indexIn(htmlContent, pos)) != -1) {
        cssBlocks << cssRegex.cap(1).trimmed();
        pos += cssRegex.matchedLength();
    }

    return cssBlocks;
}
