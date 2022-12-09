#ifndef SUPP_H
#define SUPP_H

#include <QDialog>

namespace Ui {
class supp;
}

class supp : public QDialog
{
    Q_OBJECT

public:
    explicit supp(QWidget *parent = nullptr);
    ~supp();

private slots:
    void pushButton_3();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::supp *ui;
};

#endif // SUPP_H
