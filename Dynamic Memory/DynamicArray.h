#pragma once

#include <iostream>

class DynamicArray 
{
private:
	int* pData;
	size_t current_size;
	size_t capacity;

public:
	DynamicArray();
	DynamicArray(const DynamicArray& other);
	DynamicArray& operator=(const DynamicArray& other);
	~DynamicArray();

private:
	void copyFrom(const DynamicArray& other);
	void clean();
	void resize(size_t newSize);

public:
	void push_back(int elem);
	void remove_at(size_t pos);
	int get_at(size_t pos)const;
	void set_at(size_t pos, int elem);
	void print_info()const;

	//read-write for non-constant object
	int& operator[](size_t pos);

	//read-write for constant object
	//for build-in types return a copy is
	//the proper approach, for returning 
	//a user defined object -> const T&
	const int operator[](size_t pos) const;

};

