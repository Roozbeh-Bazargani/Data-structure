#pragma once
#include<vector>
#include<string>
#include<iostream>

class Item; // for using pointer of it in linklist

class Item {
public:
	std::string key;
	Item* childl, *childr, *parent;
	Item(std::string pt, Item* pl = nullptr
		, Item* pr = nullptr, Item* pp = nullptr) :
		key{ pt }, childl{ pl }, childr{ pr }, parent{ pp } {};
	// Item(Item x) : 
};

class binary_tree
{

public:
	Item* root;

	binary_tree(std::vector<std::string> v);
};

void inorder_tree_walk(Item* x);
Item* tree_search(Item* x, std::string k);
Item* iterative_tree_search(Item* x, std::string k);
Item* tree_minimum(Item* x);
Item* tree_maximum(Item* x);
Item* tree_successor(Item* x);
void tree_insert(binary_tree& T, Item* z);
void transplant(binary_tree& T, Item* u, Item* v);
void tree_delete(binary_tree& T, Item* z);

