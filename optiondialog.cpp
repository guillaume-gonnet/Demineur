#include "optiondialog.h"
#include "ui_optiondialog.h"

OptionDialog::OptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionDialog)
{
    ui->setupUi(this);
    ui->spinBoxWide->setRange(3,100);
    ui->spinBoxHeight->setRange(3,100);
    ui->spinBoxNbMines->setRange(1,100);
}

OptionDialog::~OptionDialog()
{
    delete ui;
}


void OptionDialog::on_buttonBox_accepted()
{
    m_wide = ui->spinBoxWide->value();
    m_height = ui->spinBoxHeight->value();
    m_mines = ui->spinBoxNbMines->value();
    emit accepted(m_wide, m_height, m_mines);

}


void OptionDialog::on_buttonBox_rejected()
{
    this->close();
}

