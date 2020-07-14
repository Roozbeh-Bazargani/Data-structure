#include<iostream>
#include"queue.h"

int main()
{
	Queue<int> q{};
	for (size_t i{}; i < 10; i++)
		q.push_back(i*i);
	q.display();
	q.insert(2, 200);
	q.display();
	q.remove(2); // remove index 2
	q.display();
	while (!q.empty())
		std::cout << q.pop_front() << ", ";
	std::cout << "\b\b " << std::endl;
	return 0;
}