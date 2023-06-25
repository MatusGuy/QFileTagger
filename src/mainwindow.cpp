#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow{parent} {
    m_ui.setupUi(this);

    connect(
        m_ui.AOpen, &QAction::triggered,
        this, &MainWindow::askDir
    );

    connect(
        m_ui.SearchBox, &QLineEdit::textChanged,
        this, &MainWindow::updateDir
    );
}

void MainWindow::updateDir() {
    setDir(m_dir.path());
}

void MainWindow::setDir(const QString& dirpath) {
    m_ui.FilesView->clear();
    m_dir.setPath(dirpath);
    for (const QString& filename : m_dir.entryList(QDir::Files)) {
        if (filename.indexOf(m_ui.SearchBox->text()) != -1)
            m_ui.FilesView->addItem(filename);
    }
}

void MainWindow::askDir() {
    setDir(QFileDialog::getExistingDirectory(this,
        tr("Open folder"),
        QDir::homePath()
    ));
}
