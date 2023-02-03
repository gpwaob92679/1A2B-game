#include "game.h"

#include <algorithm>
#include <chrono>
#include <random>

#include <QDebug>
#include <QList>
#include <QString>

namespace one_a_two_b {

Game::Game() {
  uint64_t seed = std::chrono::system_clock::now().time_since_epoch().count();
  QList<int> temp = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::shuffle(temp.begin(), temp.end(), std::default_random_engine(seed));
  answer_ = temp.sliced(0, 4);
  qDebug() << "Answer:" << answer_;
}

QString Game::Guess(QList<int> &guess) {
  assert(guess.size() == answer_.size());

  int a_count = 0;
  int b_count = 0;
  for (int i = 0; i < guess.size(); ++i) {
    if (answer_.contains(guess[i])) {
      if (answer_.indexOf(guess[i]) == i) {
        ++a_count;
      } else {
        ++b_count;
      }
    }
  }

  return QString("%1A%2B").arg(a_count).arg(b_count);
}

}  // namespace one_a_two_b
