/**
  * @file mainwindow.h
  * @author Ritik Jain
  * @date 29/08/2019
  * @brief Main Window Headers File
  */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "queensproblem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_gen_clicked();

    void on_clear_clicked();

    void on_n_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QueensProblem *QP = nullptr;
    bool ignore = 0;
    void print(QString s);
};

#endif // MAINWINDOW_H
