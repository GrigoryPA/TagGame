#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //-1 rock, 0 void, (1,2,3) moveable blocks
    matrix[0][0][0]=3;matrix[0][1][0]=-1;matrix[0][2][0]=2;matrix[0][3][0]=-1;matrix[0][4][0]=3;
    matrix[1][0][0]=1;matrix[1][1][0]=0;matrix[1][2][0]=2;matrix[1][3][0]=0;matrix[1][4][0]=3;
    matrix[2][0][0]=2;matrix[2][1][0]=-1;matrix[2][2][0]=1;matrix[2][3][0]=-1;matrix[2][4][0]=1;
    matrix[3][0][0]=3;matrix[3][1][0]=0;matrix[3][2][0]=3;matrix[3][3][0]=0;matrix[3][4][0]=2;
    matrix[4][0][0]=1;matrix[4][1][0]=-1;matrix[4][2][0]=1;matrix[4][3][0]=-1;matrix[4][4][0]=2;
    for(int i=0;i<num_block_h;++i)
        for(int j=0;j<num_block_w;++j)
        {
            matrix[i][j][1]=size_block*j;
            matrix[i][j][2]=size_block*i+size_label;
        }
    connect(ui->pushBlue_1,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushBlue_2,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushBlue_3,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushBlue_4,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushBlue_5,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushYellow_1,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushYellow_2,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushYellow_3,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushYellow_4,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushYellow_5,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushRed_1,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushRed_2,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushRed_3,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushRed_4,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushRed_5,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
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
        j=button->x()/size_block;
        i=(button->y()-size_label)/size_block;
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
                matrix[i][j][0]=matrix[sel_button[0]][sel_button[1]][0];
                matrix[sel_button[0]][sel_button[1]][0]=0;
                sel_action=1;

                flag_vin=1;
                for(int i=0;i<num_block_h;++i)
                    if(matrix[i][0][0]!=1) flag_vin=0,i=num_block_h;
                for(int i=0;i<num_block_h;++i)
                    if(matrix[i][2][0]!=2) flag_vin=0,i=num_block_h;
                for(int i=0;i<num_block_h;++i)
                    if(matrix[i][4][0]!=3) flag_vin=0,i=num_block_h;
                if(flag_vin==1)
                {
                    if(QMessageBox::information(this,"Победа!","Вы победили!",QMessageBox::Ok)==QMessageBox::Ok)
                        QApplication::quit();
                }

            }
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
        QPushButton *button = (QPushButton*)sender();
        int j=button->x()/size_block;
        int i=(button->y()-size_label)/size_block;
        sel_button[0]=i;
        sel_button[1]=j;
        int num=0;
        if(j-1>=0 && matrix[i][j-1][0]==0)
            ++num;
        if(j+1<=num_block_w-1 && matrix[i][j+1][0]==0)
            ++num;
        if(i-1>=0 && matrix[i-1][j][0]==0)
            ++num;
        if(i+1<=num_block_h-1 && matrix[i+1][j][0]==0)
            ++num;
        if(num>0)
        {
            sel_action=2;
            sel_button_ui=button;
        }
}

