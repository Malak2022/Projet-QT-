#ifndef AGENT_H
#define AGENT_H

#include <QDialog>
#include"mainwindow.h"
#include <QMainWindow>
#include"personnel.h"
#include <QDialog>

namespace Ui {
class agent;
}

class agent : public QDialog
{
    Q_OBJECT

public:
     agent(QWidget *parent = nullptr);
    ~agent();

    private slots:



private:
    Ui::agent *ui;
    MainWindow *main;
    QSqlDatabase db;

};

#endif // AGENT_H
