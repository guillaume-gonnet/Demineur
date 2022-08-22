#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "box.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void createGrid();
    std::vector<std::vector<Box*>> boxList;
    int nbCol;
    int nbLine;
    int nbMines;
};
#endif // MAINWINDOW_H
