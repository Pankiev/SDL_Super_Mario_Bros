
#pragma once
#include "List.h"

template <class T>
List<T>::List()
{
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
	return frontGuard->next = backGuard;
}


template <class T>
void List<T>::push_front(T newItem)
{
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
void List<T>::erase(ListIterator<T>& fromWhere)
{
	fromWhere.pointingTo->previous->next = fromWhere.pointingTo->next;
	fromWhere.pointingTo->next->previous = fromWhere.pointingTo->previous;
}
