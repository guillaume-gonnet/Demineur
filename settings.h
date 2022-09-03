#ifndef MYSETTINGS_H
#define MYSETTINGS_H

#include <QSettings>
#include "box.h"
#include "boxgrid.h"

class MySettings
{
public:
    MySettings();
    void saveSettings(BoxGrid &boxgrid);
    void loadSettings();

private:
};

#endif // MYSETTINGS_H
