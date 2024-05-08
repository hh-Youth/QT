#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include"testwidget.h"
#include"testdialog.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //cout<<"自定义MainWindow的构造函数"<<endl;
    ui->setupUi(this);  //c++对象和ui绑定
    //移动窗口X、Y轴坐标(左上角为原点)
    this->move(100,100);
    //初始化操作(窗口、数据...)
    //显示当前窗口的时候，显示另外一个窗口TestWidget
    TestWidget* testwidget = new TestWidget(this);  //this指定父类 explicit TestWidget(QWidget *parent = nullptr);
    //testwidget->show();
#if 0
    //创建对话框窗口Dialog
    TestDialog* testdialog = new TestDialog();
    //非模态
    testdialog->show();
 #else
    //创建对话框窗口Dialog
    TestDialog* testdialog = new TestDialog();
    //模态,exec()阻塞程序的执行
    testdialog->exec();

 #endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

