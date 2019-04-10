#pragma once

class List
{
private:
	struct Node {
		size_t data;
		Node* next_ptr;
		Node(size_t dat, Node* next = nullptr) :data(dat), next_ptr(next) {};
	};
	
	Node* head_ptr;
	Node* tail_ptr;

public:
	List();
	List(const List& other);
	List& operator=(const List& other);
	~List();

private:
	void clean();
	void copyFrom(const List& other);

public:
	void push_back(size_t newElem);
	void pop_back();
	void push_front(size_t newElem);
	void pop_front();

public:
	void append(List& other);
	List divideList()const;

};

