#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) //constructeur
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->btn_Test, SIGNAL(clicked(bool)), this ,SLOT(testClick()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::BoutonClicked()
{
    //Retourne le bouton le cliqué (ciseaux =1 &  pierre =2  & feuille =3)
    if((ui->))
}
/*
void MainWindow::testClick()
{
    ui->lab_TestOK->setText("J'ai cliqué");

}
*/




// 1 < 2 // 1 > 3 //
// 2 > 1 // 2 < 3 //
// 3 > 2 // 3 < 1 //
