#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

#include "forest.hpp"
using namespace std;
int u,xx,yy;

Forest::Forest(int height, int width) {
    forest_height = height;
    forest_width = width;
    matrix = new char* [height];
    for (int i = 0; i < height; i++) {
        matrix[i] = new char[width];
        for (int j = 0; j < width; j++) {
            matrix[i][j] = ' ';

        }
    }
}

void Forest::AddTree(Tree* t) {
    trees.push_back(t);
    int tree_height = t->GetHeight();
    int tree_width = 2 * tree_height - 1;
    char symbol = t->GetSymbol();
    int x = t->GetX();
    int y = t->GetY();

    string color = t->GetColor();
    int** tab = t->GetTab();
    if (forest_height < tree_height + x || forest_width < tree_width + y) {
        u = 1;
        xx = x;
        yy = y;
    }
    for (int i = 0; i < tree_height; i++) {
        for (int j = 0; j < tree_width; j++) {
            if (tab[i][j] == 1)
                matrix[x + i][y + j] = symbol;   
        }
    }
}
void Forest::PrintForest() {
    if (u == 0) {
        for (int i = 0; i < forest_height; i++) {
            for (int j = 0; j < forest_width; j++) {
                if (matrix[i][j] != ' ') {
                    cout << "\033[1;32m";
                }
                cout << matrix[i][j];
                cout << "\033[0m";
            }
                cout << std::endl;
            }
        }
    
    else {
        for (int i = 0; i < forest_height + xx; i++) {
            for (int j = 0; j < forest_width + yy; j++) {
                cout << matrix[i][j] << ' ';
            }
        }
    }
}
Forest::~Forest() {
    cout << "Kasuje las\n" << endl;
    for (int i = 0; i < forest_height; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    for (auto t : trees) {
        delete t;
    }
    trees.clear();
}