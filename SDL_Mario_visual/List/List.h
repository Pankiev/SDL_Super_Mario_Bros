#pragma once
#include "ListElement.h"
#include "../Model/Object.h"
#include "List.h"

template <class T>
class ListIterator;

template <class T>
class List
{
public:

	List();
	~List();
	bool empty();
	int size();
	void push_back(T newItem);
	void push_front(T newItem);
	ListIterator<T> begin();
	ListIterator<T> end();
	ListIterator<T> rbegin();
	ListIterator<T> rend();
	ListIterator<T> erase(ListIterator<T>& fromWhere);
	void insert(ListIterator<T>& position, T toInsert);

private:
	ListIterator<T> createIterator(ListElement<T>* elementToPut);
	void deleteAllListPieces();


	ListElement<T>* frontGuard;
	ListElement<T>* backGuard;
	int size_;
};

