#pragma once
#include "ListIterator.h"
#include "ListElement.h"

template <class T>
T& ListIterator<T>::operator*()
{
	return pointingTo->content;
}

template <class T>
void ListIterator<T>::operator=(ListIterator<T> right)
{
	pointingTo = right.pointingTo;
}

template <class T>
bool ListIterator<T>::operator==(ListIterator<T> right)
{
	return pointingTo == right.pointingTo;
}

template <class T>
bool ListIterator<T>::operator!=(ListIterator<T> right)
{
	return !(*this == right);
}

template <class T>
void ListIterator<T>::operator++()
{
	pointingTo = pointingTo->next;
}

template <class T>
void ListIterator<T>::operator--()
{
	pointingTo = pointingTo->previous;
}

template <class T>
T* ListIterator<T>::operator->()
{
	return &(pointingTo->content);
}

template <class T>
void ListIterator<T>::startPointingTo(ListElement<T>* element)
{
	pointingTo = element;
}
