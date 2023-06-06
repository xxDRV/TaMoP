#include "taskform.h"
#include "ui_taskform.h"
#include"client_hole.h"

using namespace std;
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
   // ui->TaskForm_variant->setText("Variant"+QString::number(num));
    //ui->TaskForm_variant->setText(generate_variant(num));
    ui->TaskForm_task->setText("Task # " +QString::number(num));
    //ui->TaskForm_task->setText(get_text_of_task(num));
    if (num<=3){
        string task = "";

            for(int i=0;i<8;i++){
                string mid = to_string(i);
                if(rand()%2==1){
                    task+=mid;
                    task+=",";
                }
            }
            string res = "";
            for(int i=0; i<task.size()-1;i++){
                res+=task[i];
            }

            QString res1 = QString::fromStdString(res);
            qDebug()<<res1;
            if (num == 1){
                ui->TaskForm_task->setText("Проверьте функцию, заданную\n множеством М1 на монотонность\n ");
            }
            if (num == 2){
                 ui->TaskForm_task->setText("Проверьте функцию, заданную\n множеством М1 на самодвойственность\n ");
            }
            if (num == 3){
                 ui->TaskForm_task->setText("Постройте функцию, двойственную\n функции заданной множеством М0\n ");
            }
         ui->TaskForm_variant->setText(res1);
    }
    else if(num == 4){
        string task = "";

        for(int i=0;i<16;i++){
            string s = to_string(rand()%2);
            task+=s;
            //cout<<rand()%2;
        }
        QString res = QString::fromStdString(task);
        ui->TaskForm_task->setText("Постройте карту Карно для данной функции\n ");
        ui->TaskForm_variant->setText(res);

    }
    else{
        //Генератор задачи для Дамира
    }
}

void TaskForm::on_TaskForm_sendans_clicked()
{
    qDebug()<<"check_task+"+
              QString::number(this->num_of_task)+"+"
          +ui->TaskForm_variant->text()+"+"
         +ui->TaskForm_enterans->toPlainText();
    Client_hole::get_instance()->SendToServer("check_task+"+
                                              QString::number(this->num_of_task)+"+"
                                          +ui->TaskForm_variant->text()+"+"
                                         +ui->TaskForm_enterans->toPlainText());

}

