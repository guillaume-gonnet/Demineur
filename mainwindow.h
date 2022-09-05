#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include "boxgrid.h"
#include <QLabel>
#include <QTime>
#include <QTimer>

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
    void on_actionGrid_Size_triggered();
    void on_actionSave_triggered();
    void on_actionLoad_triggered();

private:
    Ui::MainWindow *ui;
    BoxGrid *m_boxGrid;
    QLabel *labelMines;
    QLabel *labelTimer;
    QTime time;
    QTimer *timer;
    void createGrid();
    void endGame(QString);
    void updateOptions(int wide, int height, int mines);
    void createStatusBar();
    void updateStatusMines();
    void updateStatusTimer();

};
#endif // MAINWINDOW_H
