#ifndef AUTHFORM_H
#define AUTHFORM_H

#include <QWidget>
#include <QTcpSocket>
#include<QTime>
#include<QDataStream>
#include"client_hole.h"
#include<QString>


namespace Ui {
class AuthForm;
}

class AuthForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthForm(QWidget *parent = nullptr);
    ~AuthForm();

   QString get_log();

private slots:
    void on_reg_button_clicked();

    void on_enter_button_clicked();

    void on_exit_button_clicked();

    void on_pushButton_clicked();

    void on_label_linkActivated(const QString &link);


private:
    Ui::AuthForm *ui;
    bool mode;
    void change_mode(bool mode);
    void log_pass_error(bool mode);


/*
 * signals:
    void onClosed(QString log);
*/
public slots:


};

//void change_form_main();
#endif // AUTHFORM_H
