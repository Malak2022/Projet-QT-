#include "inserer.h"
#include "ui_inserer.h"
#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
inserer::inserer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inserer)
{
    ui->setupUi(this);
}

inserer::~inserer()
{
    delete ui;
}

void inserer::on_pushButton_clicked()
{  QString filename = QFileDialog::getOpenFileName(this,tr("choose"),"",tr(""));

    if(QString::compare(filename,QString())!=0)
    {QImage image;
        bool valid=image.load(filename);
        if(valid){

            ui->image->setText(filename);
            image=image.scaledToWidth(ui->img_name->width(),Qt::SmoothTransformation);
            ui->img_name->setPixmap(QPixmap::fromImage(image));

        }
        else
        {
            QMessageBox::information(this, tr("ERROR"), QString(tr("Not Valid!")));

}
}
}
