#include "taskform.h"
#include "ui_taskform.h"

/**
 * @brief TaskForm::TaskForm конструктор класса TaskForm.
 * @param parent предок класса TaskForm.
 */
TaskForm::TaskForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskForm)
{
    this->num_of_task = 0;
    ui->setupUi(this);
    //ui->TaskForm_enterans = nullptr;
}
/**
 * @brief TaskForm::~TaskForm деструктор класса TaskForm.
 */
TaskForm::~TaskForm()
{
    delete ui;
}
/**
 * @brief TaskForm::set_task_number функция присваивания варианта заданию.
 * @param num номер задания.
 */
void TaskForm::set_task_number(int num)
{
    this->num_of_task = num;
    ui->TaskForm_variant->setText("Variant"+QString::number(num));
    //ui->TaskForm_variant->setText(generate_variant(num));
    ui->TaskForm_task->setText("Task # " +QString::number(num));
    //ui->TaskForm_task->setText(get_text_of_task(num));
}
/**
 * @brief TaskForm::on_TaskForm_sendans_clicked слот, реагирующий на нажатие кнопки отправки ответа.
 */
void TaskForm::on_TaskForm_sendans_clicked()
{
    qDebug()<<"check_task&"+
              QString::number(this->num_of_task)+"&"
          +ui->TaskForm_variant->text()+"&"
         +ui->TaskForm_enterans->toPlainText();
}

