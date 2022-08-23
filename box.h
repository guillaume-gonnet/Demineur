#ifndef BOX_H
#define BOX_H

#include <QToolButton>

class Box : public QToolButton
{
public:
    Box();
    enum BoxState {unchecked, checkedEmpty, CheckedMine};

public slots:
    void isCheckedEmpty();

private:
    BoxState m_state;
    void isCheckedEmpty(Box *box, bool b);
};

#endif // BOX_H
