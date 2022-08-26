#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
#include "boxgrid.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    boxgridnew = new BoxGrid();
    createGrid();

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

