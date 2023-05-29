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
/**
 * @brief The AuthForm class Класс для формы регистрации(или авторизации).
 */
class AuthForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthForm(QWidget *parent = nullptr);
    ~AuthForm();

private slots:
    /**
     * @brief on_reg_button_clicked слот, реагирующий на нажатие кнопки регистрации.
     */
    void on_reg_button_clicked();
    /**
     * @brief on_enter_button_clicked слот, реагирующий на нажатие кнопки входа.
     */
    void on_enter_button_clicked();
    /**
     * @brief on_exit_button_clicked слот, реагирующий на нажатие кнопки выхода.
     */
    void on_exit_button_clicked();
    /**
     * @brief on_pushButton_clicked слот, реагирующий на нажатие кнопки подключения.
     */
    void on_pushButton_clicked();
    /**
     * @brief on_label_linkActivated вывод сообщения об ошибке входа.
     * @param link араметр, в зависимости от которого появляется сообщение об ошибке входа.
     */
    void on_label_linkActivated(const QString &link);

private:
    Ui::AuthForm *ui;
    bool mode;
    /**
     * @brief change_mode Функция, отвечающая за отображение элементов в форме аутентификации.
     * @param mode Режим отображения.
     */
    void change_mode(bool mode);
    /**
     * @brief log_pass_error Функция, отвечающая за корректность введённых пароля и логина.
     * @param mode Режим отображения окошка об ошибке.
     */
    void log_pass_error(bool mode);
    //void parse_for_client(QString srt);
    //void parse();
    //QTcpSocket *socket;
    //QByteArray Data;
    //void SendToServer(QString str);
    //qint16 nextBlockSize;
signals:
    /**
     * @brief onClosed Если пользователь вышел или отключился, то форма закрывается.
     * @param log логин пользователя.
     */
    void onClosed(QString log);
public slots:
    //void slotsReadyRead();

};

#endif // AUTHFORM_H
