#ifndef OBJECTCLASS_H
#define OBJECTCLASS_H

class ObjectClass
{
public:
    ObjectClass();
    ObjectClass(const ObjectClass &) = delete;
    ObjectClass &operator=(const ObjectClass &) = delete;
};

#endif // OBJECTCLASS_H
