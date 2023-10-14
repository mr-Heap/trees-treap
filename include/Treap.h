#pragma once

#include <cmath>
#include <vector>

struct Node
{
    int x;
    double y;
    Node *left, *right;

    ~Node()
    {
        delete left;
        delete right;
    }
};

class Treap
{
private:
    void add(Node *& node, int x, double y);
    std::size_t sz = 0;
    Node * root = nullptr;
    std::pair<Node *, Node *> split(int x, Node * tree);
    Node * merge(Node * l, Node * r);

public:
    bool contains(int value) const;
    bool insert(int value);
    bool remove(int value);
    bool empty() const;

    std::size_t size() const;
    std::vector<int> values() const;

    ~Treap();
};