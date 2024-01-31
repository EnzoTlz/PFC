#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); //destruteur
    int GenerateNumberRandom();
    int GetWinnerOfTheRound(int random,int user);
    void SetScore(int winner);
    int GetScoreUser();
    int GetScoreOrdi();
    void PrintScore(int scoreUser , int scoreOrdi);
    void setImageInOrdiLabel(int value);
    void setImageInUserLabel(int userValue);
    int GetButtonClicked(QPushButton *ButtonClicked);
    void PrintResultatOfTheRound(int winner);

public slots:
    void ProcessGame();


private:
    Ui::MainWindow *ui;
    struct{
        int ScoreUser = 0;
        int ScoreOrdi = 0;
    }score;
};
#endif // MAINWINDOW_H
