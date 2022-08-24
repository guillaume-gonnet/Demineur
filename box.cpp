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
    connect(this, &QToolButton::clicked, this, &Box::clickLeftBox);
}


void Box::clickLeftBox()
{
    if(m_isMine)
    {
        this->setStyleSheet("QToolButton {"
                            "background-color: red"
                            "}");

        QMessageBox message;
        message.setText("Perdu!");
        message.exec();
        //TODO: implement final screen Replay?

    } else {
        this->setStyleSheet("QToolButton {"
                            "background-color: dark_grey"
                            "}");
        checkNextBox();
    }
}


void Box::clickRightBox()
{
//TODO: to be implemented
}

void Box::checkNextBox()
{
//TODO: to be implemented
}

void Box::setMine()
{
    m_isMine=true;
}
