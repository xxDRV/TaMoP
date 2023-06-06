#include "checking.h"
#include "ui_checking.h"

Checking::Checking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Checking)
{
    ui->setupUi(this);
}

Checking::~Checking()
{
    delete ui;
}
