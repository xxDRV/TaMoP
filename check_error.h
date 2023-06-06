#ifndef CHECK_ERROR_H
#define CHECK_ERROR_H

#include <QDialog>

namespace Ui {
class check_error;
}

class check_error : public QDialog
{
    Q_OBJECT

public:
    explicit check_error(QWidget *parent = nullptr);
    ~check_error();

private:
    Ui::check_error *ui;
};

#endif // CHECK_ERROR_H
