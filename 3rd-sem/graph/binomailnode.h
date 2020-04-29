#ifndef BINOMAILNODE_H
#define BINOMAILNODE_H

#include "!_All_include.h"

template <typename V>
class node
{
public:
    node();
    node(const V key);
    node* GetChild();
    int GetDegree() const;
    V GetKey() const;
    node* GetSib();
    void SetChild(node* child);
    void SetDegree(const int degree);
    void SetKey(const V key);
    void SetSib(node *sib);
    void InOrderDelete();
private:
    V _key;
    int _degree = 0;
    node* _child = NULL;
    node* _sib = NULL;
};

#include "binomailnode.h.impl"

#endif // BINOMAILNODE_H
