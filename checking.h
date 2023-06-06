#ifndef CHECKING_H
#define CHECKING_H

#include <QDialog>

namespace Ui {
class Checking;
}

class Checking : public QDialog
{
    Q_OBJECT

public:
    explicit Checking(QWidget *parent = nullptr);
    ~Checking();

private:
    Ui::Checking *ui;
};

#endif // CHECKING_H
