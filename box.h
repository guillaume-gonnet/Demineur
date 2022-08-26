#ifndef BOX_H
#define BOX_H

#include <QToolButton>
#include <QColor>


class Box : public QToolButton
{
public:
    Box();
    struct Coordinates{
        int x;
        int y;
    };
    void setMine();
    bool isMine() {return m_isMine;};
    void setCoordinates(int, int);
    Coordinates getCoordinates() {return m_coordinate;};
    void changeDisplay(QColor color, int nbMine);


private:
    bool m_isChecked;
    bool m_isMine;
    bool m_isFlag;

    Coordinates m_coordinate;
};

#endif // BOX_H
