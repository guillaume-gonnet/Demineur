#include "scorecard.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

ScoreCard::ScoreCard()
{
      m_scoreVect = loadScores();
}

QVector<Score> ScoreCard::loadScores()
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

void ScoreCard::saveScores()
{
    QFile file("scores");
    if(!file.open(QIODevice::WriteOnly | QFile::Text))
        return; //throw exception

    QTextStream out(&file);
    for (auto const &i: m_scoreVect)
    {
        out << i.getGridStdSize() << "," << i.getSec() << "," << i.getName()  << "\n";
    }
    file.close();
}

void ScoreCard::addScore(Score score)
{
    if(!isTop10Full(m_scoreVect,score.getGridStdSize()))
    {
        m_scoreVect.append(score);
//        m_scoreSet.append({"Small",5,"test"});
    }
    else
    {
        //NOT WORKING: get index 1 => write unit test
        m_scoreVect.removeAt(highestScore(m_scoreVect,score.getGridStdSize()));
        m_scoreVect.append(score);
    }
}

bool ScoreCard::isTop10(Score score)
{
    if(isDuplicate(m_scoreVect, score))
        return false;
    if(!isTop10Full(m_scoreVect,score.getGridStdSize()))
        return true;
    for(auto s : m_scoreVect)
    {
        if(s.getGridStdSize()==score.getGridStdSize() && score.getSec()<s.getSec())
                return true;
    }
    return false;
}

bool ScoreCard::isTop10Full(QVector<Score> scoreVect, QString gridStdSize)
{
    int count = 0;
    for(auto score : scoreVect)
    {
        if(score.getGridStdSize()==gridStdSize)
            ++count;
    }
    if(count<MAX_HIGH_SCORE)
        return false;
    return true;
}

bool ScoreCard::isDuplicate(QVector<Score> scoreVect, Score score)
{
    for(auto s : scoreVect)
    {
        if(s==score)
            return true;
    }
    return false;
}

//return index of score with highest number of seconds. Return -1 if no score in this gridSize
int ScoreCard::highestScore(const QVector<Score> scoreVect, const QString gridStdSize)
{
    int highestIndex = -1;
    int highestSec = -1;
    int i=0;
    for(auto &s : scoreVect)
    {
        if(s.getGridStdSize()==gridStdSize)
        {
            if(s.getSec()>highestSec)
            {
                highestSec = s.getSec();
                highestIndex = scoreVect.indexOf(s);

            }
        }
    }
    return highestIndex;
}
