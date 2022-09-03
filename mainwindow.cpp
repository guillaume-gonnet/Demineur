#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include "boxgrid.h"
#include "optiondialog.h"
#include "settings.h"

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
    for(int i=0;i<m_boxGrid->getHeight();i++)
    {
        for(int j=0;j<m_boxGrid->getWide();j++)
        {
            Box* box = m_boxGrid->getBox(i,j);
            ui->gridLayout->addWidget(box,i,j);
        }
    }
    connect(m_boxGrid,&BoxGrid::gameEnded,this, &MainWindow::endGame);
}

void MainWindow::endGame(const QString msg)
{
    QMessageBox msgBox;
    if(msg=="win")
        msgBox.setText("You win!");
    if(msg=="lost")
        msgBox.setText("You lost!");
    msgBox.setInformativeText("Do you want to replay?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    const int resp = msgBox.exec();
    switch (resp)
    {
    case QMessageBox::Yes :
    {
        const int wide = m_boxGrid->getWide();
        const int height = m_boxGrid->getHeight();
        const int mines = m_boxGrid->getNbMines();
        delete m_boxGrid;
        m_boxGrid=new BoxGrid(wide,height,mines);
        createGrid();
        break;
    }
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
    OptionDialog optDialog(this, m_boxGrid->getWide(),m_boxGrid->getHeight(),m_boxGrid->getNbMines());
    OptionDialog *p_optDialog = &optDialog;
    connect(p_optDialog,&OptionDialog::accepted,this,&MainWindow::updateOptions);
    optDialog.setModal(true);
    optDialog.exec();
}

void MainWindow::updateOptions(const int wide, const int height, const int mines)
{
    delete m_boxGrid;
    m_boxGrid=new BoxGrid(wide,height,mines);
    createGrid();
}

void MainWindow::on_actionSave_triggered()
{
    MySettings mySettings;
    mySettings.saveSettings(*m_boxGrid);
}

