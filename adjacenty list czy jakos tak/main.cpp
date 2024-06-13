#include <iostream>
#include "graph.h"

int main()
{
    Graph graph(5);
    graph.addNode(Node('A'));
    graph.addNode(Node('B'));
    graph.addNode(Node('C'));
    graph.addNode(Node('D'));
    graph.addNode(Node('E'));

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(4, 0);
    graph.addEdge(4, 2);

    std::cout << graph.checkEdge(0, 1) << std::endl;

    std::cout << graph;

    return 0;
}