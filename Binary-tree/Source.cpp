#include<iostream>
#include"binary_tree.h"

int main()
{
	std::vector<std::string> v{ "10","05","15","03","07","12","17"};
	binary_tree T(v);
	// std::cout << tree_search(T.root, "5")->parent->key << std::endl;
	// std::cout << T.root->key << std::endl;
	std::cout << "inorder tree walk:\n";
	inorder_tree_walk(T.root);
	Item* itm1{ tree_search(T.root,"10") };
	// std::cout << itm1->key << std::endl;
	tree_delete(T, itm1);
	std::cout << "inorder tree walk:\n";
	inorder_tree_walk(T.root);
	// std::cout << itm1->key << std::endl;
	Item* itm2{ tree_search(T.root,"07") };
	Item* itm3{ tree_successor(itm2) };
	std::cout << "successor " << itm3->key << std::endl;
	// std::cout << itm2->key << std::endl;
	// std::cout << tree_maximum(itm2)->key << std::endl;
	
	
	return 0;
}