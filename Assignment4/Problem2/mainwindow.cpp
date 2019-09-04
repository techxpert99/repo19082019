/**
  * @file mainwindow.cpp
  * @author Ritik Jain
  * @date 29/08/2019
  * @brief The Main Window
  */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->text->setReadOnly(1);
    ui->gen->setAutoFillBackground(1);
    ui->gen->setStyleSheet("background-color : rgb(0,255,0) ; color : rgb(0,0,0)");
    ui->gen->update();
    ui->clear->setAutoFillBackground(1);
    ui->clear->setStyleSheet("background-color : rgb(0,255,0) ; color : rgb(0,0,0)");
    ui->clear->update();
    ui->n->setAutoFillBackground(1);
    ui->n->setStyleSheet("background-color : rgb(0,0,0) ; color : rgb(255,0,0)");
    ui->n->update();
    ui->nsln->setStyleSheet("color:rgb(0,255,255);");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print(QString s)
{
    QString html = ui->text->toHtml();
    html = html.append(s);
    ui->text->setHtml(html);
}

void MainWindow::on_gen_clicked()
{
    QString _n = ui->n->text();
    unsigned int N = _n.toInt();

    QP = new QueensProblem(N);
    QP->solve();
    Solution **s = QP->getSolutions();
    unsigned int ns = QP->countSolutions();

    ui->nsln->setText(QString::number(ns).append(" Solution/s !"));

    if(!s) return;

    unsigned int j;
    unsigned int* loc = nullptr;
    unsigned int min_sz = 10;

    QString txt="<body width='600px' height='600px'>";

    for(j = 0; j < ns; j++)
    {
        loc = s[j]->sln();
        int k;
        unsigned int l;
        unsigned int tmp=(N*30)/6;
        if(tmp<min_sz) tmp = min_sz;

        txt.append("<table border='2' width='");
        txt.append(QString::number(tmp));
        txt.append("%' style='margin-bottom:10px; margin-right:10px;margin-left:10px;margin-top:10px;float:left;'>");

        for(k=N-1; k >= 0; k--)
        {
            txt.append("<tr>");
            for(l=0; l < N; l++)
            {
                if(l==loc[k])
                    txt.append("<td style='color:rgb(255,0,0);'> 1 </td>");
                else
                    txt.append("<td> 0 </td>");
            }
            txt.append("</tr>");
        }

        txt.append("</table>");
    }
    txt.append("</body>");

    print(txt);

    delete [] s;
    delete loc;
    delete QP;
}

void MainWindow::on_n_textChanged(const QString &arg1)
{
    if(ignore)
        return;

    ignore = 1;

    QString _n = ui->n->text();
    int j;
    for(j=0; j <_n.length(); j++)
        if(_n.data()[j]<'0' || _n.data()[j]>'9')
            _n.remove(j,1);
    ui->n->setText(_n);

    ignore = 0;
}

void MainWindow::on_clear_clicked()
{
    ui->text->clear();
}
