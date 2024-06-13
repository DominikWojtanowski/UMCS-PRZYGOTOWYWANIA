#pragma once

#include "node.h"
#include <iostream>
#include <forward_list>

class Graph
{
    std::forward_list<Node> *listArr;
    int size;
    int nodesArrCurrIndex{};

public:
    Graph(int);
    virtual ~Graph();

    void addNode(const Node &);
    void addEdge(int src, int ds);
    bool checkEdge(int src, int ds);

    friend std::ostream &operator<<(std::ostream &, const Graph &);
};