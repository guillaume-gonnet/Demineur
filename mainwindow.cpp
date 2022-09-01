#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include "boxgrid.h"
#include "optiondialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_boxGrid = new BoxGrid();
    createGrid();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createGrid()
{
    for(int i=0;i<m_boxGrid->getNbCol();i++)
    {
        for(int j=0;j<m_boxGrid->getNbLine();j++)
        {
            Box* box = m_boxGrid->getBox(i,j);
            ui->gridLayout->addWidget(box,i,j);
        }
    }
    connect(m_boxGrid,&BoxGrid::gameEnded,this, &MainWindow::endGame);
}

void MainWindow::endGame(QString msg)
{
    QMessageBox msgBox;
    if(msg=="win")
        msgBox.setText("You win!");
    if(msg=="lost")
        msgBox.setText("You lost!");
    msgBox.setInformativeText("Do you want to replay?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int resp = msgBox.exec();
    switch (resp)
    {
    case QMessageBox::Yes :
        delete m_boxGrid;
        m_boxGrid=new BoxGrid();
        createGrid();
        break;
    case QMessageBox::No :
        qApp->exit();
    }
}


void MainWindow::on_actionNew_triggered()
{
    if(m_boxGrid)
        delete m_boxGrid;
    m_boxGrid=new BoxGrid();
    createGrid();
}


void MainWindow::on_actionExit_triggered()
{
    qApp->exit();
}


void MainWindow::on_actionGrid_Size_triggered()
{
    OptionDialog optDialog;
    optDialog.setModal(true);
    optDialog.exec();
}

