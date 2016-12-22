
#pragma once
#include "List.h"

template <class T>
List<T>::List()
{
	size_ = 0;
	frontGuard = new ListElement<T>;
	backGuard = new ListElement<T>;
	frontGuard->next = backGuard;
	backGuard->previous = frontGuard;
}

template <class T>
List<T>::~List()
{
	deleteAllListPieces();
}

template <class T>
void List<T>::deleteAllListPieces()
{
	ListElement<T>* current = frontGuard;
	while(current != backGuard)
	{
		ListElement<T>* next = current->next;
		delete current;
		current = next;
	}
	delete backGuard;
}

template <class T>
bool List<T>::empty()
{
	return size_ == 0;
}

template <class T>
int List<T>::size()
{
	return size_;
}

template <class T>
void List<T>::push_front(T newItem)
{
	size_++;
	ListElement<T>* newElement = new ListElement<T>;
	newElement->content = newItem;
	newElement->previous = frontGuard;
	newElement->next = frontGuard->next;
	frontGuard->next->previous = newElement;
	frontGuard->next = newElement;
}


template <class T>
void List<T>::push_back(T newItem)
{
	size_++;
	ListElement<T>* newElement = new ListElement<T>;
	newElement->content = newItem;
	newElement->next = backGuard;
	newElement->previous = backGuard->previous;
	backGuard->previous->next = newElement;
	backGuard->previous = newElement;
}

template <class T>
ListIterator<T> List<T>::createIterator(ListElement<T>* elementToPut)
{
	ListIterator<T> iteratorToFirstElement;
	iteratorToFirstElement.startPointingTo(elementToPut);
	return iteratorToFirstElement;
}

template <class T>
ListIterator<T> List<T>::begin()
{
	return createIterator(frontGuard->next);
}

template <class T>
ListIterator<T> List<T>::end()
{
	return createIterator(backGuard);
}

template <class T>
ListIterator<T> List<T>::rbegin()
{
	return createIterator(backGuard->previous);
}

template <class T>
ListIterator<T> List<T>::rend()
{
	return createIterator(frontGuard);
}

template <class T>
ListIterator<T> List<T>::erase(ListIterator<T>& fromWhere)
{
	size_--;
	ListIterator<T> iteratorCopy = fromWhere;
	++fromWhere;
	iteratorCopy.pointingTo->previous->next = iteratorCopy.pointingTo->next;
	iteratorCopy.pointingTo->next->previous = iteratorCopy.pointingTo->previous;
	return fromWhere;
}

template <class T>
void List<T>::insert(ListIterator<T>& position, T toInsert)
{
	size_++;
	ListElement<T>* newElement = new ListElement<T>;
	newElement->content = toInsert;
	newElement->next = position.pointingTo;
	newElement->previous = position.pointingTo->previous;
	position.pointingTo->previous->next = newElement;
	position.pointingTo->previous = newElement;
}
