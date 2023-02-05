#ifndef UI_TIMER_LABEL_H_
#define UI_TIMER_LABEL_H_

#include <QLabel>
#include <QTime>
#include <QTimer>

namespace one_a_two_b {

class TimerLabel : public QLabel {
  Q_OBJECT;

 public:
  TimerLabel(QWidget *parent = nullptr);

 public slots:
  void ResetTimer();
  void StartTimer();
  void StopTimer();

 private:
  void UpdateText();

  QTime time_;
  QTimer *timer_;
};

} // namespace one_a_two_b

#endif  // UI_TIMERLABEL_H_
