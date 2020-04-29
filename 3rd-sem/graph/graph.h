#ifndef GRAPH_H
#define GRAPH_H

#include "!_All_include.h"
#include "vertex.h"
#include "binomialheap.h"
#include "dsu.h"

template <typename V, typename W, bool R = 0>
class graph {
public:
    graph();
    graph(int n);
    graph(const graph<V, W, R>& g);
    bool ExistValue(V value);
    bool ExistEdge(int from, int to);
    void AddVertex(int a, vertex<V, W>& v);
    void AddVertex(int a, V value);
    void AddEdge(int a, int b);
    void AddEdgeValue(V value1, V value2, W weight);
    void AddEdgeValue(V value1, V value2);
    void DeleteEdge(V value1, V value2);
    void DeleteVertex(V value);
    void StrongConnect(int a, int& ind, std::stack<int>& st, std::vector<std::set<V> >& scc);
    void Tarjan();
    void Dijkstra(int a);
    void DijkstraBinomialHeap(int a);
    void BellmanFord(int a);
    void FloydWarshall();
    void Kruskal();
    template <typename VV, typename WW, bool RR>
    friend std::ostream& operator<<(std::ostream& stream, graph<VV, WW, RR>& g);
    template <typename VV, typename WW, bool RR>
    friend std::istream& operator>>(std::istream& stream, graph<VV, WW, RR>& g);
private:
    int _n;
    bool _oriented;
    std::map<V, int> _vect;
    std::vector<vertex<V, W> > _data;
};

#include "graph.h.impl"

#endif // GRAPH_H
