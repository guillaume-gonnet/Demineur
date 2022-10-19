#ifndef SCORECARD_H
#define SCORECARD_H
#include <QString>
#include <QVector>
#include "score.h"
#define MAX_HIGH_SCORE 10

class ScoreCard
{
    public:
        ScoreCard();
        QVector<Score> loadScores();
        void saveScores();
        void addScore(const Score);
        bool isTop10(const Score);
        int highestScore(const QVector<Score>, const QString gridStdSize);

    private:
        QVector<Score> m_scoreVect;
        bool isTop10Full(const QVector<Score>, const QString gridStdSize);
        bool isDuplicate(const QVector<Score>, const Score score);
};

#endif // SCORECARD_H