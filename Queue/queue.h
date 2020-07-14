#pragma once

#include<iostream>

template<class T>
class Queue
{
	class Item; // for using pointer of it in linklist

	class Item {
	public:
		T pT;
		Item* pNext;
		Item(T pt, Item* pN) : pT{ pt }, pNext{ pN } {};
	};

	Item* pTop{}; //back
	Item* pFront{}; //front
	size_t cnt{}; // number of elements

public:
	~Queue(); //destructor
	void push_back(const T&); // add elements
	void display(); // show elements
	void insert(const size_t&,const T&); // add elements between elements
	void remove(const size_t&); // delete elements between elements
	bool empty() { return !cnt; } // is empty?
	T pop_front(); // return back the last element
};

#include "queue.hpp"


/*template<class T>
Queue<T>::~Queue()
{
	while (cnt--) // not 0
	{
		Item* p{ pFront };
		pFront = pFront->pNext;
		delete p;
	}
}

template<class T>
inline void Queue<T>::push_back(const T& pT)
{
	if (!cnt) // first time
	{
		pFront = new Item(pT, nullptr);
		pTop = pFront;
		cnt++;
		return;
	}
	Item* temp = new Item(pT, nullptr);
	pTop->pNext = temp;
	pTop = temp;
	temp = nullptr;
	delete temp;
	cnt++;
}

template<class T>
inline void Queue<T>::display() 
{ // show elements
	if (cnt) // not zero
	{
		Item* p{ pFront };
		for (size_t i{}; i < cnt - 1; i++)
		{
			std::cout << p->pT << ", ";
			p = p->pNext;
		}
		std::cout << p->pT << " -> " << cnt << " item\n";
	}
	else
		std::cout << "-> 0 item\n";
}

template<class T>
inline void Queue<T>::insert(const size_t& n, const T& pT)
{ // add elements between elements
	if (n > cnt) // in queue
	{
		std::cout << "Error : Out of Queue\n";
	}
	else if (n == cnt)
		this->push_back(pT);
	else if (n < 0)
		std::cout << "Iterator should be size_t\n";
	else
	{
		Item* p{ pFront };
		for (size_t i{}; i < n; i++)
		{
			p = p->pNext;
		}
		Item* temp{ new Item(p->pT, p->pNext) };
		p->pT = pT;
		p->pNext = temp;
		cnt++;
	}
}

template<class T>
inline void Queue<T>::remove(const size_t & n)
{ // delete elements between elements
	if (n > cnt - 1) // in queue
		std::cout << "Error : Out of Queue\n";
	else if (cnt < 1) // no element
		std::cout << "Error : No element to remove\n";
	else if (n < 0)
		std::cout << "Iterator should be size_t\n";
	else if (cnt - 1 == n) //special case
	{
		Item* p{ pFront };
		for (size_t i{}; i < n - 1; i++)
		{
			p = p->pNext;
		}
		Item* temp{ p->pNext };
		pTop = p;
		delete temp;
		cnt--;
	}
	else
	{
		Item* p{ pFront };
		for (size_t i{}; i < n; i++)
		{
			p = p->pNext;
		}
		Item* temp{ p->pNext };
		p->pT = temp->pT;
		p->pNext = temp->pNext;
		delete temp;
		cnt--;
	}
}

template<class T>
inline T Queue<T>::pop_front()
{
	if (cnt) // not 0
	{
		Item* p{ pFront };
		T temp{ pFront->pT };
		pFront = pFront->pNext;
		delete p;
		cnt--;
		return temp;
	}
	else // no element
		std::cout << "Error : No element to pop\n";
}
*/