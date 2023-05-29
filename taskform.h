#ifndef TASKFORM_H
#define TASKFORM_H

#include <QWidget>

namespace Ui {

class TaskForm;
}
/**
 * @brief The TaskForm class
 * Класс для форм задач для заполнения.
 */
class TaskForm : public QWidget
{
    Q_OBJECT

public:
    explicit TaskForm(QWidget *parent = nullptr);
    /**
     * @brief TaskForm::~TaskForm деструктор класса TaskForm.
     */
    ~TaskForm();
    /**
     * @brief TaskForm::set_task_number функция присваивания варианта заданию.
     * @param num номер задания.
     */
    void set_task_number(int num);

private slots:
    /**
     * @brief TaskForm::on_TaskForm_sendans_clicked слот, реагирующий на нажатие кнопки отправки ответа.
     */
    void on_TaskForm_sendans_clicked();

private:
    Ui::TaskForm *ui;
    int num_of_task;
};

#endif // TASKFORM_H
