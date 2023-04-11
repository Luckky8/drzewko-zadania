#include <string>
#include <iostream>

using namespace std;


class Tree {
private:
	string color;
	int height;
	char symbol;
	int xx;
	int yy;
	int** tab;
public:
	Tree(string c, int h, char s,int x, int y);
	~Tree();
	void PrintTree();
	int** GetTab();
	int GetHeight();
	char GetSymbol();
	string GetColor();
	int GetX();
	int GetY();
};
