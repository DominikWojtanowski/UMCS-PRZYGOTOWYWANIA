#pragma once

class Node
{

public:
    Node() = default;
    Node(char);
    void changeData(char);
    virtual ~Node();
    char data;
};