#ifndef INSERER_H
#define INSERER_H

#include <QDialog>

namespace Ui {
class inserer;
}

class inserer : public QDialog
{
    Q_OBJECT

public:
    explicit inserer(QWidget *parent = nullptr);
    ~inserer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::inserer *ui;
};

#endif // INSERER_H
