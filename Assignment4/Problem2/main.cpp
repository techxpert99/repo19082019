/**
  * @file main.cpp
  * @author Ritik Jain
  * @date 29/08/2019
  * @brief The Main File
  */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
