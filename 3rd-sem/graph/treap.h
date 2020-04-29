#ifndef TREAP_H
#define TREAP_H

#include "!_All_include.h"
#include "treapnode.h"

template <typename V, typename P>
class treap
{
public:
    treap();
    void Insert(V value);
    void Insert(V value, P priority);
    void Insert(treapnode<V, P> *item);
    V FindIndex(int index);
    int GetSize();
    V GetValue();
    P GetPriority();
    void Merge(treap<V, P> l, treap<V, P> r);
    void Split(treap<V, P>& l, treap<V, P>& r, V value);
    void Erase(V value);
    void InOrderDelete();
    ~treap();
private:
    treapnode<V, P>* GetRoot();
    void SetRoot(treapnode<V, P>* root);
    void Insert(treapnode<V, P>*& t, treapnode<V, P> *item);
    void Merge(treapnode<V, P>* &t, treapnode<V, P> *l, treapnode<V, P> *r);
    void Split(treapnode<V, P> *t, treapnode<V, P>* &l, treapnode<V, P>* &r, V value);
    void Erase(treapnode<V, P>*& t, V value);
    treapnode<V, P>* _root = NULL;
};

#include "treap.h.impl"

#endif // TREAP_H
