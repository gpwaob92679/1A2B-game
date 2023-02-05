#include "ui/digit_spin_box.h"

#include <QFocusEvent>
#include <QKeyEvent>
#include <QLineEdit>
#include <QMouseEvent>
#include <QSpinBox>
#include <QTimer>

namespace one_a_two_b {

DigitSpinBox::DigitSpinBox(QWidget *parent) : QSpinBox(parent) {}

void DigitSpinBox::focusInEvent(QFocusEvent *event) {
  QTimer::singleShot(0, this, &DigitSpinBox::selectAll);
}

void DigitSpinBox::keyPressEvent(QKeyEvent *event) {
  switch (event->key()) {
    case Qt::Key_Right:
      focusNextChild();
      return;
    case Qt::Key_Left:
      focusPreviousChild();
      return;
  }
  QSpinBox::keyPressEvent(event);
  switch (event->key()) {
    case Qt::Key_0:
    case Qt::Key_1:
    case Qt::Key_2:
    case Qt::Key_3:
    case Qt::Key_4:
    case Qt::Key_5:
    case Qt::Key_6:
    case Qt::Key_7:
    case Qt::Key_8:
    case Qt::Key_9:
      focusNextChild();
      emit NumberEntered();
  }
}

void DigitSpinBox::Reset() {
  setValue(0);
}

}  // namespace one_a_two_b
