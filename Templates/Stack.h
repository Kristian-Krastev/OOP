#pragma once
#include <iostream>

#define MAX_SIZE 100

template <typename T>
class Stack {

private:
	T data[MAX_SIZE];
	int top;

public:
	Stack();
	~Stack() {};

	bool is_empty()const;
	void push(const T& elem);
	void pop();
	T& peek();

};

template<typename T>
inline Stack<T>::Stack(): top(0)
{
	for (int i = 0; i < MAX_SIZE; ++i) {
		data[i] = 0;
	}
}

template<typename T>
inline bool Stack<T>::is_empty() const
{
	return (top == 0);
}

template<typename T>
inline void Stack<T>::push(const T & elem)
{
	if (top == MAX_SIZE)
		std::cout << "not enough space in the stack!";

	else
		data[top++] = elem;
}

template<typename T>
inline void Stack<T>::pop()
{
	if (!is_empty()) {
		--top;
	}
}

template<typename T>
inline T & Stack<T>::peek()
{
	if (!is_empty()) {
		return data[top - 1];
	}
}
