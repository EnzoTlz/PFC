#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

#define CISEAUX 1

//

MainWindow::MainWindow(QWidget *parent) //constructeur
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->SetVisibilityLabelFalse();

    connect(ui->btn_Ciseaux, SIGNAL(clicked(bool)), this ,SLOT(ProcessGame()));
    connect(ui->btn_Papier, SIGNAL(clicked(bool)), this ,SLOT(ProcessGame()));
    connect(ui->btn_Pierre, SIGNAL(clicked(bool)), this ,SLOT(ProcessGame()));

}

int MainWindow::GenerateNumberRandom()
{
    return rand()% 3+1;
}

int MainWindow::CompareNumberRandomAndUserNumber(int random, int user) //changer le nom
{
    // 1 ==> user win       //Ciseaux === 1
    // 2 ==> ordi win       //Pierre === 2
    // 0 ==> egalite        //papier === 3


    // 1 < 2 // 1 > 3 //
    // 2 > 1 // 2 < 3 //
    // 3 > 2 // 3 < 1 //

    if(random == CISEAUX  && user == 2){
        return 1;
    }else if(random == 2 && user ==3){
        return 1;
    }else if(random == 3 && user ==CISEAUX){
        return 1;
    }else if(random == user){
        return 0;
    }else{ return 2; }
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

    //Affichage du label : user
    if((ButtonClicked == ui->btn_Ciseaux)){
        userNumber = CISEAUX;
        ui->lb_CiseauxUser->setVisible(true);
        ui->lb_FeuilleUser->setVisible(false);
        ui->lb_PierreUser->setVisible(false);
    }else if(ButtonClicked == ui->btn_Pierre){
        userNumber = 2;
        ui->lb_CiseauxUser->setVisible(false);
        ui->lb_FeuilleUser->setVisible(false);
        ui->lb_PierreUser->setVisible(true);
    }else if(ButtonClicked == ui->btn_Papier){
        userNumber = 3;
        ui->lb_CiseauxUser->setVisible(false);
        ui->lb_FeuilleUser->setVisible(true);
        ui->lb_PierreUser->setVisible(false);
    }
    // Affichage du label : ordinateurs
    switch (randomNumber) {
    case CISEAUX:
        ui->lb_FeuilleOrdi->setVisible(false);
        ui->lb_PierreOrdi->setVisible(false);
        ui->lb_CiseauxOrdi->setVisible(true);
        break;
    case 2:
        ui->lb_FeuilleOrdi->setVisible(false);
        ui->lb_PierreOrdi->setVisible(true);
        ui->lb_CiseauxOrdi->setVisible(false);
        break;
    case 3:
        ui->lb_FeuilleOrdi->setVisible(true);
        ui->lb_PierreOrdi->setVisible(false);
        ui->lb_CiseauxOrdi->setVisible(false);
        break;
    default:
        break;
    }
    int result = this->CompareNumberRandomAndUserNumber(randomNumber,userNumber);

    // Affichage du label : Résulat
    switch (result) {
    case 0:
        ui->lb_PrintResult->setText("égalité ");
        break;
    case 1:
        ui->lb_PrintResult->setText("Vous avez gagner !");
        this->SetScore(1,0);
        break;
    case 2:
        ui->lb_PrintResult->setText("Vous avez perdu !");
        this->SetScore(0,1);
        break;
    default:
        break;
    }

}

void MainWindow::SetVisibilityLabelFalse()
{
    ui->lb_CiseauxOrdi->setVisible(false);
    ui->lb_FeuilleOrdi->setVisible(false);
    ui->lb_PierreOrdi->setVisible(false);

    ui->lb_CiseauxUser->setVisible(false);
    ui->lb_FeuilleUser->setVisible(false);
    ui->lb_PierreUser->setVisible(false);
}

void MainWindow::SetScore(int user, int random)
{

    this->ScoreUser = this->ScoreUser + user;
    this->ScoreOrdi = this->ScoreOrdi + random;
    QString scoreStringUser = QString::number(this->ScoreUser);
    QString scoreStringOrdi = QString::number(this->ScoreOrdi);
    ui->lb_Score->setText(scoreStringOrdi + " - " + scoreStringUser);
}



