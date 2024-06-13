#include "graph.h"
#include <iterator>

Graph::Graph(int size) : size{size}
{
    this->listArr = new std::forward_list<Node>[5];
}
Graph::~Graph()
{
    delete[] listArr;
}

void Graph::addNode(const Node &node)
{
    listArr[nodesArrCurrIndex++].emplace_front(node);
}
void Graph::addEdge(int src, int dst)
{
    std::forward_list<Node> *list = &listArr[src];
    Node &node = listArr[dst].front();

    // std::cout << node->data << "->" << &(*node) << std::endl;
    auto it = list->begin();
    for (; (std::next(it)) != list->end(); it++)
    {
        // std::cout << "??" << std::endl;
    }
    list->emplace_after(it, node);
    //  std::cout << &(*it) << std::endl;
}

bool Graph::checkEdge(int src, int dst)
{
    std::forward_list<Node> *list = &listArr[src];
    Node *dstNode = &listArr[dst].front();

    for (auto it = list->begin(); it != list->end(); it++)
    {
        if ((*it).data == dstNode->data) // Porównaj wskaźniki do węzłów
            return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Graph &graph)
{
    for (size_t i = 0; i < graph.size; i++)
    {
        for (auto it = graph.listArr[i].begin(); it != graph.listArr[i].end(); it++)
        {
            std::cout << (*it).data << ", " << &(*it) << "-> ";
        }
        std::cout << std::endl;
    }

    return os;
}