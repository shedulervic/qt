#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QStringListModel>
#include <QStandardItem>
#include <QString>
#include <QColor>

static const QStringList LIST_ITEMS = QStringList() << "C++" << "Python" << "Java" << "C#" << "PHP" << "JavaScript";
static auto itemModel = new QStandardItemModel();
static auto tableModel = new QStandardItemModel();
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



ui->listView->setIconSize(QSize(32, 32));

//task 2
    foreach(const QString& item, LIST_ITEMS){
        ui->listView->setModel(itemModel);
        itemModel->appendRow(new QStandardItem(QIcon(":/" + item), item));
    }

  //task 3
    QStringList labels = QObject::trUtf8("Название, IP, MAC").simplified().split(",");
    tableModel->setHorizontalHeaderLabels(labels);

    ui->tableView->setModel(tableModel);
    ui->tableView->show();
    tableModel->appendRow({new QStandardItem("PC1"), new QStandardItem("192.168.1.100"), new QStandardItem("F0:98:9D:00:00:00")});
    tableModel->appendRow({new QStandardItem("PC2"), new QStandardItem("192.168.1.101"), new QStandardItem("F0:98:9D:00:00:0d")});
    tableModel->appendRow({new QStandardItem("PC3"), new QStandardItem("192.168.1.102"), new QStandardItem("F0:98:9D:00:00:0c")});
    tableModel->appendRow({new QStandardItem("PC4"), new QStandardItem("192.168.1.103"), new QStandardItem("F0:98:9D:00:00:0e")});






}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1){
        ui->listView->setViewMode(QListView::ListMode);
    }
    else {
         ui->listView->setViewMode(QListView::IconMode);
    }

}


void MainWindow::on_pushButton_Delete_clicked()
{
QItemSelectionModel *selectModel = ui->listView->selectionModel();

if (selectModel != NULL){
    itemModel->clearItemData(selectModel->currentIndex());
}
}


void MainWindow::on_pushButton_Up_clicked()
{
    QItemSelectionModel *selectModel = ui->listView->selectionModel();
    if (selectModel != NULL){
        auto selectedRow = itemModel->takeRow(selectModel->currentIndex().row());
        if(selectModel->currentIndex().row() == 0){
            itemModel->appendRow(selectedRow);
        }
        itemModel->insertRow(selectModel->currentIndex().row() - 1, selectedRow);
    }
}


void MainWindow::on_pushButtonDown_clicked()
{
    QItemSelectionModel *selectModel = ui->listView->selectionModel();
    if (selectModel != NULL){
        auto selectedRow = itemModel->takeRow(selectModel->currentIndex().row());
        if(itemModel->rowCount() > selectModel->currentIndex().row() - 1){
            itemModel->insertRow(0, selectedRow);
            // тут какая то фигня с тем что остается пустая строка, и поясните если можно как перебросить селект на вьюхе в новую позицию
        }
        itemModel->insertRow(selectModel->currentIndex().row() + 1, selectedRow);
    }

}



void MainWindow::on_pushButton_clicked()
{
    QModelIndexList selectedList= ui->tableView->selectionModel()->selectedIndexes();
    QModelIndex index;
    QBrush green;
    green.setColor(Qt::green);
    foreach (index, selectedList){
        //и я так и не понял почему не работает ((
                tableModel->setData(index, green, Qt::BackgroundRole);
    }

    }






