#include "box.h"
#include <QMessageBox>

Box::Box()
{
    m_isChecked=false;
    m_isMine=false;
    m_hasFlag=false;
    this->setStyleSheet("QToolButton {\
                        background-color: silver;\
                        border-style: none;\
                        padding: 2px;\
                        width: 25px;\
                        height: 25px;\
                        border-radius: 5px;\
                        }");
}

void Box::setCoordinates(const int x1, const int y1)
{
    m_coordinate.x=x1;
    m_coordinate.y=y1;
}

void Box::changeDisplay(const QColor color, const int nbMine)
{
    if(color == "red") //lost
    {
        this->setStyleSheet("QToolButton {\
                            background-color: red;\
                            border-image: url(:/image/image/mine.png) 0 0 0 0 stretch stretch;\
                            }");
    } else {
        this->setText(QString::number(nbMine));
        this->setStyleSheet("QToolButton {background-color: grey; color: white;}");
    }
}

void Box::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton)
        emit rightClicked();
    if(e->button()==Qt::LeftButton)
        emit leftClicked();
}
