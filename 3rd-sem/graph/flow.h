#ifndef FLOW_H
#define FLOW_H

#include "!_All_include.h"

typedef std::vector<std::vector<std::pair<double, double> > > ribs;

class minCostFlow {
public:
    minCostFlow(int n);
    void AddEdge(int from, int to, double cap, double cost);
    int GetSize();
    void GetPath(ribs& flow, std::vector<int>& dist, std::vector<int>& path, double& df, int s, int t);
    std::pair<double, double> Flow(int s, int t, double max_flow);
    friend minCostFlow& operator>>(std::istream& stream, minCostFlow& flow);
private:
    ribs _data;
};

#include "flow.h.impl"

#endif // FLOW_H
