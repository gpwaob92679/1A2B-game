#include <QApplication>

#include "ui/mainwindow.h"

using one_a_two_b::MainWindow;

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainWindow main_window;
  main_window.show();
  return app.exec();
}
