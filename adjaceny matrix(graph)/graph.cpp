#include "graph.h"

Graph::Graph(int size) : size{size}
{
    matrix = new int *[size];
    nodesArr = new Node[5];
    for (size_t i = 0; i < size; i++)
        matrix[i] = new int[size]{};
}
Graph::~Graph()
{

    for (size_t i = 0; i < size; i++)
        delete[] matrix[i];
    delete[] matrix;
}

void Graph::addEdge(int src, int dst)
{
    matrix[src][dst] = 1;
}
void Graph::addNode(char noteData)
{
    nodesArr[nodesArrCurrIndex++].changeData(noteData);
}
bool Graph::checkEdge(int src, int dst)
{
    return matrix[src][dst] == 1;
}

std::ostream &operator<<(std::ostream &os, const Graph &graph)
{
    os << "  ";
    for (size_t i = 0; i < graph.size; i++)
    {
        os << graph.nodesArr[i].data << " ";
    }
    os << std::endl;

    for (size_t i = 0; i < graph.size; i++)
    {
        os << graph.nodesArr[i].data << " ";
        for (size_t j = 0; j < graph.size; j++)
            os << graph.matrix[i][j] << " ";
        os << std::endl;
    }
    return os;
}