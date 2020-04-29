#ifndef BINOMIALHEAP_H
#define BINOMIALHEAP_H

#include "!_All_include.h"
#include "binomailnode.h"

template <typename V, typename Node_Comp>
class binomialHeap {
public:
    binomialHeap();
    binomialHeap(const V key);
    void Insert(const V key);
    const V GetMinimum();
    V ExtractMin();
    void Merge(binomialHeap<V, Node_Comp>& heap);
    bool Empty();
    ~binomialHeap();
private:
    node<V>* _head = NULL;
};

#include "binomialheap.h.impl"

#endif // BINOMIALHEAP_H
