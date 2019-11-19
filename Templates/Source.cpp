#include "Stack.h"

int main() {

	Stack<int> s;
	
	s.push(5);
	s.push(10);
	s.push(123);
	s.push(54);
	s.push(23);

	std::cout << s.peek() << '\n';
	s.pop();

	std::cout << s.peek() << '\n';
	s.pop();

	std::cout << s.peek() << '\n';
	s.pop();

	std::cout << s.peek() << '\n';
	s.pop();

	std::cout << s.peek() << '\n';
	std::cout << s.peek() << '\n';
	std::cout << s.peek() << '\n';
	std::cout << s.peek() << '\n';
	std::cout << s.peek() << '\n';
	std::cout << s.peek() << '\n';
	
	s.pop();
	return 0;
}