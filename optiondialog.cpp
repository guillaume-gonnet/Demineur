#include "optiondialog.h"
#include "ui_optiondialog.h"

OptionDialog::OptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionDialog)
{
    ui->setupUi(this);
    ui->spinBoxHeight->setRange(3,100);
    ui->spinBoxWide->setRange(3,100);
    ui->spinBoxNbMines->setRange(1,100);
}

OptionDialog::~OptionDialog()
{
    delete ui;
}


void OptionDialog::on_buttonBox_accepted()
{
    m_height = ui->spinBoxHeight->value();
    m_wide = ui->spinBoxWide->value();
    m_mines = ui->spinBoxNbMines->value();
    if(m_mines>=m_height*m_wide)
        return;
}


void OptionDialog::on_buttonBox_rejected()
{
    this->close();
}

