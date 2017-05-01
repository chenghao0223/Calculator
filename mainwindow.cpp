#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"
#include "QString"
#include "iostream"
using namespace  std;

double firstNum;
bool secondNumTyped = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digit_pressed()));

    connect(ui->pushButton_plusMinus, SIGNAL(released()), this, SLOT(unary_opeartion_pressed()));
    connect(ui->pushButton_percent, SIGNAL(released()), this, SLOT(unary_opeartion_pressed()));

    connect(ui->pushButton_add, SIGNAL(released()), this, SLOT(binary_opeartion_pressed()));
    connect(ui->pushButton_subtract, SIGNAL(released()), this, SLOT(binary_opeartion_pressed()));
    connect(ui->pushButton_multiply, SIGNAL(released()), this, SLOT(binary_opeartion_pressed()));
    connect(ui->pushButton_divide, SIGNAL(released()), this, SLOT(binary_opeartion_pressed()));

    connect(ui->pushButton_equals, SIGNAL(released()), this, SLOT(equals_opeartion_released()));
    connect(ui->pushButton_clear, SIGNAL(released()), this, SLOT(clear_opeartion_released()));

    connect(ui->pushButton_decimal, SIGNAL(released()), this, SLOT(decimal_opeartion_released()));

    ui->pushButton_add->setCheckable(true);
    ui->pushButton_subtract->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);

}

void MainWindow::digit_pressed(){

    QPushButton * button =(QPushButton*) sender();
    double  labelNumber;
    QString newLabel;

    if( (ui->pushButton_add->isChecked() || ui->pushButton_subtract->isChecked()
            || ui->pushButton_multiply->isChecked() || ui->pushButton_divide->isChecked() )
            && (!secondNumTyped) ){
        labelNumber = button->text().toDouble();
        secondNumTyped = true;
        newLabel = QString::number(labelNumber,'g',15);
    }else{

        if( ui->label->text().contains('.') && button->text() == "0"){
            newLabel = ui->label->text() + button->text();
        }
        else{
            labelNumber = (ui->label->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber,'g',15);
        }
    }

    ui->label->setText(newLabel);

}

void MainWindow::decimal_opeartion_released(){
    QString newLabel;
    newLabel = ui->label->text() + "." ;
    ui->label->setText(newLabel);
}

void MainWindow::unary_opeartion_pressed(){
    QPushButton * button = (QPushButton *) sender();
    double labelNumber = ui->label->text().toDouble() ;
    QString newLabel ;

    if( button->text() == "+/-"){
        labelNumber *= -1;
    }

    if( button->text() == "%" ){
        labelNumber *= 0.01;
    }

    newLabel = QString::number(labelNumber,'g',15);
    ui->label->setText(newLabel);

}

void MainWindow::clear_opeartion_released(){
    ui->label->setText(QString::number(0,'g',15));
    ui->pushButton_add->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_subtract->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    secondNumTyped = false;
}

void  MainWindow::equals_opeartion_released(){
    double result,secondNum;
    secondNum = ui->label->text().toDouble();
    if( ui->pushButton_add->isChecked() ){
        result = firstNum + secondNum;
        ui->pushButton_add->setChecked(false);
    }
    else if( ui->pushButton_subtract->isChecked() ){
        result = firstNum - secondNum;
        ui->pushButton_subtract->setChecked(false);
    }
    else if( ui->pushButton_multiply->isChecked() ){
        result = firstNum * secondNum;
        ui->pushButton_multiply->setChecked(false);
    }
    else if( ui->pushButton_divide->isChecked() ){
        result = firstNum / secondNum;
        ui->pushButton_divide->setChecked(false);
    }else{
        result = ui->label->text().toDouble();
    }
    QString newLabel = QString::number(result,'g',15);
    ui->label->setText(newLabel);

    secondNumTyped = false;

}

void MainWindow::binary_opeartion_pressed(){
    QPushButton * button = (QPushButton * ) sender();

    firstNum = ui->label->text().toDouble();

    button->setChecked(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


