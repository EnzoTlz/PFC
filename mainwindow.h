#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    int CompareNumberRandomAndUserNumber(int random,int user);
    void SetVisibilityLabelFalse();
    void SetScore(int user , int random);

public slots:
    void ProcessGame();


private:
    Ui::MainWindow *ui;
    int ScoreUser = 0;
    int ScoreOrdi = 0;
};
#endif // MAINWINDOW_H
