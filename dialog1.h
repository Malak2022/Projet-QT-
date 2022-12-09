#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>

class dialog1Data;

class dialog1
{
    Q_OBJECT
public:
    dialog1();
    dialog1(const dialog1 &);
    dialog1 &operator=(const dialog1 &);
    ~dialog1();

private:
    QSharedDataPointer<dialog1Data> data;
};

#endif // DIALOG1_H
