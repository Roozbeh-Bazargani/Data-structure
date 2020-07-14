#pragma once
#include<string>
#include<vector>
#include<iostream>

class unbounded_tree
{
	class Item; // for using pointer of it in linklist

	class Item {
	public:
		std::string pT;
		Item* child, *sibling, *parent;
		Item(std::string pt, Item* pl, Item* pr, Item* pp) :
			pT{ pt }, child{ pl }, sibling{ pr }, parent{ pp } {};
	};

	Item* root, *head; //root
	size_t cnt{}; // number of elements
	bool nochild{ false };
public:
	unbounded_tree(std::vector<std::string> v);
};

