#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QFileDialog>
#include <QSize>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    void on_actionClose_triggered();

    void on_actionAbout_triggered();

    void on_actionNew_triggered();

    void on_actionClose_2_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
