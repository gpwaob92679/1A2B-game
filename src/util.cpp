#include "util.h"

#include <QList>
#include <QString>

namespace one_a_two_b {

QString QlistToQstring(QList<int> &list) {
  QString ret;
  for (int &i : list) {
    ret += QString("%1").arg(i);
  }
  return ret;
}

}  // namespace one_a_two_b
