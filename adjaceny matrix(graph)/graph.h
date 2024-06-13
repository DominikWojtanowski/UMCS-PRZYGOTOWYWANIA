#pragma once

#include "node.h"
#include <iostream>

class Graph
{
    int **matrix;
    Node *nodesArr;
    int size;
    int nodesArrCurrIndex{};

public:
    Graph(int);
    virtual ~Graph();

    void addNode(char);
    void addEdge(int src, int ds);
    bool checkEdge(int src, int ds);

    friend std::ostream &operator<<(std::ostream &, const Graph &);
};