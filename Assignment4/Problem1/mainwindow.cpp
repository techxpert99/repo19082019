/**
  *
  * @author Ritik Jain
  * @date 25/08/2019
  * @file mainwindow.cpp
  * @brief Dictionary File
  *
  */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dictionary.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->meaning->setReadOnly(1);
    ui->search->setAutoFillBackground(1);
    ui->search->setStyleSheet("background-color: rgb(0, 255, 0); color: rgb(0, 0, 0)");
    ui->search->update();
    this->setFixedSize(this->size());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_word_textChanged()
{
    if(ignore_sig)
        return;

    ignore_sig = 1;

    QString text = ui->word->toPlainText();

    QChar *data = text.data();
    int len = text.length();

    for(int i=0; i < len; i++)
        if(data[i]<'A' || data[i]>'z' || (data[i]>'Z' && data[i]<'a'))
            text.remove(i,1);

    ui->word->setText(text);

    QTextCursor c = ui->word->textCursor();
    c.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, text.length());
    ui->word->setTextCursor(c);

    ignore_sig = 0;
}

void MainWindow::on_search_clicked()
{
    char* word = ui->word->toPlainText().toLocal8Bit().data();
    char* mean = DICT.search(word);

    if(mean)
        ui->meaning->setText(QString(mean));
    else
        ui->meaning->setText("----- Error : Word Not Found !!! -----");
}
