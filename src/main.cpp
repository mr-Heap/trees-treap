#include "../include/Treap.h"

#include <iostream>

int main()
{
    Treap tree;

    for (int i = 10; i > 0; --i) {
        tree.insert(i);
        std::cout << tree.contains(i) << '\n';
    }

    for (const auto value : tree.values()) {
        std::cout << value << std::endl; // 1 .. 10
    }
}
