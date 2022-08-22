#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "box.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    nbCol=8;
    nbLine=8;
    nbMines=10;
    createGrid();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createGrid()
{
    for(int i=0;i<nbLine;i++)
    {
        std::vector<Box*> tmp;

        for(int j=0;j<nbCol;j++)
        {
            tmp.push_back(new Box());
        }
        boxList.push_back(tmp);
    }
    for(int i=0;i<nbLine;i++)
    {
        for(int j=0;j<nbCol;j++)
        {
              ui->gridLayout->addWidget(boxList[i][j],i,j);
        }
    }
}
