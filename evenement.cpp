#include "agent.h"
#include "ui_agent.h"

evenement::evenement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::evenement)
{
    ui->setupUi(this);
}

evenement::~evenement()
{
    delete ui;
}
