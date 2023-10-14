#include "../include/Treap.h"
#include "../include/RandomGenerator.h"

#include <vector>

Node * Treap::merge(Node * l, Node * r)
{
    if (l == nullptr) {
        return r;
    }
    else if (r == nullptr) {
        return l;
    }
    if (l->y > r->y) {
        l->right = merge(l->right, r);
        return l;
    }
    r->left = merge(l, r->left);
    return r;
}

std::pair<Node *, Node *> Treap::split(int x, Node * tree)
{
    if (tree == nullptr) {
        return std::make_pair(nullptr, nullptr);
    }
    if (tree->x < x) {
        std::pair<Node *, Node *> p = split(x, tree->right);
        tree->right = p.first;
        return std::make_pair(tree, p.second);
    }
    else {
        std::pair<Node *, Node *> p = split(x, tree->left);
        tree->left = p.second;
        return std::make_pair(p.first, tree);
    }
}

std::size_t Treap::size() const
{
    return sz;
}

void dfs(Node * v, std::vector<int> & answer)
{
    if (v == nullptr) {
        return;
    }
    dfs(v->left, answer);
    answer.push_back(v->x);
    dfs(v->right, answer);
}

std::vector<int> Treap::values() const
{
    std::vector<int> value;
    value.reserve(sz);
    dfs(root, value);
    return value;
}

bool Treap::empty() const
{
    return sz == 0;
}

bool Treap::remove(int value)
{
    if (!contains(value)) {
        return false;
    }

    auto [t1, t2] = split(value, root);

    auto [tmp, t3] = split(value + 1, t2);

    tmp->left = nullptr;
    tmp->right = nullptr;
    delete tmp;

    root = merge(t1, t3);
    sz--;

    return true;
}

bool Treap::insert(int value)
{
    if (contains(value)) {
        return false;
    }

    add(root, value, get_random_number());
    sz++;
    return true;
}

void Treap::add(Node *& node, int x, double y)
{
    if (node == nullptr) {
        node = new Node({x, y, nullptr, nullptr});
        return;
    }

    if (node->y >= y) {
        if (x < node->x) {
            add(node->left, x, y);
        }
        else {
            add(node->right, x, y);
        }
        return;
    }

    std::pair<Node *, Node *> p = split(x, node);
    node = new Node({x, y, p.first, p.second});
    return;
}

bool Treap::contains(int value) const
{
    auto tmp = root;
    while (tmp != nullptr) {
        if (tmp->x == value) {
            return true;
        }
        if (tmp->x > value) {
            tmp = tmp->left;
        }
        else {
            tmp = tmp->right;
        }
    }

    return false;
}

Treap::~Treap()
{
    if (root != nullptr) {
        delete root;
    }
}