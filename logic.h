#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>

class Logic : public QObject
{
    Q_OBJECT
private:
    Logic(QObject *parent = 0);
    ~Logic();
    static Logic *logic;
public:
    static Logic *get();
};

#endif // LOGIC_H
