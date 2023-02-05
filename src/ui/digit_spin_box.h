#ifndef UI_DIGIT_SPIN_BOX_H_
#define UI_DIGIT_SPIN_BOX_H_

#include <QSpinBox>

namespace one_a_two_b {

class DigitSpinBox : public QSpinBox {
  Q_OBJECT

 public:
  DigitSpinBox(QWidget *parent = nullptr);

 public slots:
  void Reset();

 signals:
  void NumberEntered();

 protected:
  void focusInEvent(QFocusEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;
};

}  // namespace one_a_two_b

#endif  // UI_DIGITSPINBOX_H_
