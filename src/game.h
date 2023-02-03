#ifndef GAME_H_
#define GAME_H_

#include <QList>
#include <QString>

namespace one_a_two_b {

class Game {
 public:
  Game();
  QString Guess(QList<int> &guess);

 private:
  QList<int> answer_;
};

}  // namespace one_a_two_b

#endif  // GAME_H_
