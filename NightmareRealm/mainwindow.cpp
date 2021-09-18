#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //-1 rock, 0 void, (1,2,3) moveable blocks
    matrix[0][0][0]=1;matrix[0][1][0]=1;matrix[0][2][0]=1;matrix[0][3][0]=1;
    matrix[1][0][0]=1;matrix[1][1][0]=1;matrix[1][2][0]=1;matrix[1][3][0]=1;
    matrix[2][0][0]=-1;matrix[2][1][0]=-1;matrix[2][2][0]=1;matrix[2][3][0]=1;
    matrix[3][0][0]=0;matrix[3][1][0]=0;matrix[3][2][0]=0;matrix[3][3][0]=0;
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
    connect(ui->voidButton_1,SIGNAL(clicked()),this,SLOT(on_pushVoid_clicked()));
    connect(ui->voidButton_2,SIGNAL(clicked()),this,SLOT(on_pushVoid_clicked()));
    connect(ui->voidButton_3,SIGNAL(clicked()),this,SLOT(on_pushVoid_clicked()));
    connect(ui->voidButton_4,SIGNAL(clicked()),this,SLOT(on_pushVoid_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushVoid_clicked()
{
    if(sel_action==2)
    {
        QPushButton *button = (QPushButton*)sender();
        int i,j;
        j=button->x()/100;
        i=button->y()/100;
        if(matrix[i][j][0]==0)
        {
            if((i==sel_button[0]&&j==sel_button[1]-1)||(i==sel_button[0]&&j==sel_button[1]+1)||
                    (i==sel_button[0]-1&&j==sel_button[1])||(i==sel_button[0]+1&&j==sel_button[1]))
            {
                sel_button_ui->setGeometry(matrix[i][j][1],
                        matrix[i][j][2],
                        sel_button_ui->width(),
                        sel_button_ui->height());
                button->setGeometry(matrix[sel_button[0]][sel_button[1]][1],
                        matrix[sel_button[0]][sel_button[1]][2],
                        button->width(),
                        button->height());
                matrix[sel_button[0]][sel_button[1]][0]=0;
                matrix[i][j][0]=1;
                sel_action=1;
            }
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
        QPushButton *button = (QPushButton*)sender();
        int j=button->x()/100;
        int i=button->y()/100;
        sel_button[0]=i;
        sel_button[1]=j;
        int num=0;
        if(j-1>=0 && matrix[i][j-1][0]==0)
        {
            ++num;
        }
        if(j+1<=3 && matrix[i][j+1][0]==0)
        {
            ++num;
        }
        if(i-1>=0 && matrix[i-1][j][0]==0)
        {
            ++num;
        }
        if(i+1<=3 && matrix[i+1][j][0]==0)
        {
            ++num;
        }
        if(num>0)
        {
            sel_action=2;
            sel_button_ui=button;
        }
}

