#include "stuwindow.h"
#include "ui_stuwindow.h"

#include "logindialog.h"
#include <QString>
#include "util.h"
#include "connect_mysql.h"
#include <QFileDialog>
#include <QTimer>



StuWindow::StuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StuWindow)
{
    ui->setupUi(this);
    officeContent_ = ui->axWidget;
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(OpenPdf()));
    OpenPdf();
}

StuWindow::~StuWindow()
{
    delete ui;
}

void StuWindow::CloseOffice()
{
    if(this->officeContent_)
    {
        officeContent_->close();
        officeContent_->clear();
        delete officeContent_;
        officeContent_ = nullptr;
    }
}

void StuWindow::OpenPdf()
{
    this->CloseOffice();
    officeContent_ = new QAxWidget(this);
    if(!officeContent_->setControl("Adobe PDF Reader"))
        QMessageBox::critical(this, "Error", "没有安装PDF Reader！");
    this->ui->gridLayout->addWidget(officeContent_);
    officeContent_->dynamicCall("LoadFile(const QString&)","E:/Qt/Demo/test.pdf");
}


