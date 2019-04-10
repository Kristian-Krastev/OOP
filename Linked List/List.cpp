#include "List.h"



List::List():head_ptr(nullptr), tail_ptr(nullptr) {
}

List::List(const List & other)
{
	copyFrom(other);
}

List & List::operator=(const List & other)
{
	if (this != &other) {

		clean();
		copyFrom(other);
	}
	return *this;
}


List::~List()
{
	clean();
}

void List::clean()
{
	if (head_ptr = nullptr) {
		return;
	}
	Node* destroyer = head_ptr;
	while (head_ptr != nullptr) {
		head_ptr = head_ptr->next_ptr;
		delete destroyer;
		destroyer = head_ptr;
	}
	tail_ptr = nullptr;


}

void List::copyFrom(const List & other)
{
	this->head_ptr = new Node(other.head_ptr->data);
	Node* copier = this->head_ptr;
	Node* toCopy = other.head_ptr;
	while (toCopy != other.tail_ptr) {
		toCopy = toCopy->next_ptr;
		copier->next_ptr = new Node(toCopy->data);
		copier = copier->next_ptr;

	}
	tail_ptr = copier;
}

void List::push_back(size_t newElem)
{
	if (head_ptr == nullptr) {
		head_ptr = new Node(newElem);
		tail_ptr = head_ptr;
	}
	else {
		tail_ptr->next_ptr = new Node(newElem);
		tail_ptr = tail_ptr->next_ptr;
	}
}

void List::pop_back()
{
	if (head_ptr == tail_ptr) {
		delete head_ptr;
		head_ptr = nullptr;
		tail_ptr = nullptr;
	}
	else {
		Node* temp = head_ptr;
		while (temp->next_ptr != tail_ptr) {
			temp = temp->next_ptr;
		}
		delete temp->next_ptr;
		temp->next_ptr = nullptr;
		tail_ptr = temp;
	}
}

void List::push_front(size_t newElem)
{

	Node* temp = head_ptr;
	head_ptr = new Node(newElem, temp);
	if (tail_ptr == nullptr) {	//if the list was empty and we add the first element
		tail_ptr = head_ptr;
	}

}

void List::pop_front()
{
	if (head_ptr == tail_ptr) {
		delete head_ptr;
		head_ptr = nullptr;
		tail_ptr = nullptr;
	}
	else {
		Node* del = head_ptr;
		head_ptr = head_ptr->next_ptr;
		delete del;
	}
}

void List::append(List & other)
{
	if (this->head_ptr == nullptr) {	//if our list is empty
		this->head_ptr = other.head_ptr;
		this->tail_ptr = other.tail_ptr;
	}
	else {
		this->tail_ptr->next_ptr = other.head_ptr;
		if (other.tail_ptr != nullptr) {	//if the other list has at least one element
			this->tail_ptr = other.tail_ptr;
			other.head_ptr = nullptr;
			other.tail_ptr = nullptr;
		}
	}
}

List List::divideList() const
{
	//creating two new empty lists, with memory O(1) -> just four pointers
	List odds, evens;
	Node* temp_ptr = head_ptr;
	while (temp_ptr != nullptr) {
		// decide in which part it belongs
		List& in_which = (temp_ptr->data % 2 == 0) ? evens : odds;
		in_which.push_back(temp_ptr->data);

		temp_ptr = temp_ptr->next_ptr;
	}
	// append the result lists into list evens
	evens.append(odds);
	// copy the pointers of the result list into the given one
	return evens;
}
