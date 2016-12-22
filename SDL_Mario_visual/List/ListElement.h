#pragma once


template <class T>
struct ListElement
{
	ListElement<T>* next = nullptr;
	ListElement<T>* previous = nullptr;
	T content;
};