#include "boxgrid.h"
#include <QMessageBox>
#include <QRandomGenerator>
#include <QDateTime>

QRandomGenerator gene = QRandomGenerator(QDateTime::currentMSecsSinceEpoch());

BoxGrid::BoxGrid()
{
    m_nbLine=7;
    m_nbCol=7;
    m_nbMines=5;
    createBoxGrid();
    createMines(m_boxList,m_nbMines);
}


void BoxGrid::createBoxGrid()
{
    for(int i=0;i<m_nbLine;i++)
    {
        QVector<Box*> tmp;

        for(int j=0;j<m_nbCol;j++)
        {
            Box *box = new Box();
            box->setCoordinates(i,j);
            tmp.push_back(box);
            Box::connect(box, &Box::leftClicked, this, [this, box] {clickLeftBox(box);});
            Box::connect(box, &Box::rightClicked, this, [this, box] {clickRightBox(box);});
        }
        m_boxList.push_back(tmp);
    }
}

void BoxGrid::createMines(QVector<QVector<Box*>> boxList, int nbMines)
{
    QVector<Box::Point> mineGrid;
    while(mineGrid.size()<m_nbMines)
    {
        Box::Point p;
        p.x= gene.bounded(m_nbCol);
        p.y = gene.bounded(m_nbLine);
        if(std::find(mineGrid.constBegin(), mineGrid.constEnd(), p) == mineGrid.constEnd())
            mineGrid.push_back(p);
    }
    for(Box::Point p : mineGrid)
    {
        Box *box = getBox(p.x,p.y);
        box->setMine();
    }
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
        //discoverBox();
    }
}

void BoxGrid::clickRightBox(Box *box)
{
    box->setStyleSheet("QToolButton {"
                       "background-color: dark_grey;"
                       "border-image: url(:/image/image/flag.png) 0 0 0 0 stretch stretch;"
                       "}");
}

int BoxGrid::getNbMinesAround(Box* box)
{
    int counter =0;
    Box::Point coordinate = box->getCoordinates();
    QVector<Box*> listBoxes;
    if(coordinate.x-1>=0 && coordinate.y-1>=0)
        listBoxes.push_back(getBox(coordinate.x-1,coordinate.y-1));
    if(coordinate.x-1>=0)
        listBoxes.push_back(getBox(coordinate.x-1,coordinate.y));
    if(coordinate.x-1>=0 && coordinate.y+1<m_nbLine)
        listBoxes.push_back(getBox(coordinate.x-1,coordinate.y+1));
    if(coordinate.y-1>=0)
        listBoxes.push_back(getBox(coordinate.x,coordinate.y-1));
    if(coordinate.y+1<m_nbLine)
        listBoxes.push_back(getBox(coordinate.x,coordinate.y+1));
    if(coordinate.x+1<m_nbCol && coordinate.y-1>=0)
        listBoxes.push_back(getBox(coordinate.x+1,coordinate.y-1));
    if(coordinate.x+1<m_nbCol)
        listBoxes.push_back(getBox(coordinate.x+1,coordinate.y));
    if(coordinate.x+1<m_nbCol && coordinate.y+1<m_nbLine)
        listBoxes.push_back(getBox(coordinate.x+1,coordinate.y+1));

    for(auto b : listBoxes)
    {
        if(b->isMine())
            counter++;
    }
    return counter;
}

//void BoxGrid::discoverBox(Box *box)
//{
//    //if(getNbMinesAround(box)==0)

//}
