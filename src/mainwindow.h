#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QStandardPaths>

#include <ui_mainwindow.h>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

public slots:
    void updateDir();
    void setDir(const QString& dirpath);
    void askDir();

private:
    Ui::MainWindow m_ui;

    QDir m_dir;

signals:

};

#endif // MAINWINDOW_H
