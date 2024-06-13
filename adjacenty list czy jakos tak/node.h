#pragma once

class Node
{
public:
    Node() = default;
    Node(char);
    virtual ~Node();
    Node *next{nullptr};

    void changeData(char);
    char data;
};