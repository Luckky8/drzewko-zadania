#include <iostream>

#include "forest.hpp"


int main() {
    Forest f(10, 20);

    Tree* t1 = new Tree("\033[1;32m",3,'*',0,0);
    f.AddTree(t1);

    Tree* t2 = new Tree("\033[1;32m", 6, '*', 0, 2);
    f.AddTree(t2);

    f.PrintForest();

    return 0;
}