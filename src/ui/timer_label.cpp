#include "ui/timer_label.h"

#include <QDebug>
#include <QLabel>

namespace one_a_two_b {

TimerLabel::TimerLabel(QWidget *parent)
    : QLabel(parent), time_(0, 0), timer_(new QTimer()) {
  UpdateText();
  QObject::connect(timer_, &QTimer::timeout, [&]() {
    time_ = time_.addSecs(1);
    UpdateText();
  });
}

void TimerLabel::ResetTimer() {
  time_.setHMS(0, 0, 0);
  UpdateText();
  timer_->stop();
}

void TimerLabel::StartTimer() {
  if (!timer_->isActive()) {
    timer_->start(1000);
  }
}

void TimerLabel::StopTimer() {
  timer_->stop();
}

void TimerLabel::UpdateText() {
  if (time_.hour() == 0) {
    setText(time_.toString("m:ss"));
  } else {
    setText(time_.toString("h:mm:ss"));
  }
}

}  // namespace one_a_two_b
