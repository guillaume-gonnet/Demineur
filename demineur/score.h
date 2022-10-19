#ifndef SCORE_H
#define SCORE_H
#include <QString>

enum gridStdSize{
    SMALL = 1,
    MEDIUM = 2,
    LARGE = 3
};

class Score
{
public:
    Score(QString gridStdSize, int sec, QString name);
    QString getGridStdSize() const {return m_gridStdSize;};
    QString getName() const {return m_name;};
    int getSec() const {return m_sec;};
    bool operator ==(const Score &score) const {return score.getGridStdSize() == m_gridStdSize && score.getName() == m_name && score.getSec() == m_sec;};

private:
    QString m_gridStdSize;
    QString m_name;
    int m_sec;
};

#endif // SCORE_H
