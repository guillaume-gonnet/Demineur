#ifndef SCORESDIALOG_H
#define SCORESDIALOG_H

#include <QDialog>

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
    void fillItems();
};

#endif // SCORESDIALOG_H
