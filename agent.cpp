#include "evenement.h"
#include "ui_evenement.h"

agent::agent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agent)
{
    ui->setupUi(this);
}

agent::~agent()
{
    delete ui;
}
