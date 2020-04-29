#ifndef DSU_H
#define DSU_H

#include "!_All_include.h"

template <typename V>
class dsu
{
public:
    dsu(V n);
    void MakeSet(V a);
    V FindSet(V a);
    void Union(V a, V b);
private:
    std::vector<V> _parent;
    std::vector<V> _rank;
};

#include "dsu.h.impl"

#endif // DSU_H
