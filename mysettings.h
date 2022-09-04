#ifndef MYSETTINGS_H
#define MYSETTINGS_H

#include <QSettings>

#include "boxgrid.h"

class MySettings
{
public:
    MySettings();
    void saveSettings(BoxGrid &boxgrid);
    BoxGrid* loadSettings();
    void loadBox(Box *box);

private:
};

#endif // MYSETTINGS_H
