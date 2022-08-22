#ifndef BOX_H
#define BOX_H

#include <QPushButton>

class Box : public QPushButton
{
public:
    Box();
    enum BoxState {unchecked, checkedEmpty, CheckedMine};
    enum BoxSolution {empty, mine};

private:
    BoxState state;
    BoxSolution solution;
};

#endif // BOX_H
