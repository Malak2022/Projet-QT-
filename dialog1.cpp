#include "dialog1.h"
#include "ui_dialog1.h"

class dialog1Data : public QSharedData
{
public:

};

dialog1::dialog1() : data(new dialog1Data)
{

}

dialog1::dialog1(const dialog1 &rhs) : data(rhs.data)
{

}

dialog1 &dialog1::operator=(const dialog1 &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

