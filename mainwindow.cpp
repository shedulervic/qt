#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QTextEdit>
#include <QFileDialog>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QMdiSubWindow>

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


void MainWindow::on_openButton_clicked()
{
        QWidget *widget = new QWidget(ui->mdiArea);
        QGridLayout *gridlayout = new QGridLayout(widget);
        widget->setLayout(gridlayout);
        QTextEdit *textEdit = new QTextEdit();
        gridlayout->addWidget(textEdit);
        textEdit->resize(QSize(200,200));
        textEdit->setWindowTitle("Undecided");
        ui->mdiArea->addSubWindow(textEdit);


         textEdit->show();

}





void MainWindow::on_Print_clicked()
{
    QMdiSubWindow *activSubWindow =ui->mdiArea->activeSubWindow();
    QWidget *widg = activSubWindow->widget();
    QTextEdit *tedit = (QTextEdit*)widg;
    QPrinter printer;
    QPrintDialog dlg(&printer, this);
    dlg.setWindowTitle("Print");
    if (dlg.exec() != QDialog::Accepted)
    return;
    tedit->print(&printer);

}

