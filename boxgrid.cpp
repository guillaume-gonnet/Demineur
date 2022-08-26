#include "boxgrid.h"

BoxGrid::BoxGrid()
{
    m_nbLine=5;
    m_nbCol=5;
    m_nbMines=1;
    createBoxGrid();
    createMines(m_boxList,m_nbMines);
}

void BoxGrid::createBoxGrid()
{
    for(int i=0;i<m_nbLine;i++)
    {
        std::vector<Box*> tmp;

        for(int j=0;j<m_nbCol;j++)
        {
            Box *box = new Box();
            box->setCoordinates(i,j);
            tmp.push_back(box);
        }
        m_boxList.push_back(tmp);
    }
}



void BoxGrid::createMines(std::vector<std::vector<Box*>> boxList, int nbMines)
{
    //TODO: generate random Mines
    boxList[0][0]->setMine();
}

void BoxGrid::discoverBox()
{

}
