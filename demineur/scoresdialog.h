#ifndef SCORESDIALOG_H
#define SCORESDIALOG_H

#include <QDialog>
#include <QVector>
#include "score.h"

namespace Ui {
class ScoresDialog;
}

class ScoresDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScoresDialog(QWidget *parent = nullptr);
    ~ScoresDialog();

private:
    Ui::ScoresDialog *ui;
    void fillItems(QVector<Score>);
    QVector<Score> loadScores(); //duplicate with Scorecard. SHould file interface be in Score?
};

#endif // SCORESDIALOG_H
