#ifndef TREAPNODE_H
#define TREAPNODE_H

#include "!_All_include.h"

template <typename V, typename P>
class treapnode
{
public:
    treapnode();
    treapnode(V value, P priority);
    V GetValue() const;
    P GetPriority() const;
    int GetIndex() const;
    treapnode<V, P>*& GetLeft();
    treapnode<V, P>*& GetRight();
    void SetLeft(treapnode<V, P>* left);
    void SetRight(treapnode<V, P>* right);
    void RefreshIndex();
    void InOrderDelete();
private:
    V _value;
    P _priority;
    int _index = 0;
    treapnode<V, P>* _left = NULL;
    treapnode<V, P>* _right = NULL;
};

#include "treapnode.h.impl"

#endif // TREAPNODE_H
