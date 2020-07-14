#pragma once

template <class T>
class Stack
{
	class Item; // for using pointer of them

	class Item {
	public:
		T pT;
		Item* pNext;
		Item(T pt, Item* pN) : pT{ pt }, pNext{ pN } {};
	};

	Item* pTop{}; // last element in stack
	int cnt{}; // Number of elements

public:
	
	Stack() = default; //default constructor
	void push(T pT); //adding elements
	T pop(); // bring elements out
	bool isEmpty() const; // is Empty?
	int getCount() const; // How many elements
	~Stack(); // destructor
};

#include"stack.hpp"