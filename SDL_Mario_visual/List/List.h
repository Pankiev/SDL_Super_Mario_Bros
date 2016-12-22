#pragma once
#include "ListElement.h"

template <class T>
class ListIterator;

template <class T>
class List
{
public:

	List();
	~List();
	bool empty();
	void push_back(T newItem);
	void push_front(T newItem);
	ListIterator<T> begin();
	ListIterator<T> end();
	ListIterator<T> rbegin();
	ListIterator<T> rend();
	void erase(ListIterator<T>& fromWhere);

	
private:
	ListIterator<T> createIterator(ListElement<T>* elementToPut);
	void deleteAllListPieces();


	ListElement<T>* frontGuard;
	ListElement<T>* backGuard;
};

