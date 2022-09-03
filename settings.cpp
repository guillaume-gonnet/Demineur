#include "settings.h"
#include <iostream>

MySettings::MySettings()
{

}

void MySettings::saveSettings(BoxGrid &boxgrid)
{
    QSettings settings("GG company", "Demineur");
    settings.setValue("BoxGrid/wide", boxgrid.getWide());
    settings.setValue("BoxGrid/height", boxgrid.getHeight());
    settings.setValue("BoxGrid/mines", boxgrid.getNbMines());
    for(int i=0; i!=boxgrid.getHeight(); ++i)
    {
        for(int j=0; j!=boxgrid.getWide(); j++)
        {
            Box *box = boxgrid.getBox(i,j);
            QString str = "BoxGrid/box";
            str.append(i);
            str.append("-");
            str.append(j);
            settings.setValue(str.append("isChecked"), box->isChecked());
            settings.setValue(str.append("hasMine"), box->hasMine());
            settings.setValue(str.append("hasFLag"), box->hasFlag());
        }
    }
}

void MySettings::loadSettings()
{
    QSettings settings("GG company", "Demineur");
    //TODO: implement
}
