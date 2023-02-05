#ifndef UI_DIGITSPINBOX_H_
#define UI_DIGITSPINBOX_H_

#include <QSpinBox>

namespace one_a_two_b {

class DigitSpinBox : public QSpinBox {
  Q_OBJECT

 public:
  DigitSpinBox(QWidget *parent = nullptr);

 protected:
  void focusInEvent(QFocusEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;
};

} // namespace one_a_two_b

#endif  // UI_DIGITSPINBOX_H_