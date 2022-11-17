#include "login.h"
#include "ui_login.h"
#include"personnel.h"
#include<QMessageBox>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pb_login_clicked()
{
    QString ID = ui->lineEdit_ID->text();
        QString mdp = ui->lineEdit_mdp->text();

        QSqlQuery query;


             query.prepare(("SELECT *FROM PERSONNEL WHERE ID_PERSONNEL=:ID_PERSONNEL AND PASSWORD=:PASSWORD"));
             query.bindValue(":ID_PERSONNEL",ID);
             query.bindValue(":PASSWORD",mdp);
             query.exec();
             if(query.next())
             {

                 main = new MainWindow(this);
                            main->show();
                            }

                            else{
                                QMessageBox::critical(this,"Error","Wrong password or ID");
                            }

}
