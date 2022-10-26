#include "scoresdialog.h"
#include "ui_scoresdialog.h"
#include <QFile>

ScoresDialog::ScoresDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScoresDialog)
{
    ui->setupUi(this);
    QVector<Score> scoreSet = loadScores();
    fillItems(scoreSet);
}

ScoresDialog::~ScoresDialog()
{
    delete ui;
}

void ScoresDialog::fillItems(QVector<Score> scoreSet)
{
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels({"Name","Time"});
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    for(int row = 0; row < scoreSet.size() && row <= 10; ++row)
    {
        QTableWidgetItem *name = new QTableWidgetItem(scoreSet[row].getName());
        QTableWidgetItem *sec = new QTableWidgetItem(QString::number(scoreSet[row].getSec()));
        ui->tableWidget->setItem(row,0,name);
        ui->tableWidget->setItem(row,1,sec);
    }
    ui->tableWidget->sortItems(1);
}

QVector<Score> ScoresDialog::loadScores()
{
  QFile file("scores");
  if(!file.open(QIODevice::ReadOnly | QFile::Text))
      return {};
  if(file.size()==0)
      return {};

    qInfo() << "file loading...";
    QVector<Score> scoreSet;
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList list1 = line.split(QLatin1Char(','));
        Score score(list1[0],list1[1].toInt(),list1[2]);
        Score const &sc = score;
        scoreSet.append(sc);
     }

    file.close();
    return scoreSet;
}
