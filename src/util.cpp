#include "util.h"

#include <QList>
#include <QString>

QString QlistToQstring(QList<int> &list) {
  QString ret;
  for (int &i : list) {
    ret += QString("%1").arg(i);
  }
  return ret;
}
