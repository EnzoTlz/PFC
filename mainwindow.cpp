#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include <iostream>

#define CISEAUX 1
#define PIERRE 2
#define PAPIER 3
#define USER 1
#define ORDI 2
#define EQUALS 0
#define WIN 1
#define LOOSE 2

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

int MainWindow::GetWinnerOfTheRound(int random, int user)
{
    if(random == CISEAUX  && user == PIERRE){ return USER; }
    else if(random == PIERRE && user == PAPIER){ return USER; }
    else if(random == PAPIER && user == CISEAUX){ return USER; }
    else if(random == user){ return EQUALS; }
    else{ return ORDI; }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ProcessGame()
{
    QPushButton *ButtonClicked  = qobject_cast<QPushButton*>(sender());

    int randomNumber = this->GenerateNumberRandom();
    int userNumber = this->GetButtonClicked(ButtonClicked);
    this->setImageInUserLabel(userNumber);
    this->setImageInOrdiLabel(randomNumber);

    int winner = this->GetWinnerOfTheRound(randomNumber,userNumber);
    this->PrintResultatOfTheRound(winner);
    this->SetScore(winner);
    this->PrintScore(this->GetScoreUser(),this->GetScoreOrdi());

}

void MainWindow::SetScore(int winner)
{
    switch (winner) {
        case EQUALS:
            break;
        case WIN:
            score.ScoreUser = score.ScoreUser +1;
            break;
        case LOOSE:
            score.ScoreOrdi = score.ScoreOrdi +1;
            break;
        default:
            break;
    }
}

int MainWindow::GetScoreUser()
{
    return this->score.ScoreUser;
}

int MainWindow::GetScoreOrdi()
{
    return this ->score.ScoreOrdi;
}

void MainWindow::PrintScore(int scoreUser, int scoreOrdi)
{
    QString scoreStringUser = QString::number(scoreUser);
    QString scoreStringOrdi = QString::number(scoreOrdi);
    ui->lb_Score->setText(scoreStringUser + " - " + scoreStringOrdi);
}

void MainWindow::setImageInOrdiLabel(int value)
{
    ui->lb_ImgOrdi->setFixedHeight(300);
    ui->lb_ImgOrdi->setFixedWidth(300);
    switch (value) {
        case CISEAUX:
        ui->lb_ImgOrdi->setPixmap(QPixmap(":/Pictures/ciseaux.png"));
            break;
        case PIERRE:
            ui->lb_ImgOrdi->setPixmap(QPixmap(":/Pictures/pierre.png"));
            break;
        case PAPIER:
            ui->lb_ImgOrdi->setPixmap(QPixmap(":/Pictures/feuille.png"));
            break;
        default:
            break;
    }
}

void MainWindow::setImageInUserLabel(int userValue)
{
    ui->lb_ImgUser->setFixedHeight(300);
    ui->lb_ImgUser->setFixedWidth(300);
    switch (userValue) {
        case CISEAUX:
        ui->lb_ImgUser->setPixmap(QPixmap(":/Pictures/ciseaux.png"));
            break;
        case PIERRE:
            ui->lb_ImgUser->setPixmap(QPixmap(":/Pictures/pierre.png"));
            break;
        case PAPIER:
            ui->lb_ImgUser->setPixmap(QPixmap(":/Pictures/feuille.png"));
            break;
        default:
            break;
    }
}

int MainWindow::GetButtonClicked(QPushButton *ButtonClicked)
{
    int userValue = 0;
    if(ButtonClicked == ui->btn_Ciseaux){ userValue = CISEAUX; }
    else if(ButtonClicked == ui->btn_Pierre){ userValue = PIERRE; }
    else if(ButtonClicked == ui->btn_Papier){ userValue = PAPIER; }
    return userValue;
}

void MainWindow::PrintResultatOfTheRound(int winner)
{
    switch (winner) {
        case EQUALS:
            ui->lb_PrintResult->setText("égalité ");
            break;
        case WIN:
            ui->lb_PrintResult->setText("Vous avez gagner !");
            break;
        case LOOSE:
            ui->lb_PrintResult->setText("Vous avez perdu !");
            break;
        default:
            break;
    }
}



