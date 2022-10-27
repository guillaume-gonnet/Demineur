#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include "boxgrid.h"
#include "optiondialog.h"
#include "mysettings.h"
#include "scoresdialog.h"
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_boxGrid = new BoxGrid();
    m_timer = new QTimer(this);
    m_time = QTime(0,0);
    m_scoreCard = new ScoreCard();
    launchGame();
}

MainWindow::~MainWindow()
{
    delete m_labelMines;
    delete m_labelTimer;
    delete m_scoreCard;
    delete m_boxGrid;
    delete m_timer;
    delete ui;
}

void MainWindow::launchGame()
{
    if(m_boxGrid!=nullptr)
        delete m_boxGrid;
    m_boxGrid = new BoxGrid();
    createGrid();
    createStatusBar();
    connect(m_boxGrid,&BoxGrid::statusBarUpdate,this,&MainWindow::updateStatusMines);
    connect(m_boxGrid,&BoxGrid::timerStart,this,&MainWindow::timerStart);
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

void MainWindow::createStatusBar()
{
    m_labelMines = new QLabel(this);
    m_labelTimer = new QLabel(this);
    updateStatusMines();
    ui->statusbar->addPermanentWidget(m_labelMines,1);
    connect(m_boxGrid,&BoxGrid::statusBarUpdate,this,&MainWindow::updateStatusMines);

    connect(m_timer, &QTimer::timeout, this, &MainWindow::updateStatusTimer);
    m_labelTimer->setText(m_time.toString("hh : mm : ss"));
    ui->statusbar->addPermanentWidget(m_labelTimer,1);
}

void MainWindow::updateStatusMines()
{
    QString str = QString("Nb mines: %1/%2").arg(m_boxGrid->getNbFlags()).arg(m_boxGrid->getNbMines());
    m_labelMines->setText(str);
}

void MainWindow::updateStatusTimer()
{
    m_time = m_time.addSecs(1);
    m_labelTimer->setText(m_time.toString("hh : mm : ss"));
}

void MainWindow::endGame(const QString msg)
{
    m_timer->stop();
    QMessageBox msgBox;
    if(msg=="win")
    {
        msgBox.setText("You win!");
        //TODO: define std size of grid


        Score score = {"Small",m_time.second(),"tmp"};
        if(m_scoreCard->isTop10(score))
        {
            //Open input dialog to get name
            bool ok;
            QString name = QInputDialog::getText(this, tr("Enter your name"),
                                                 tr("You made it in Top 10! Enter your name"), QLineEdit::Normal,
                                                 "name", &ok);
            score.setName(name);
            m_scoreCard->addScore(score);
            m_scoreCard->saveScores();
        }
    }
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
        connect(m_boxGrid,&BoxGrid::statusBarUpdate,this,&MainWindow::updateStatusMines);
        connect(m_boxGrid,&BoxGrid::timerStart,this,&MainWindow::timerStart);
        createGrid();
        updateStatusMines();
        m_time = QTime(0,0);
        m_labelTimer->setText(m_time.toString("hh : mm : ss"));
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
    m_boxGrid = new BoxGrid();
    connect(m_boxGrid,&BoxGrid::statusBarUpdate,this,&MainWindow::updateStatusMines);
    connect(m_boxGrid,&BoxGrid::timerStart,this,&MainWindow::timerStart);
    createGrid();
}

void MainWindow::on_actionExit_triggered()
{
    qApp->exit();
}

void MainWindow::on_actionEasy_triggered()
{
    updateOptions(5,5,4);
}

void MainWindow::on_actionMedium_triggered()
{
    updateOptions(10,10,25);
}

void MainWindow::on_actionHard_triggered()
{
    updateOptions(15,15,75);
}

void MainWindow::on_actionCustom_triggered()
{
    OptionDialog optDialog(this, m_boxGrid->getWide(),m_boxGrid->getHeight(),m_boxGrid->getNbMines());
    OptionDialog *p_optDialog = &optDialog;
    connect(p_optDialog,&OptionDialog::accepted,this,&MainWindow::updateOptions);
    optDialog.setModal(true);
    optDialog.exec();
}

void MainWindow::on_actionBest_Scores_triggered()
{
    ScoresDialog *scoresDialog = new ScoresDialog();
    scoresDialog->setModal(true);
    scoresDialog->exec();
    delete scoresDialog;
}

void MainWindow::updateOptions(const int wide, const int height, const int mines)
{
    delete m_boxGrid;
    m_boxGrid=new BoxGrid(wide,height,mines);
    updateStatusMines();
    connect(m_boxGrid,&BoxGrid::statusBarUpdate,this,&MainWindow::updateStatusMines);
    connect(m_boxGrid,&BoxGrid::timerStart,this,&MainWindow::timerStart);
    createGrid();
}

void MainWindow::on_actionSave_triggered()
{
    MySettings mySettings;
    mySettings.saveSettings(*m_boxGrid);
}

void MainWindow::on_actionLoad_triggered()
{
    delete m_boxGrid;
    MySettings mySettings;
    m_boxGrid = mySettings.loadSettings();
    connect(m_boxGrid,&BoxGrid::statusBarUpdate,this,&MainWindow::updateStatusMines);
    connect(m_boxGrid,&BoxGrid::timerStart,this,&MainWindow::timerStart);
    createGrid();
}

void MainWindow::timerStart()
{
    m_timer->start(1000);
}
