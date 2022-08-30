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
    int getNbCol() {return m_nbCol;};
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
    int m_nbFlag;
    int m_remainBox;
    void createMines(QVector<QVector<Box*>> boxList, int nbMines);
    void endGame();

signals:
    void gameEnded(QString);
};

#endif // BOXGRID_H
