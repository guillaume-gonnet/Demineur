#include "scoresdialog.h"
#include "ui_scoresdialog.h"

ScoresDialog::ScoresDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScoresDialog)
{
    ui->setupUi(this);
    fillItems();
}

ScoresDialog::~ScoresDialog()
{
    delete ui;
}

void ScoresDialog::fillItems()
{
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels({"Name","Time"});

}
