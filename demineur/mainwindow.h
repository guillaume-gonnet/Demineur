#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QLabel>
#include <QTime>
#include <QTimer>
#include <QMap>
#include "boxgrid.h"
#include "scorecard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();
    void on_actionExit_triggered();
    void on_actionHard_triggered();
    void on_actionMedium_triggered();
    void on_actionEasy_triggered();
    void on_actionCustom_triggered();
    void on_actionSave_triggered();
    void on_actionLoad_triggered();
    void on_actionBest_Scores_triggered();
    void timerStart();

private:
    Ui::MainWindow *ui;
    BoxGrid *m_boxGrid;
    QLabel *m_labelMines;
    QLabel *m_labelTimer;
    QTime m_time;
    QTimer *m_timer;
    ScoreCard *m_scoreCard;
    void createGrid();
    void endGame(QString);
    void updateOptions(int wide, int height, int mines);
    void createStatusBar();
    void updateStatusMines();
    void updateStatusTimer();
    void launchGame();

};
#endif // MAINWINDOW_H
