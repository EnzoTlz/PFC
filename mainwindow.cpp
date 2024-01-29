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
    // 1 ==> user win       //Ciseaux === 1
    // 2 ==> ordi win       //Pierre === 2
    // 0 ==> egalite        //papier === 3


    // 1 < 2 // 1 > 3 //
    // 2 > 1 // 2 < 3 //
    // 3 > 2 // 3 < 1 //

    if (random == 1  && user == 2){
        return 1;
    }else if(random == 2 && user ==3){
        return 1;
    }else if(random == 3 && user ==1){
        return 1;
    }else if(random == user){
        return 0;
    }else{
        return 2;
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
        ui->lb_PrintUser->setText("Vous avez choisi le ciseaux");
    }else if(ButtonClicked == ui->btn_Pierre){
        userNumber = 2;
        ui->lb_PrintUser->setText("Vous avez choisi la pierre");
    }else if(ButtonClicked == ui->btn_Papier){
        userNumber = 3;
        ui->lb_PrintUser->setText("Vous avez choisi le papier");
    }
    // Affichage du label : ordinateurs
    switch (randomNumber) {
    case 1:
        ui->lb_PrintOrdi->setText("L'ordinateur à choisi le ciseaux");
        break;
    case 2:
        ui->lb_PrintOrdi->setText("L'ordinateur à choisi la pierre");
        break;
    case 3:
        ui->lb_PrintOrdi->setText("L'ordinateur à choisi le papier");
        break;
    default:
        break;
    }
    int result = this->CompareNumberRandomAndUserNumber(randomNumber,userNumber);
    // Aaffichage du label : user
    int ScoreUser = 0;
    int ScoreOrdi = 0;
    switch (result) {
    case 0:
        ui->lb_PrintResult->setText("égalité ");
        break;
    case 1:
        ui->lb_PrintResult->setText("Bravo vous avez gagner !");
        ScoreUser++;
        break;
    case 2:
        ui->lb_PrintResult->setText("Vous avez perdu !");
        ScoreOrdi++;
        break;
    default:
        break;
    }
    std::cout << ScoreOrdi << std::endl;
    QString scoreStringUser = QString::number(ScoreUser);
    QString scoreStringOrdi = QString::number(ScoreOrdi);
    ui->lb_Score->setText(scoreStringOrdi + " - " + scoreStringUser);
}



