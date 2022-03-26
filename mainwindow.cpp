#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <qstring.h>

#define M_PI       3.14159265358979323846

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    double a, b, c, d, x1, x2;
    a = ui->doubleSpinBox_a->value();
    b = ui->doubleSpinBox_b->value();
    c = ui->doubleSpinBox_c->value();

    //d = b * b - 4 * a * c; //декриминант
    d=pow(b,2)-4*a*c;
    if(d>0)
    {
        x1 = ((-b) + sqrt(d)) / 2 * a;
        x2 = ((-b) - sqrt(d)) / 2 * a;
        ui->label_2->setText(ui->label_2->text() + "x1 = " + QString::number(x1) + "\nx2 = " + QString::number(x2));
    }
    if (d == 0)
    {
     x1 = -(b / 2 * a);
     ui->label_2->setText(ui->label_2->text() + "x1 = x2 = " + QString::number(x1));
    }
    if (d < 0)
    {
        ui->label_2->setText("D < 0, корней уравнения не существует");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    double a,b,c,angle_1, angle_rad;
    if (ui->radioButton->isChecked())
    {
       angle_rad = ui->spinBoxAngle->value();
       angle_1 = (angle_rad*180)/M_PI;
    }
    else {
       angle_1 = ui->spinBoxAngle->value();
    }

    a = ui->spinBox_a->value();
    b = ui->spinBox_b->value();


    if (angle_1 < 90)
    {
        c = sqrt(pow(a,2) + pow(b,2) - (2*a*b) * -(cos(angle_1)));
        ui->label_4->clear();
        ui->label_4->setText(ui->label_4->text() + "Третья сторона равна: " + QString::number(c));
    }
    if  (angle_1 < 90)
    {
        c = sqrt(pow(a,2) + pow(b,2) - (2*a*b) * (cos(angle_1)));
        ui->label_4->clear();
        ui->label_4->setText(ui->label_4->text() + "Третья сторона равна: " + QString::number(c));
    }
    if (angle_1 == 90)
    {
        c = sqrt(pow(b,2) + pow(a,2));
        ui->label_4->clear();
        ui->label_4->setText(ui->label_4->text() + "Третья сторона равна: " + QString::number(c));
    }


}

void MainWindow::on_pushButton_3_clicked()
{
    QString text;
    text = ui->textEdit->toPlainText();
    ui->textEdit_2->append(text);
}


void MainWindow::on_pushButton_4_clicked()
{
    QString text;
    text = ui->textEdit->toPlainText();
    ui->textEdit_2->clear();
    ui->textEdit_2->append(text);
}


void MainWindow::on_pushButton_5_clicked()
{
    QString text;
    text = "<font color='red'>Hello</font>";
    ui->textEdit_2->clear();
    ui->textEdit_2->append(text);
}

