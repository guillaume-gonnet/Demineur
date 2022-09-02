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
    void setCheck(const bool b) {m_isChecked=b;};
    bool isChecked() {return m_isChecked;};
    void setMine() {m_isMine=true;};
    bool hasMine() {return m_isMine;};
    void setFlag(const bool b) {m_hasFlag = b;};
    bool hasFlag() {return m_hasFlag;};
    void setCoordinates(const int, const int);
    Point getCoordinates() {return m_coordinate;};
    void changeDisplay(const QColor color, const int nbMine);

private:
    bool m_isChecked;
    bool m_isMine;
    bool m_hasFlag;

    Point m_coordinate;

private slots:
    void mousePressEvent(QMouseEvent *e);

signals:
    void rightClicked();
    void leftClicked();

};

#endif // BOX_H
