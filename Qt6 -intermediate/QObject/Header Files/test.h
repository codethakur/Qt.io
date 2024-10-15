#ifndef TEST_H
#define TEST_H

#include <QObject>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);
    ~test();

    void testing();

signals:
    void alram(QString sound);
public slots:
    void weakup(QString sound);
};

#endif // TEST_H
