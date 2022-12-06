#include "login.h"
#include "ui_login.h"
#include"personnel.h"
#include<QMessageBox>
#include"agent.h"
#include"fournisseur.h"
#include"salle.h"
#include"equipement.h"

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

    QMessageBox msg;
        QString ID = ui->lineEdit_ID->text();
            QString mdp = ui->lineEdit_mdp->text();

            PERSONNEL p;
            if(p.login(ID,mdp)==1)

                {   agent *fenetre = new agent;

                    fenetre->show();



                msg.setText("welcome Responsable Evenement!") ; msg.exec();

                }

                else

                {if(p.login(ID,mdp)==2)

                {msg.setText ("welcome admin!") ;msg.exec() ;

                        main = new MainWindow(this);

                                   main->show();

                    }

                    if(p.login(ID,mdp)==3)

                    {msg.setText ("welcome agent fournisseur!") ;msg.exec() ;

                            fournisseur *fenetre = new fournisseur;

                                    fenetre->show();

                        }

                    if(p.login(ID,mdp)==4)

                    {msg.setText ("welcome agent salle!") ;msg.exec() ;

                            salle *fenetre = new salle;

                                    fenetre->show();

                        }

                    if(p.login(ID,mdp)==5)

                    {msg.setText ("welcome agent equipement!") ;msg.exec() ;

                            equipement *fenetre = new  equipement;

                                    fenetre->show();

                        }





                 }



                //ui->tableView->setModel(e.afficher());

                }



            void login::on_pushButton_clicked()

            {

                close();

            }
