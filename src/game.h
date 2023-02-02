#ifndef GAME_H_
#define GAME_H_

#include <QList>
#include <QString>

class Game {
 public:
  Game();
  QString Guess(QList<int> &guess);

 private:
  QList<int> answer_;
};

#endif  // GAME_H_
