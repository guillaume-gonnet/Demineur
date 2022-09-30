#include <QtTest>
#include <QCoreApplication>
#include "../../demineur/scorecard.h"

class unit_test : public QObject
{
    Q_OBJECT

public:
    unit_test();
    ~unit_test();

private slots:
    void test_highestScore();

private:
    ScoreCard *m_scoreCard;
    QVector<Score> scoreVect;
};

unit_test::unit_test()
{
    m_scoreCard = new ScoreCard;
    scoreVect = {
        {"Small", 2, "gg"},
        {"Small", 9, "gg"},
        {"Small", 5, "gg"},
        {"Small", 20, "gg"},
        {"Small", 25, "gg"},
        {"Small", 10, "gg"},
        {"Small", 10, "tmp"},
        {"Small", 8, "zzzz"},
        {"Small", 30, "tmp"},
        {"Small", 22, "a"},
    };
}

unit_test::~unit_test()
{
    delete m_scoreCard;
}

void unit_test::test_highestScore()
{

    QString gridStdSize = "Small";
    int index = m_scoreCard->highestScore(scoreVect, gridStdSize);
    QCOMPARE(index, 8);
}

QTEST_MAIN(unit_test)

#include "tst_unit_test.moc"
