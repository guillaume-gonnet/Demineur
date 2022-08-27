#ifndef BOX_H
#define BOX_H

#include <QToolButton>
#include <QColor>
#include <QMouseEvent>
#include <qevent.h>


class Box : public QToolButton
{
    Q_OBJECT

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

private slots:
    void mousePressEvent(QMouseEvent *e);

signals:
    void rightClicked();
    void leftClicked();

};

#endif // BOX_H
