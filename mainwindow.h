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
    int GenerateNumberRandom();
    int CompareNumberRandomAndUserNumber(int random,int user);
    ~MainWindow(); //destruteur
public slots:
    void ProcessGame();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
