#include <iostream>
#include <string>
using namespace std;

#include "tree.hpp"

Tree::Tree(string c, int h, char s,int x, int y)
{
	color = c;
	height = h;
	symbol = s;
	xx = x;
	yy = y;
	int i, j;
	tab = new int* [height];
	for (j = 0; j < height; j++) {
		tab[j] = new int[2 * height - 1];
		for (i = 0; i < 2 * height - 1; i++)
			tab[j][i] = 0;
	}
	for (int j = 0; j < height; j++)
	{
		for (int i = height - j - 1; i < height + j; i++)
			tab[j][i] = 1;
	}
}

void Tree::PrintTree() {
	int i, j;
	for (j = 0; j < height; j++)
	{
		for (i = 0; i < 2 * height - 1; i++) {
			if (tab[j][i] == 1)
				cout << color << symbol << "\033[0m";
			else
				cout << " ";
		}
		cout << endl;
	}
}

int Tree::GetX(){
	return xx;
}

int Tree::GetY(){
	return yy;
}

string Tree ::GetColor() {
	return color;
}

int** Tree::GetTab()
{
	return tab;
}

int Tree::GetHeight()
{
	return height;
}

char Tree::GetSymbol()
{
	return symbol;
}

Tree::~Tree() {
	int j;
	cout << "Kasuje drzewo\n" << endl;
	for (j = 0; j < height; j++)
		delete tab[j];
	delete tab;
}
