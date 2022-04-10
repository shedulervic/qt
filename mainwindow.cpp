#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QTextCodec>
#include <QRegExp>


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




void MainWindow::on_pushButton_Open_clicked()
{
    auto filter = trUtf8("Текстовый файл(*.txt) ;; Заголовочный файл(*.h) ;; cpp файл(*.cpp) ");
    QString s = QFileDialog::getOpenFileName(this, "Заголовок окна",
    QDir::current().path(), filter);
    if (s.length() > 0)
    {
    QFile file(s);
    if (file.open(QFile::ReadOnly | QFile::ExistingOnly))
    {
    QTextStream stream(&file);
    ui->plainTextEdit->setPlainText(stream.readAll());
    file.close();
    }
    }
}


void MainWindow::on_pushButton_Save_clicked()
{
    auto filter = trUtf8("Текстовый файл(*.txt) ;; Заголовочный файл(*.h) ;; cpp файл(*.cpp) ");
    QString s = QFileDialog::getSaveFileName(this, "Заголовок окна",
    QDir::current().path(), filter);

    if (s.length() > 0)
    {
    QFile file(s);
    if (file.open(QFile::WriteOnly | QFile::NewOnly))
    {
    QTextStream stream(&file);
    stream << ui->plainTextEdit->toPlainText();
    file.close();
    }
    }

}


void MainWindow::on_pushButton_Help_clicked()
{
    QFile file (":/about");

    QTextStream stream(&file);
if (file.open(QIODevice::ReadOnly)){
 QByteArray str = file.readAll();
    QMessageBox msgBox;
   msgBox.setText(str);
   msgBox.exec();
}
}


// Первоночальная попытка распарсить хтмл регуляркой была смелой...
//к счатью обошелся так, получилось корявенько но к сожаления через 7 часов на работу

void MainWindow::on_pushButtonOpen_clicked()
{
  QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    auto filter = trUtf8("html файл(*.html)");
    QString s = QFileDialog::getOpenFileName(this, "Заголовок окна",
    QDir::current().path(), filter);
    if (s.length() > 0)
    {
    QFile file(s);
    if (file.open(QFile::ReadOnly | QFile::ExistingOnly))
    {
    QTextStream stream(&file);
    QString text;
    while (!stream.atEnd()){
        text = stream.readLine();
        if(text.contains("weather__description svelte-16a8jo"))
            break;
    }

    int pos = text.indexOf("<a target=\"_blank\" class=\"weather__block weather__block_base svelte-16a8jo\"");
    int endPos = text.indexOf("<div class=\"rate__diff svelte-1nen9jy rate__diff_negative\">", pos);
    QString subStr = text.mid(pos, endPos - pos);
    ui->textEdit->toHtml();
    ui->textEdit->setHtml(subStr);
    file.close();
    }
    }
}

