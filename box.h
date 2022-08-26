#ifndef BOX_H
#define BOX_H

#include <QToolButton>


class Box : public QToolButton
{
public:
    Box();
    void setMine();
    void setCoordinates(int, int);

public slots:
    void clickRightBox();
    void clickLeftBox();

private:
    bool m_isChecked;
    bool m_isMine;
    bool m_isFlag;
    int m_col;
    int m_line;
    void checkNextBox();
};

#endif // BOX_H
