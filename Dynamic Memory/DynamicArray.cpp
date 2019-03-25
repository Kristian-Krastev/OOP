#include "DynamicArray.h"



DynamicArray::DynamicArray(): pData(nullptr), current_size(0), capacity(0)
{
}

DynamicArray::DynamicArray(const DynamicArray & other)
{
	copyFrom(other);
}

DynamicArray & DynamicArray::operator=(const DynamicArray & other)
{
	if (this != &other) {

		clean();
		copyFrom(other);
	}
	return *this;
}


DynamicArray::~DynamicArray()
{
	clean();

}

void DynamicArray::copyFrom(const DynamicArray & other)
{
	this->pData = new int[other.capacity];
	memcpy(pData, other.pData, sizeof(int) * other.current_size);

	this->capacity = other.capacity;
	this->current_size = other.current_size;
}

void DynamicArray::clean()
{
	delete[] pData;
	pData = nullptr;
	current_size = 0;
	capacity = 0;

}

void DynamicArray::resize(size_t newSize)
{
	int* temp = pData;
	pData = new int[newSize];
	memcpy(pData, temp, sizeof(int) * current_size);

	capacity = newSize;

	delete[] temp;
}

void DynamicArray::push_back(int elem)
{
	if (current_size >= capacity) {
		size_t newSize = (capacity == 0) ? 2 : capacity * 2;
		resize(newSize);
	}

	pData[current_size++] = elem;
}

void DynamicArray::remove_at(size_t pos)
{
	if (pos >= current_size)
		return;

	std::swap(pData[pos], pData[current_size - 1]);
	current_size--;

	if (current_size * 2 <= capacity)
		resize(capacity / 2);
}

int DynamicArray::get_at(size_t pos) const
{
	if (pos >= current_size)
		return -1;

	return pData[pos];
}

void DynamicArray::set_at(size_t pos, int elem)
{
	if (pos >= current_size)
		return;

	pData[pos] = elem;
}

void DynamicArray::print_info() const
{
	std::cout << "obj at: Ox" << this
		<< " buffer starts at: Ox" << pData
		<< " length:" << current_size
		<< " capacity:" << capacity << std::endl;
}

int & DynamicArray::operator[](size_t pos)
{
	if (pos >= current_size) {
		return pData[0];
	}

	return pData[pos];
}

const int DynamicArray::operator[](size_t pos) const
{
	if (pos >= current_size) {
		return pData[0];
	}

	return pData[pos];
}
