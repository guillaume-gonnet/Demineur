#include "boxgrid.h"
#include <QMessageBox>
#include <QRandomGenerator>
#include <QDateTime>

QRandomGenerator gene = QRandomGenerator(QDateTime::currentMSecsSinceEpoch());

BoxGrid::BoxGrid(): m_height(5),m_wide(5),m_mines(5),m_remainFlag(m_mines)
{
    m_remainBox = m_height * m_wide;
    createBoxGrid();
    createMines(m_boxList,m_mines);
}

BoxGrid::BoxGrid(int wide, int height, int mines): m_wide(wide),m_height(height),m_mines(mines),m_remainFlag(mines)
{
    m_remainBox = m_height * m_wide;
    createBoxGrid();
    createMines(m_boxList,m_mines);
}

BoxGrid::~BoxGrid()
{
    for(auto arrBox : m_boxList)
    {
        for(auto box : arrBox)
        {
            delete box;
        }
    }
}


void BoxGrid::createBoxGrid()
{
    for(int i=0;i<m_height;i++)
    {
        QVector<Box*> tmp;

        for(int j=0;j<m_wide;j++)
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
    while(mineGrid.size()<m_mines)
    {
        Box::Point p;
        p.x= gene.bounded(m_height);
        p.y = gene.bounded(m_wide);
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
    if(box->isChecked())
        return;

    box->setCheck(true);

    if(box->hasMine()) //lost
    {
        for(auto boxArr : m_boxList)
        {
            for(auto box : boxArr)
            {
                if(box->hasMine())
                    box->changeDisplay(QColor("red"),0);
            }
        }

        emit gameEnded("lost");

    } else {
        box->setCheckable(false);
        box->setStyleSheet("QToolButton {"
                            "background-color: dark_grey"
                            "}");

        box->changeDisplay(QColor("black"), getNbMinesAround(box));
    }
    if(--m_remainBox==0)
        emit gameEnded("win");
}

void BoxGrid::clickRightBox(Box *box)
{
    if(box->hasFlag()) //remove flag
    {
        box->setFlag(false);
        box->setCheck(false);
        box->setStyleSheet("QToolButton {"
                           "background-color: silver;"
                           "}");
        ++m_remainFlag;
        ++m_remainBox;
    } else if (box->isChecked() || m_remainFlag==0)
    {
        return;
    } else {
        box->setFlag(true);
        box->setCheck(true);
        box->setStyleSheet("QToolButton {"
                           "background-color: grey;"
                           "border-image: url(:/image/image/flag.png) 0 0 0 0 stretch stretch;"
                           "}");
        --m_remainFlag;
        if(--m_remainBox==0)
            emit gameEnded("win");
    }
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
    if(coordinate.x-1>=0 && coordinate.y+1<m_wide)
        listBoxes.push_back(getBox(coordinate.x-1,coordinate.y+1));
    if(coordinate.y-1>=0)
        listBoxes.push_back(getBox(coordinate.x,coordinate.y-1));
    if(coordinate.y+1<m_wide)
        listBoxes.push_back(getBox(coordinate.x,coordinate.y+1));
    if(coordinate.x+1<m_height && coordinate.y-1>=0)
        listBoxes.push_back(getBox(coordinate.x+1,coordinate.y-1));
    if(coordinate.x+1<m_height)
        listBoxes.push_back(getBox(coordinate.x+1,coordinate.y));
    if(coordinate.x+1<m_height && coordinate.y+1<m_wide)
        listBoxes.push_back(getBox(coordinate.x+1,coordinate.y+1));

    for(auto b : listBoxes)
    {
        if(b->hasMine())
            counter++;
    }
    if(counter == 0)
        clickLeftBox(box);

 //if 0 mine, then explore around boxes and click if 0 mine as well
    if(counter==0 && !listBoxes.isEmpty())
    {
        for(auto b : listBoxes)
        {
            clickLeftBox(b);
        }
    }
    return counter;
}
