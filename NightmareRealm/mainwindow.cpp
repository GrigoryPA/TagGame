#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    matrix[0][0][0]=1;matrix[0][1][0]=1;matrix[0][2][0]=1;matrix[0][3][0]=1;
    matrix[1][0][0]=1;matrix[1][1][0]=1;matrix[1][2][0]=1;matrix[1][3][0]=1;
    matrix[2][0][0]=1;matrix[2][1][0]=1;matrix[2][2][0]=1;matrix[2][3][0]=1;
    matrix[3][0][0]=0;matrix[3][1][0]=1;matrix[3][2][0]=1;matrix[3][3][0]=1;
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
        {
            matrix[i][j][1]=100*j;
            matrix[i][j][2]=100*i;
        }
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_10,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_11,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_12,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_13,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_14,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_15,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QPushButton *button = (QPushButton*)sender();
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
            if(button->x()==j*100 && button->y()==i*100)
            {
                if(j-1>=0 && matrix[i][j-1][0]==0)
                {
                    button->setGeometry(matrix[i][j-1][1],matrix[i][j-1][2],button->width(),button->height());
                    matrix[i][j-1][0]=1;
                    matrix[i][j][0]=0;
                    i=4;j=4;
                }
                else if(j+1<=3 && matrix[i][j+1][0]==0)
                {
                    button->setGeometry(matrix[i][j+1][1],matrix[i][j+1][2],button->width(),button->height());
                    matrix[i][j+1][0]=1;
                    matrix[i][j][0]=0;
                    i=4;j=4;
                }
                else if(i-1>=0 && matrix[i-1][j][0]==0)
                {
                    button->setGeometry(matrix[i-1][j][1],matrix[i-1][j][2],button->width(),button->height());
                    matrix[i-1][j][0]=1;
                    matrix[i][j][0]=0;
                    i=4;j=4;
                }
                else if(i+1<=3 && matrix[i+1][j][0]==0)
                {
                    button->setGeometry(matrix[i+1][j][1],matrix[i+1][j][2],button->width(),button->height());
                    matrix[i+1][j][0]=1;
                    matrix[i][j][0]=0;
                    i=4;j=4;
                }
            }

}

