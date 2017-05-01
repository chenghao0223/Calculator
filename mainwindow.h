#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void digit_pressed();
    void unary_opeartion_pressed();
    void binary_opeartion_pressed();
    void equals_opeartion_released();
    void clear_opeartion_released();
    void decimal_opeartion_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
