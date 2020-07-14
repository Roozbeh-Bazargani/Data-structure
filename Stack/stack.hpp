
template<class T>
bool Stack<T>::isEmpty() const // is Empty?
{
	return !pTop;
}

template<class T>
inline int Stack<T>::getCount() const // How many elements
{
	return cnt;
}

template<class T>
Stack<T>::~Stack()
{ // destructor
	Item* temp{};
	while (cnt--)
	{
		temp = pTop;
		pTop = pTop->pNext;
		delete temp;
	}
}


template<class T>
void Stack<T>::push(T pT)
{ //adding elements
	pTop = new Item(pT, pTop);
	cnt++;
}

template<class T>
T Stack<T>::pop()
{ // bring elements out
	if (!cnt) // no elements
	{
		std::cout << "No element to pop!\n";
		return nullptr;
	}
	cnt--;
	T Ttemp = pTop->pT;
	Item* pTemp = pTop;
	pTop = pTop->pNext;
	delete pTemp;
	return Ttemp;
}