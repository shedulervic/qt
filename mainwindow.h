#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QShortcut>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void changeEvent(QEvent * event);

private slots:
    void on_comboBox_lang_currentIndexChanged(int index);

    void on_pushButton_Open_clicked();

    void on_pushButton_Save_clicked();

    void on_pushButton_Help_clicked();

    void on_comboBox_mode_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
     QTranslator qtLanguageTranslator;
     QShortcut *keyOpen;
     QShortcut *keySave;
     QShortcut *keyNew;
     QShortcut *keyQuit;
};
#endif // MAINWINDOW_H
