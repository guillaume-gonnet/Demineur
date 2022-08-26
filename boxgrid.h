#ifndef BOXGRID_H
#define BOXGRID_H

#include "box.h"

class BoxGrid : public QObject
{
public:
    BoxGrid();
    Box* getBox(int x,int y) {return m_boxList[x][y];};
    int getNbLine() {return m_nbLine;};
    int getNbCol() {return m_nbCol;};
    int getNbMinesAround(Box*);
    void discoverBox();

public slots:
    void clickLeftBox(Box*);

private:
    void createBoxGrid();
    std::vector<std::vector<Box*>> m_boxList;
    int m_nbCol;
    int m_nbLine;
    int m_nbMines;
    void createMines(std::vector<std::vector<Box*>> boxList, int nbMines);
};

#endif // BOXGRID_H
