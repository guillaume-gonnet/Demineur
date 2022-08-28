#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include "boxgrid.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    boxgridnew = new BoxGrid();
    createGrid();
    connect(boxgridnew,&BoxGrid::gameEnded,this, &MainWindow::endGame);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createGrid()
{
    for(int i=0;i<boxgridnew->getNbCol();i++)
    {
        for(int j=0;j<boxgridnew->getNbLine();j++)
        {
            Box* box = boxgridnew->getBox(i,j);
            ui->gridLayout->addWidget(box,i,j);
        }
    }
}

void MainWindow::endGame(QString msg)
{
    QMessageBox message;
    if(msg=="win")
        message.setText("Gagne!");
    if(msg=="lost")
        message.setText("Perdu!");
    message.exec();
}

