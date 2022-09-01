#ifndef BOXGRID_H
#define BOXGRID_H

#include "box.h"
#include <QObject>


class BoxGrid: public QObject
{
    Q_OBJECT

public:
    BoxGrid();
    ~BoxGrid();
    Box* getBox(int x,int y) {return m_boxList[x][y];};
    int getNbLine() {return m_nbLine;};
    void setNbLine(int nb) {m_nbLine=nb;};
    int getNbCol() {return m_nbCol;};
    void setNbCol(int nb) {m_nbCol=nb;};
    void setNbMines(int nb) {m_nbMines=nb;};
    int getNbMinesAround(Box*);

public slots:
    void clickLeftBox(Box*);
    void clickRightBox(Box*);

private:
    void createBoxGrid();
    QVector<QVector<Box*>> m_boxList;
    int m_nbCol;
    int m_nbLine;
    int m_nbMines;
    int m_remainBox;
    int m_remainFlag;
    void createMines(QVector<QVector<Box*>> boxList, int nbMines);

signals:
    void gameEnded(QString);
};

#endif // BOXGRID_H
