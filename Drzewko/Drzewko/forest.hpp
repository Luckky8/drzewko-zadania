#ifndef FOREST_HPP
#define FOREST_HPP
#include <vector>
#include "tree.hpp"

using namespace std;

class Forest {
public:
	Forest(int height, int width);
	~Forest();
	void AddTree(Tree* t);
	void PrintForest();
	vector<Tree*> trees;
private:
	char** matrix;
	int forest_height;
	int forest_width;
};

#endif
