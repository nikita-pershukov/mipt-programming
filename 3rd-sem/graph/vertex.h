#ifndef VERTEX_H
#define VERTEX_H

#include "!_All_include.h"

template <typename V, typename W>
class vertex {
public:
    vertex();
    vertex(V value);
    void operator=(vertex& vert);
    bool _exist = false;
    V _value;
    int _index = 0;
    int _scc = 0;
    color _col = WHITE;
    std::list<std::pair<int, W> > _neigh;
};

#include "vertex.h.impl"

#endif // VERTEX_H
