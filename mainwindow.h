#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include <QTextEdit>


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


    void on_openButton_clicked();


    void on_Print_clicked();

    void on_dataButton_clicked();

private:
    Ui::MainWindow *ui;
    QMdiArea *mdiArea;
QTextEdit *curEdit;
};
#endif // MAINWINDOW_H
