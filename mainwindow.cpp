#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "box.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_nbCol=8;
    m_nbLine=8;
    m_nbMines=10;
    createGrid();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createGrid()
{
    for(int i=0;i<m_nbLine;i++)
    {
        std::vector<Box*> tmp;

        for(int j=0;j<m_nbCol;j++)
        {
            Box *box = new Box();
            QString str = "Box%1%2";
//            str.arg(i).arg(j);
//            box->setObjectName(str);
            tmp.push_back(box);
        }
        m_boxList.push_back(tmp);
    }
    for(int i=0;i<m_nbLine;i++)
    {
        for(int j=0;j<m_nbCol;j++)
        {
            Box *box = m_boxList[i][j];
            ui->gridLayout->addWidget(box,i,j);
        }
    }
    createMines(m_boxList,m_nbMines);
}

void MainWindow::createMines(std::vector<std::vector<Box*>> boxList, int nbMines)
{
    //TODO: generate random Mines
    boxList[0][0]->setMine();
}
