#ifndef LOGIN_H
#define LOGIN_H
#include"mainwindow.h"
#include <QMainWindow>
#include"personnel.h"
#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
     login(QWidget *parent = nullptr);
    ~login();

signals:
    void PageAccueil();

    private slots:

    void on_pb_login_clicked();

private:
    Ui::login *ui;
    MainWindow *main;
    QSqlDatabase db;

};

#endif // LOGIN_H
