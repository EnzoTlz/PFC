#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent) //constructeur
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn_Ciseaux, SIGNAL(clicked(bool)), this ,SLOT(PrintButtonCliked()));
    connect(ui->btn_Papier, SIGNAL(clicked(bool)), this ,SLOT(PrintButtonCliked()));
    connect(ui->btn_Pierre, SIGNAL(clicked(bool)), this ,SLOT(PrintButtonCliked()));
    int test = GenerateNumberRandom();
    std::cout << test << std::endl;
}

int MainWindow::GenerateNumberRandom()
{
    //
    return rand()%(1-3+1)+1;
}

MainWindow::~MainWindow()
{
    delete ui;
}


//Afficher le texte recu en parametre
void MainWindow::PrintButtonCliked()
{
    QPushButton *ButtonClicked  = qobject_cast<QPushButton*>(sender());

    if((ButtonClicked == ui->btn_Ciseaux)){
        ui->lb_PrintResult->setText("1");
    }else if(ButtonClicked == ui->btn_Papier){
        ui->lb_PrintResult->setText("3");
    }else if(ButtonClicked == ui->btn_Pierre){
        ui->lb_PrintResult->setText("2");
    }

}



// 1 < 2 // 1 > 3 //
// 2 > 1 // 2 < 3 //
// 3 > 2 // 3 < 1 //
