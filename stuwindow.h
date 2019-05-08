#ifndef STUWINDOW_H
#define STUWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <ActiveQt/QAxWidget>
#include "logindialog.h"


namespace Ui {
class StuWindow;
}

class StuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StuWindow(QWidget *parent = nullptr);
    ~StuWindow();

    QAxWidget *officeContent_;

public slots:
    void CloseOffice();
    void OpenPdf();


private:
    Ui::StuWindow *ui;
};

#endif // STUWINDOW_H

