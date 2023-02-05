#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "game.h"
#include "util.h"

namespace one_a_two_b {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow), game_(new Game) {
  ui_->setupUi(this);
  ui_->digitSpinBox0->setFocus();
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

  QString result =
      QString("%1   %2").arg(QlistToQstring(guess), game_->Guess(guess));
  ui_->listWidgetPastGuesses->insertItem(0, result);

  ui_->digitSpinBox0->setFocus();
}

}  // namespace one_a_two_b
