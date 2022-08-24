#ifndef BOX_H
#define BOX_H

#include <QToolButton>

class Box : public QToolButton
{
public:
    Box();
    void setMine();

public slots:
    void clickRightBox();
    void clickLeftBox();

private:
    bool m_isChecked;
    bool m_isMine;
    bool m_isFlag;
    void checkNextBox();
};

#endif // BOX_H
