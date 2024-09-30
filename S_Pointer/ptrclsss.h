#ifndef PTRCLSSS_H
#define PTRCLSSS_H

#include <QObject>

class ptrClsss: public QObject
{
    Q_OBJECT
public:
    explicit ptrClsss(QObject * parent = nullptr);
    ~ptrClsss();

    void message(QString value = "");

    signals:
};


#endif // PTRCLSSS_H
