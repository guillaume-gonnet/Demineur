#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
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

signals:
    void boxClicked();

private:
    Ui::MainWindow *ui;
    void createGrid();
    std::vector<std::vector<Box*>> boxList;
    int m_nbCol;
    int m_nbLine;
    int m_nbMines;
    QAction *actionClickBox = nullptr;
};
#endif // MAINWINDOW_H
