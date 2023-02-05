#ifndef UI_MAINWINDOW_H_
#define UI_MAINWINDOW_H_

#include <QMainWindow>

#include "game.h"
#include "ui/timer_label.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace one_a_two_b {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_actionNew_triggered();
  void on_pushButtonSubmit_clicked();

 signals:
  void GameEnded();

 private:
  void InitTimerLabel();

  Ui::MainWindow *ui_;
  Game *game_;
  TimerLabel *timer_label_;
};

}  // namespace one_a_two_b

#endif  // UI_MAINWINDOW_H_
