#include "game.h"

#include <QDebug>
#include <QList>
#include <QString>
#include <algorithm>
#include <chrono>
#include <random>

Game::Game() {
  uint64_t seed = std::chrono::system_clock::now().time_since_epoch().count();
  QList<int> temp = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::shuffle(temp.begin(), temp.end(), std::default_random_engine(seed));
  answer_ = temp.sliced(0, 4);
  qDebug() << "Answer:" << answer_;
}

QString Game::Guess(QList<int> &guess) {
  assert(guess.size() == answer_.size());

  int count_a = 0;
  int count_b = 0;

  for (int i = 0; i < guess.size(); ++i) {
    if (answer_.contains(guess[i])) {
      if (answer_.indexOf(guess[i]) == i) {
        ++count_a;
      } else {
        ++count_b;
      }
    }
  }

  return QString("%1A%2B").arg(count_a).arg(count_b);
}
