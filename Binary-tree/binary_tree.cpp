#include "binary_tree.h"


binary_tree::binary_tree(std::vector<std::string> v)
{
	root = new Item(v[0]);
	for (size_t i{ 1 }; i < v.size(); i++)
	{
		Item* x = new Item(v[i]);
		tree_insert(*this, x);
	}
}

void inorder_tree_walk(Item * x)
{
	if (x != nullptr)
	{
		inorder_tree_walk(x->childl);
		std::cout << x->key << std::endl;
		inorder_tree_walk(x->childr);
	}
}

void tree_insert(binary_tree& T, Item * z)
{
	Item* y{ nullptr }; // z->parent
	Item* x{ T.root };
	while (x != nullptr)
	{
		y = x;
		if (z->key < x->key)
			x = x->childl;
		else
			x = x->childr;
	}
	z->parent = y;
	if (y == nullptr)
		T.root = z;
	else if (z->key < y->key)
		y->childl = z;
	else
		y->childr = z;
}

void transplant(binary_tree &T, Item * u, Item * v)
{
	if (u->parent == nullptr)
		T.root = v;
	else if (u == u->parent->childl)
		u->parent->childl = v;
	else
		u->parent->childr = v;
	if (v != nullptr)
		v->parent = u->parent;
}

void tree_delete(binary_tree& T, Item * z)
{
	if (z->childl == nullptr)
		transplant(T, z, z->childr);
	else if (z->childr == nullptr)
		transplant(T, z, z->childl);
	else
	{
		Item* y = tree_minimum(z->childr);
		if (y->parent != z)
		{
			transplant(T, y, y->childr);
			y->childr = z->childr;
			y->childr->parent = y;
		}
		transplant(T, z, y);
		y->childl = z->childl;
		y->childl->parent = y;
	}
}

Item* tree_successor(Item * x)
{
	if (x->childr != nullptr)
		return tree_minimum(x->childr);
	Item* y{ x->parent };
	while (y != nullptr && x == y->childr)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

Item* tree_maximum(Item * x)
{
	while (x->childr != nullptr)
		x = x->childr;
	return x;
}

Item* tree_minimum(Item * x)
{
	while (x->childl != nullptr)
		x = x->childl;
	return x;
}

Item* iterative_tree_search(Item * x, std::string k)
{
	while (x != nullptr && k != x->key)
	{
		if (k < x->key)
			x = x->childl;
		else
			x = x->childr;
		return x;
	}
}

Item* tree_search(Item * x, std::string k)
{
	
	if (x == nullptr || k == x->key)
	{
		return x;
	}
	if (k < x->key) {
		return tree_search(x->childl, k);
	}
	else
	{
		return tree_search(x->childr, k);
	}
}
