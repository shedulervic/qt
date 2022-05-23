#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QTextEdit>
#include <QFileDialog>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QMdiSubWindow>
#include <QDate>
#include <QTime>

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
    QTextEdit *tedit ;

    // каст переписал :)
    tedit = qobject_cast<QTextEdit*>(ui->mdiArea->activeSubWindow()->widget());

    QPrinter printer;
    QPrintDialog dlg(&printer, this);
    dlg.setWindowTitle("Print");
    if (dlg.exec() != QDialog::Accepted)
    return;
    tedit->print(&printer);

}

// первое задание
void MainWindow::on_dataButton_clicked()
{
    QTextEdit *tedit ;
    tedit = qobject_cast<QTextEdit*>(ui->mdiArea->activeSubWindow()->widget());

    QDate date = QDate::currentDate();
    const QString month[] = {" ", " января " , " февраля ", " марта ",
    " апреля ", " мая ", " июня ",
    " июля ", " августа ", " сентября ",
    " октября ", " ноября ", " декабря ",
    }; // Месяцы отсчитываются от 1, поэтому первый
    // элемент - пустая строка

    QString dstr = QString::number(date.day()) + month[date.month()] +
    QString::number(date.year());
    setWindowTitle(dstr);
    QTime time = QTime::currentTime();
    QString dt = QString::number(date.day()) + month[date.month()] +
            QString::number(date.year()) + " Время: " + QString::number(time.hour()) +
            ":" + QString::number(time.minute());
    QTextCursor cursor(tedit->textCursor());
    cursor.insertText(" " + dt + " ");
}

