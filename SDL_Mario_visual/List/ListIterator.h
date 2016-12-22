#pragma once

template <class T>
struct ListElement;

template <class T>
class ListIterator
{	
public:
	template <class T>
	friend class List;
	T& operator*();
	void operator=(ListIterator<T> right);
	bool operator==(ListIterator<T> right);
	bool operator!=(ListIterator<T> right);
	void operator++();
	void operator--();
	T* operator->();

	void startPointingTo(ListElement<T>* element);

private:

	ListElement<T>* pointingTo = nullptr;
};
