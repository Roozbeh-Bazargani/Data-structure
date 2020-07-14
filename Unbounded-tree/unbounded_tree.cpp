#include "unbounded_tree.h"

unbounded_tree::unbounded_tree(std::vector<std::string> v)
{
	for (size_t i{}; i < v.size(); i++)
	{
		if (v[i] == "/")
		{
			if (nochild)
			{
				head = head->parent;
				/*while (!(head->sibling))
				{
					head = head->parent;
				}*/
				nochild = false;
			}
			else
			{
				nochild = true;
			}
		}
		else // v[i] != /
		{
			if (!(root)) // first element
			{
				root = new Item(v[i], nullptr,
					nullptr, nullptr);
				head = root;
			}
			else
			{
				if (nochild || (head->child)) // sibling
				{
					Item* temp{ new Item(v[i],
						nullptr,nullptr,head->parent) };
					head->sibling = temp;
					head = temp;
					nochild = false;
				}
				else // child
				{
					Item* temp{ new Item(v[i],
						nullptr,nullptr,head) };
					head->child = temp;
					head = temp;
				}
			}
		}
		cnt++;
	}
	while (head->parent) // if head is root
	{
		head = head->parent;
	}
	// std::cout << cnt << "\n";
}