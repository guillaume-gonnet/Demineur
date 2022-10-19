#ifndef BESTSCORESFRAME_H
#define BESTSCORESFRAME_H

#include <QDockWidget>

namespace Ui {
class BestScoresFrame;
}

class BestScoresFrame : public QDockWidget
{
    Q_OBJECT

public:
    explicit BestScoresFrame(QWidget *parent = nullptr);
    ~BestScoresFrame();

private:
    Ui::BestScoresFrame *ui;
};

#endif // BESTSCORESFRAME_H
