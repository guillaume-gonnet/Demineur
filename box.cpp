#include "box.h"
#include <QMessageBox>

Box::Box()
{
    m_isChecked=false;
    m_isMine=false;
    m_isFlag=false;
    this->setStyleSheet("QToolButton {"
                        "background-color: grey"
                        "padding: 1px"
                        "}");
}

void Box::setMine()
{
    m_isMine=true;
}

void Box::setCoordinates(int x1, int y1)
{
    m_coordinate.x=x1;
    m_coordinate.y=y1;
}

void Box::changeDisplay(QColor color, int nbMine)
{
    if(color == "red") //lost
    {
        this->setStyleSheet("QToolButton {"
                            "background-color: red"
                            "}");
    } else {
        this->setText(QString::number(nbMine));
        this->setStyleSheet("QToolButton {background-color: grey; color: white;}");
    }
}
