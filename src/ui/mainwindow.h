#ifndef UI_MAINWINDOW_H_
#define UI_MAINWINDOW_H_

#include <QMainWindow>

#include "game.h"

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
  void on_pushButtonSubmit_clicked();
  void on_actionNew_triggered();

 private:
  Ui::MainWindow *ui_;
  Game *game_;
};

}  // namespace one_a_two_b

#endif  // UI_MAINWINDOW_H_
