#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushVoid_clicked();

private:
    Ui::MainWindow *ui;
    int matrix[5][5][3];
    int sel_action=1;
    int sel_button[2];
    int num_block_w=5;
    int num_block_h=5;
    int size_block=100;
    int size_label=50;
    int flag_vin=0;
    QPushButton *sel_button_ui;
};
#endif // MAINWINDOW_H
