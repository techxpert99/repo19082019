/**
  * @file mainwindow.h
  * @author Ritik Jain
  * @date 25/08/2019
  * @brief The Main Window Headers File
  */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dictionary.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Dictionary DICT;

private slots:
    void on_word_textChanged();
    void on_search_clicked();

private:
    Ui::MainWindow *ui;
    bool ignore_sig=0;
};

#endif // MAINWINDOW_H
