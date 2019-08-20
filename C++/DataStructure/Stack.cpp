#include "Stack.hpp"

// Array Stack
template <class T>
class ArrayStack 
{
private:
	vector<T> items;

public:
	void push(T const&);
	void pop();
	T top() const;
	bool isEmpty() const {
		return items.empty();
	}
};

template <class T>
void ArrayStack<T>::push(T const& elem)
{
	items.push_back(elem);
}

template <class T>
void ArrayStack<T>::pop()
{
	if (items.empty()) {
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	items.pop_back();
}

template <class T>
T ArrayStack<T>::top() const
{
	if (items.empty()) {
		throw out_of_range("Stack<>::top(): empty stack");
	}
	return items.back();
}


// Linked Stack
template <class T>
class LinkedStack
{
private:
	T *top;
public:
	void push(T const&);
	void pop();
	T top() const;
	bool isEmpty() const {
		return items.empty();
	}
};

template <class T>
void LinkedStack<T>::push(T const& elem)
{
	items.push_back(elem);
}

template <class T>
void LinkedStack<T>::pop()
{
	if (items.empty()) {
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	items.pop_back();
}

template <class T>
T LinkedStack<T>::top() const
{
	if (items.empty()) {
		throw out_of_range("Stack<>::top(): empty stack");
	}
	return items.back();
}
