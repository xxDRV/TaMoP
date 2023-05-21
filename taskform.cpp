#include "taskform.h"
#include "ui_taskform.h"

TaskForm::TaskForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskForm)
{
    this->num_of_task = 0;
    ui->setupUi(this);
    //ui->TaskForm_enterans = nullptr;
}

TaskForm::~TaskForm()
{
    delete ui;
}

void TaskForm::set_task_number(int num)
{
    this->num_of_task = num;
    ui->TaskForm_variant->setText("Variant"+QString::number(num));
    //ui->TaskForm_variant->setText(generate_variant(num));
    ui->TaskForm_task->setText("Task # " +QString::number(num));
    //ui->TaskForm_task->setText(get_text_of_task(num));
}

void TaskForm::on_TaskForm_sendans_clicked()
{
    qDebug()<<"check_task&"+
              QString::number(this->num_of_task)+"&"
          +ui->TaskForm_variant->text()+"&"
         +ui->TaskForm_enterans->toPlainText();
}

