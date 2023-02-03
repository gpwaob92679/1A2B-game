#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "game.h"
#include "util.h"

namespace one_a_two_b {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow), game_(new Game) {
  ui_->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui_;
  delete game_;
}

void MainWindow::on_pushButton_submit_clicked() {
  QList<int> guess(4);
  guess[0] = ui_->spinBox_0->value();
  guess[1] = ui_->spinBox_1->value();
  guess[2] = ui_->spinBox_2->value();
  guess[3] = ui_->spinBox_3->value();

  QString result =
      QString("%1   %2").arg(QlistToQstring(guess), game_->Guess(guess));
  ui_->listWidget_past_guesses->insertItem(0, result);
}

}  // namespace one_a_two_b
