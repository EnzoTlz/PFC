#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent) //constructeur
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn_Ciseaux, SIGNAL(clicked(bool)), this ,SLOT(ProcessGame()));
    connect(ui->btn_Papier, SIGNAL(clicked(bool)), this ,SLOT(ProcessGame()));
    connect(ui->btn_Pierre, SIGNAL(clicked(bool)), this ,SLOT(ProcessGame()));

}

int MainWindow::GenerateNumberRandom()
{
    return rand()% 3+1;
}

int MainWindow::CompareNumberRandomAndUserNumber(int random, int user)
{
    // 1 ==> user win
    // 2 ==> ordi win
    // 0 ==> egalite


    // 1 < 2 // 1 > 3 //
    // 2 > 1 // 2 < 3 //
    // 3 > 2 // 3 < 1 //

    if (random == 1  && user == 2){
        return 2;
    }else if(random == 1 && user ==3){
        return 1;
    }else if(random == 2 && user ==1){
        return 1;
    }else if(random == 2 && user ==3){
        return 2;
    }else if(random == 3 && user ==1){
        return 2;
    }else if(random == 2 && user ==2){
        return 1;
    }else{
        return 0;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ProcessGame()
{
    QPushButton *ButtonClicked  = qobject_cast<QPushButton*>(sender());
    int randomNumber = this->GenerateNumberRandom();
    int userNumber = 0;

    if((ButtonClicked == ui->btn_Ciseaux)){
        userNumber = 1;
    }else if(ButtonClicked == ui->btn_Papier){
        userNumber = 3;
    }else if(ButtonClicked == ui->btn_Pierre){
        userNumber = 2;
    }

    int result = this->CompareNumberRandomAndUserNumber(randomNumber,userNumber);

    switch (result) {
    case 0:
        ui->lb_PrintResult->setText("égalité ");
        break;
    case 1:
        ui->lb_PrintResult->setText("Bravo vous avez gagner !");
        break;
    case 2:
        ui->lb_PrintResult->setText("Vous avez perdu !");
        break;
    default:
        break;
    }
}



