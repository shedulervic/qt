#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileSystemModel>


// ://dark

static auto fileModel = new QFileSystemModel;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox_theme->addItems(QStringList() << "Light" << "Dark");

    fileModel->setRootPath(QDir::rootPath());
            ui->centralwidget->findChild<QTreeView*>("treeView")->setModel(fileModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
     ui->lineEdit->setText(fileModel->fileInfo(ui->treeView->currentIndex()).absolutePath());


}


// qss сам писать поленился, скачал отсюда: https://qss-stock.devsecstudio.com/templates.php

void MainWindow::on_comboBox_theme_currentIndexChanged(int index)
{
    if (index == 0){QFile file(":/Medize");
        file.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(file.readAll());
        setStyleSheet(styleSheet);
    } else{QFile file(":/Darkeum");
        file.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(file.readAll());
        setStyleSheet(styleSheet);
    }
    }

