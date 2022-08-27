#ifndef BOX_H
#define BOX_H

#include <QToolButton>
#include <QColor>


class Box : public QToolButton
{
public:
    Box();
    struct Point{
        int x;
        int y;
        bool operator==(const Point& a) const
            {
                return (x == a.x && y == a.y);
            }
    };
    void setMine();
    bool isMine() {return m_isMine;};
    void setCoordinates(int, int);
    Point getCoordinates() {return m_coordinate;};
    void changeDisplay(QColor color, int nbMine);


private:
    bool m_isChecked;
    bool m_isMine;
    bool m_isFlag;

    Point m_coordinate;
};

#endif // BOX_H
