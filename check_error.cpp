#include "check_error.h"
#include "ui_check_error.h"

check_error::check_error(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::check_error)
{
    ui->setupUi(this);
}

check_error::~check_error()
{
    delete ui;
}
