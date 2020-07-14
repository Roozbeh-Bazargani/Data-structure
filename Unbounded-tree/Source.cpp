#include"unbounded_tree.h"

int main()
{
	std::vector<std::string> v{ "1","2","3","/","4","5",
		"/","/","/","6","7","/","8","/","9","10","/","11",
		"/","/","12","/","/","13","14","/","/","/" };
	unbounded_tree T(v);
	return 0;
}