/**
  *
  * @author Ritik Jain
  * @date 25/08/2019
  * @file main.cpp
  * @brief Dictionary File
  *
  */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dictionary DICT;
    char* dict_file = QCoreApplication::applicationDirPath().append("/dictionary/dictionary.csv").toLocal8Bit().data();
    DICT.load(dict_file);
    MainWindow w;
    w.DICT = DICT;
    w.show();
    return a.exec();
}
