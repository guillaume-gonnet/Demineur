#include "boxgrid.h"
#include <QMessageBox>

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
            Box::connect(box, &QToolButton::clicked, this, [this, box] {clickLeftBox(box);});
        }
        m_boxList.push_back(tmp);
    }
}



void BoxGrid::createMines(std::vector<std::vector<Box*>> boxList, int nbMines)
{
    //TODO: generate random Mines
    boxList[3][2]->setMine();
}

void BoxGrid::clickLeftBox(Box* box)
{
    if(box->isMine())
    {
        box->changeDisplay(QColor("red"),0);
        QMessageBox message;
        message.setText("Perdu!");
        message.exec();
        //TODO: implement final screen Replay?

    } else {
        box->setStyleSheet("QToolButton {"
                            "background-color: dark_grey"
                            "}");

        box->changeDisplay(QColor("black"), getNbMinesAround(box));
        discoverBox();
    }
}

int BoxGrid::getNbMinesAround(Box* box)
{
    int counter =0;
    Box::Coordinates coordinate = box->getCoordinates();
    QVector<Box*> listBoxes;
    if(coordinate.x-1>=0 && coordinate.y-1>=0)
        listBoxes.push_back(getBox(coordinate.x-1,coordinate.y-1));
    if(coordinate.x-1>=0)
        listBoxes.push_back(getBox(coordinate.x-1,coordinate.y));
    if(coordinate.x-1>=0 && coordinate.y+1<=m_nbLine)
        listBoxes.push_back(getBox(coordinate.x-1,coordinate.y+1));
    if(coordinate.y-1>=0)
        listBoxes.push_back(getBox(coordinate.x,coordinate.y-1));
    if(coordinate.y+1<=m_nbLine)
        listBoxes.push_back(getBox(coordinate.x,coordinate.y+1));
    if(coordinate.x+1<=m_nbCol && coordinate.y-1>=0)
        listBoxes.push_back(getBox(coordinate.x+1,coordinate.y-1));
    if(coordinate.x+1<=m_nbCol)
        listBoxes.push_back(getBox(coordinate.x+1,coordinate.y));
    if(coordinate.x+1<=m_nbCol && coordinate.y+1<=m_nbLine)
        listBoxes.push_back(getBox(coordinate.x+1,coordinate.y+1));

    for(auto b : listBoxes)
    {
        if(b->isMine())
            counter++;
    }
    return counter;
}

void BoxGrid::discoverBox()
{
//TODO: check all box nearby with 0 mine around
}
