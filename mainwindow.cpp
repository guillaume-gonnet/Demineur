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
            str.arg(i).arg(j);
            box->setObjectName(str);
            tmp.push_back(box);
        }
        boxList.push_back(tmp);
    }
    for(int i=0;i<m_nbLine;i++)
    {
        for(int j=0;j<m_nbCol;j++)
        {
            Box *box = boxList[i][j];
            ui->gridLayout->addWidget(box,i,j);
            actionClickBox = new QAction(tr("&click box"), this);
            //connect(actionClickBox,&QAction::triggered,this, &Box::isCheckedEmpty);


        }
    }
}
