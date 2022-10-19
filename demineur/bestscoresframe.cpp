#include "bestscoresframe.h"
#include "ui_bestscoresframe.h"

BestScoresFrame::BestScoresFrame(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::BestScoresFrame)
{
    ui->setupUi(this);
}

BestScoresFrame::~BestScoresFrame()
{
    delete ui;
}
