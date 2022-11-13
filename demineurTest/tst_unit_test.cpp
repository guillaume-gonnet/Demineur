#include <QtTest>
#include <QCoreApplication>
#include "../demineur/scorecard.h"

class unit_test : public QObject
{
    Q_OBJECT

public:
    unit_test();
    ~unit_test();

private slots:
    void test_highestScore();
    void test_addScore();

private:
    ScoreCard *m_scoreCard;
    QVector<Score> scoreVect;
};

unit_test::unit_test()
{
    m_scoreCard = new ScoreCard;
    m_scoreCard->clearScoreVect();
    m_scoreCard->addScore(Score{"Small", 30, "gg"});
    m_scoreCard->addScore(Score{"Small", 9, "gg"});
    m_scoreCard->addScore(Score{"Small", 5, "gg"});
    m_scoreCard->addScore(Score{"Small", 20, "gg"});
    m_scoreCard->addScore(Score{"Small", 25, "gg"});
    m_scoreCard->addScore(Score{"Small", 10, "gg"});
    m_scoreCard->addScore(Score{"Small", 10, "tmp"});
    m_scoreCard->addScore(Score{"Small", 8, "zzzz"});
    m_scoreCard->addScore(Score{"Small", 29, "tmp"});
    m_scoreCard->addScore(Score{"Small", 22, "a"});
}

unit_test::~unit_test()
{
    delete m_scoreCard;
}

void unit_test::test_highestScore()
{
    QString gridStdSize = "Small";
    int index = m_scoreCard->highestScore(gridStdSize);
    QCOMPARE(m_scoreCard->getScore(index).getSec(), 30);
}

void unit_test::test_addScore()
{
    Score score = {"Small", 6, "test"};
    m_scoreCard->addScore(score);
    QCOMPARE(m_scoreCard->getScore(9).getName(),"test");
}

QTEST_MAIN(unit_test)

#include "tst_unit_test.moc"
