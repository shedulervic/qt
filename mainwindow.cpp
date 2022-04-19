#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QTextCodec>
#include <QShortcut>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox_lang->addItems(QStringList() << "ru_RU" << "en_US");
    ui->comboBox_mode->addItems(QStringList() << "rw" << "read");

    QSettings *settings = new QSettings("settings.conf",QSettings::IniFormat);
         settings->setValue("function/Open", "ctrl+O");
         settings->setValue("function/Save", "ctrl+S");
         settings->setValue("function/New", "ctrl+N");
         settings->setValue("function/Quit", "ctrl+Q");
         settings->sync();

         QSettings *settings2 = new QSettings("settings.conf",QSettings::IniFormat);
         QStringList sett = QStringList() << settings2->value("function/Open",5).toString() <<  settings2->value("function/Save",5).toString()
                                          << settings2->value("function/New",5).toString() << settings2->value("function/Quit",5).toString();
    ui->listWidget->addItems(sett);

    keyOpen = new QShortcut(this);
    keySave = new QShortcut(this);
    keyNew = new QShortcut(this);
    keyQuit = new QShortcut(this);
    keyOpen->setKey(settings2->value("function/Open",5).toString());
    keySave->setKey(settings2->value("function/Save",5).toString());
    keyNew->setKey(settings2->value("function/New",5).toString());
    keyQuit->setKey(settings2->value("function/Quit",5).toString());

    connect(keyOpen, SIGNAL(activated()), this, SLOT(on_pushButton_Open_clicked()));
    connect(keySave, SIGNAL(activated()), this, SLOT(on_pushButton_Save_clicked()));
}



QString engHelp = "Some help";
QString ruHelp = "Какая-то помощь";
QString help;




void MainWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
    ui->retranslateUi(this);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// пол дня убил пока не понял ччто qm файлы надо в папку сборки подкинуть, иначе не работает))
void MainWindow::on_comboBox_lang_currentIndexChanged(int index)
{
    if (index == 0){qtLanguageTranslator.load(QString("QtLanguage_") + QString("ru")); help = ruHelp;}
            else{qtLanguageTranslator.load(QString("QtLanguage_") + QString("en")); help = engHelp;}
            qApp->installTranslator(&qtLanguageTranslator);
}

void MainWindow::on_comboBox_mode_currentIndexChanged(int index)
{
    if (index == 0){ui->plainTextEdit->setReadOnly(false);}
    else{ui->plainTextEdit->setReadOnly(true);}
}

void MainWindow::on_pushButton_Open_clicked()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
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

// топорно но время поджимало... смеркалось
void MainWindow::on_pushButton_Help_clicked()
{
    QMessageBox msgBox;
    msgBox.setText(help);
     msgBox.exec();
}




