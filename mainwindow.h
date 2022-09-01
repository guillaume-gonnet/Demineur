#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include "boxgrid.h"

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

private:
    Ui::MainWindow *ui;
    BoxGrid *m_boxGrid;
    void createGrid();
    void endGame(QString);
};
#endif // MAINWINDOW_H
