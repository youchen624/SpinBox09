#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QColor>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->spinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &MainWindow::onSpinBoxValueChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onSpinBoxValueChanged(int value) {
    int r = QRandomGenerator::global()->bounded(256);
    int g = QRandomGenerator::global()->bounded(256);
    int b = QRandomGenerator::global()->bounded(256);

    QColor randomColor(r, g, b);
    QString styleSheet = QString("QLCDNumber {"
                                 "background-color: %1;"
                                 "color: %2;"
                                 "border: 2px solid %1;"
                                 "}"
                                 "QLCDNumber::segment {"
                                 "background-color: %1;"
                                 "}").arg(randomColor.name()).arg(randomColor.lightnessF() > 0.5 ? "black" : "white");
    ui->lcdNumber->setStyleSheet(styleSheet);
    ui->lcdNumber->display(value);
}
