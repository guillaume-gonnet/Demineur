#include "box.h"

Box::Box()
{
    m_state = unchecked;
    this->setStyleSheet("QToolButton {"
                        "background-color: grey"
                        "padding: 1px"
                        "}");
}


