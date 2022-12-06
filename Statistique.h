#ifndef STATISTIQUE_H
#define STATISTIQUE_H


#include <QWidget>

namespace Ui {
class stat;
}

class stati: public QWidget
{
    Q_OBJECT

public:
    explicit stati(QWidget *parent = nullptr);
    ~stati();
    void makePolt();

private:
    Ui::stat *ui;
};

#endif // STAT_H
