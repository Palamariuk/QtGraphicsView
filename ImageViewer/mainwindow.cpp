#include "mainwindow.h"
#include "ui_mainwindow.h"

double zoom = 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->hide();
    this->setFixedSize(700, 350);
    this->setWindowTitle("ImageViewer");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    this->setCentralWidget(ui->label);
    QString filename = QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("Images(*.png *.jpg *.jpeg *.bmp *.xpm *.gif)"));
    QImage img;
    bool valid = img.load(filename);
    if(valid){
        ui->label->show();
        this->setWindowTitle("ImageViewer: " + filename);
        img.scaled(ui->label->width()*zoom, ui->label->height()*zoom, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        this->setFixedSize(img.width(), img.height());
        ui->label->setPixmap(QPixmap::fromImage(img));
    }
}


void MainWindow::on_actionClose_triggered()
{
    ui->label->clear();
    this->setFixedSize(700, 350);
    this->setWindowTitle("ImageViewer");
    ui->label->hide();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "Help", "If you have problems, please send me a message on my email: stolnyimax@gmail.com\nMax Palamariuk. NULP. 2020\nTurmalinStudio ");
}


void MainWindow::on_actionNew_triggered()
{
    MainWindow *a = new MainWindow;
    a->show();
}

void MainWindow::on_actionClose_2_triggered()
{
    close();
}
