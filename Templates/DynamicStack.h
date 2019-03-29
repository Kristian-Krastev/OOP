#pragma once

template<typename T>
class DynamicStack
{
private:
	T* data;
	size_t cur_size;
	size_t capacity;

private:
	void clean();
	void copy_from(const DynamicStack& other);
	void resize(size_t new_size);

public:
	DynamicStack();
	DynamicStack(size_t size);
	DynamicStack(const DynamicStack& other);
	DynamicStack& operator=(const DynamicStack& other);
	~DynamicStack();

public:
	bool is_empty()const;
	void push(const T& elem);  // adding an element on the top of the stack
	void pop();				// removing the element on the top of the stack
	T& peek();				// gets the top element
};

template<typename T>
inline void DynamicStack<T>::clean()
{
	delete[] data;
	data = nullptr;
	cur_size = 0;
	capacity = 0;
}

template<typename T>
inline void DynamicStack<T>::copy_from(const DynamicStack & other)
{
	this->capacity = other.capacity;
	this->cur_size = other.cur_size;

	this->data = new T[this->capacity];
	for (int i = 0; i < this->cur_size; ++i) {

		this->data[i] = other.data[i];
	}
}

template<typename T>
inline void DynamicStack<T>::resize(size_t new_size)
{
	T* temp = data;
	data = new T[new_size];
	for (int i = 0; i < cur_size; ++i) {
		data[i] = temp[i];
	}

	delete[] temp;
	capacity = new_size;
}

template<typename T>
inline DynamicStack<T>::DynamicStack() :
	data(nullptr),
	cur_size(0),
	capacity(0)
{
}

template<typename T>
inline DynamicStack<T>::DynamicStack(size_t size) :
	capacity(size),
	cur_size(0)
{
	data = new T[capacity];
}

template<typename T>
inline DynamicStack<T>::DynamicStack(const DynamicStack & other)
{
	copy_from(other);
}

template<typename T>
inline DynamicStack<T> & DynamicStack<T>::operator=(const DynamicStack & other)
{
	if (this != &other) {
		
		clean();
		copy_from(other);
	}
	return *this;
}

template<typename T>
inline DynamicStack<T>::~DynamicStack()
{
	clean();
}

template<typename T>
inline bool DynamicStack<T>::is_empty() const
{
	return (cur_size == 0);
}

template<typename T>
inline void DynamicStack<T>::push(const T & elem)
{
	if (cur_size >= capacity) {
		size_t new_cap = (capacity == 0) ? 2 : capacity * 2;
		resize(new_cap);
	}

	data[cur_size++] = elem;
}

template<typename T>
inline void DynamicStack<T>::pop()
{
	if (!is_empty()) {
		if (cur_size * 2 <= capacity) {
			resize(capacity / 2);
		}

		cur_size--;
	}
}

template<typename T>
inline T & DynamicStack<T>::peek()
{
	if (!is_empty()) {
		return data[cur_size - 1];
	}
}
