#ifndef TASKFORM_H
#define TASKFORM_H

#include <QWidget>
#include<string>
#include<QString>

namespace Ui {
class TaskForm;
}

class TaskForm : public QWidget
{
    Q_OBJECT

public:
    explicit TaskForm(QWidget *parent = nullptr);
    ~TaskForm();
    void set_task_number(int num);

private slots:
    void on_TaskForm_sendans_clicked();

private:
    Ui::TaskForm *ui;
    int num_of_task;
};

#endif // TASKFORM_H
