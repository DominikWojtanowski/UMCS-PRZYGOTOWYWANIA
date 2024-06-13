#include <iostream>

#include "graph.h"

int main()
{
    Graph graph(5);

    graph.addNode('A');
    graph.addNode('B');
    graph.addNode('C');
    graph.addNode('D');
    graph.addNode('E');

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(4, 0);
    graph.addEdge(4, 2);

    std::cout << graph << std::endl;

    std::cout << graph.checkEdge(0, 1) << std::endl;

    return 0;
}