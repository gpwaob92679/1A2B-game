#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "game.h"
#include "ui/timer_label.h"
#include "util.h"

namespace one_a_two_b {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow), game_(new Game()) {
  ui_->setupUi(this);
  ui_->digitSpinBox0->setFocus();
  InitTimerLabel();
}

void MainWindow::InitTimerLabel() {
  timer_label_ = new TimerLabel();
  timer_label_->setObjectName("timerLabel");
  ui_->statusbar->addPermanentWidget(timer_label_);
  QObject::connect(ui_->actionNew, &QAction::triggered, timer_label_,
                   &TimerLabel::ResetTimer);
  QObject::connect(this, &MainWindow::GameEnded, timer_label_,
                   &TimerLabel::StopTimer);
  QObject::connect(ui_->digitSpinBox0, &DigitSpinBox::NumberEntered,
                   timer_label_, &TimerLabel::StartTimer);
  QObject::connect(ui_->digitSpinBox1, &DigitSpinBox::NumberEntered,
                   timer_label_, &TimerLabel::StartTimer);
  QObject::connect(ui_->digitSpinBox2, &DigitSpinBox::NumberEntered,
                   timer_label_, &TimerLabel::StartTimer);
  QObject::connect(ui_->digitSpinBox3, &DigitSpinBox::NumberEntered,
                   timer_label_, &TimerLabel::StartTimer);
  QObject::connect(ui_->digitSpinBox0, &DigitSpinBox::valueChanged,
                   timer_label_, &TimerLabel::StartTimer);
  QObject::connect(ui_->digitSpinBox1, &DigitSpinBox::valueChanged,
                   timer_label_, &TimerLabel::StartTimer);
  QObject::connect(ui_->digitSpinBox2, &DigitSpinBox::valueChanged,
                   timer_label_, &TimerLabel::StartTimer);
  QObject::connect(ui_->digitSpinBox3, &DigitSpinBox::valueChanged,
                   timer_label_, &TimerLabel::StartTimer);
}

MainWindow::~MainWindow() {
  delete ui_;
  delete game_;
}

void MainWindow::on_pushButtonSubmit_clicked() {
  QList<int> guess(4);
  guess[0] = ui_->digitSpinBox0->value();
  guess[1] = ui_->digitSpinBox1->value();
  guess[2] = ui_->digitSpinBox2->value();
  guess[3] = ui_->digitSpinBox3->value();

  QString guess_result = game_->Guess(guess);
  QString result = QString("%1   %2").arg(QlistToQstring(guess), guess_result);
  ui_->listWidgetPastGuesses->insertItem(0, result);

  if (guess_result == QString("4A0B")) {
    emit GameEnded();
  }
}

void MainWindow::on_actionNew_triggered() {
  delete game_;
  game_ = new Game();
}

}  // namespace one_a_two_b
