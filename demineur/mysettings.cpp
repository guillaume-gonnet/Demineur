#include "mysettings.h"
#include "box.h"

MySettings::MySettings()
{

}

void MySettings::saveSettings(BoxGrid &boxgrid)
{
    QSettings settings("GG company", "Demineur");
    settings.beginGroup("BoxGrid");
    settings.remove("");
    settings.setValue("wide", boxgrid.getWide());
    settings.setValue("height", boxgrid.getHeight());
    settings.setValue("mines", boxgrid.getNbMines());
    settings.beginGroup("Box");
    for(int i=0; i!=boxgrid.getHeight(); ++i)
    {
        for(int j=0; j!=boxgrid.getWide(); j++)
        {
            Box *box = boxgrid.getBox(i,j);
            QString str = "";
            str.append(QString::number(box->getCoordinates().x));
            str.append("-");
            str.append(QString::number(box->getCoordinates().y));
            settings.setValue(str.append("isChecked"), box->isChecked());
            settings.setValue(str.append("hasMine"), box->hasMine());
            settings.setValue(str.append("hasFlag"), box->hasFlag());
        }
    }
    settings.endGroup(); //Box
    settings.endGroup(); //BoxGrid
}

BoxGrid* MySettings::loadSettings()
{
    QSettings settings("GG company", "Demineur");
    settings.beginGroup("BoxGrid");
    int wide = settings.value("wide").toInt();
    int height = settings.value("height").toInt();
    int mines = settings.value("wide").toInt();
    settings.endGroup(); //Box
    settings.endGroup(); //BoxGrid
    BoxGrid *boxgrid = new BoxGrid(wide, height,mines,true);
    return boxgrid;
}

void MySettings::loadBox(Box *box)
{
    QSettings settings("GG company", "Demineur");
    settings.beginGroup("BoxGrid");
    settings.beginGroup("Box");
    QString str = "";
    str.append(QString::number(box->getCoordinates().x));
    str.append("-");
    str.append(QString::number(box->getCoordinates().y));
    bool checked = settings.value(str.append("isChecked")).toBool();
    bool mine = settings.value(str.append("hasMine")).toBool();
    bool flag = settings.value(str.append("hasFlag")).toBool();
    box->setCheck(checked);
    box->setMine(mine);
    box->setFlag(flag);
    settings.endGroup(); //Box
    settings.endGroup(); //BoxGrid
}
