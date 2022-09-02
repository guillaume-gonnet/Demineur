#ifndef BOXGRID_H
#define BOXGRID_H

#include "box.h"
#include <QObject>


class BoxGrid: public QObject
{
    Q_OBJECT

public:
    BoxGrid(int wide = 5, int height = 5, int mines = 5);
    ~BoxGrid();
    Box* getBox(const int x,const int y) {return m_boxList[x][y];};
    int getHeight() {return m_height;};
    void setHeight(const int nb) {m_height=nb;};
    int getWide() {return m_wide;};
    void setWide(const int nb) {m_wide=nb;};
    int getNbMines() {return m_mines;}
    void setNbMines(const int nb) {m_mines=nb;};
    int getNbMinesAround(Box*);

public slots:
    void clickLeftBox(Box*);
    void clickRightBox(Box*);

private:
    void createBoxGrid();
    QVector<QVector<Box*>> m_boxList;
    int m_wide;
    int m_height;
    int m_mines;
    int m_remainBox;
    int m_remainFlag;
    void createMines();

signals:
    void gameEnded(const QString);
};

#endif // BOXGRID_H
