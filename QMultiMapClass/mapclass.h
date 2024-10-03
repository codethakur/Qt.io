#ifndef MAPCLASS_H
#define MAPCLASS_H

#include <QObject>

class MapClass : public QObject
{
    Q_OBJECT
public:
    explicit MapClass(QObject *parent = nullptr);
    ~MapClass();

    // Getter functions
    QString name() const;
    int id() const;

    // Setter functions
    void SetName(const QString &name);
    void SetId(int id);

signals:

private:
    QString m_name;
    int m_id;
};

#endif // MAPCLASS_H
