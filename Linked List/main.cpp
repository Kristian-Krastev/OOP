#include "List.h"


int main() {

	List a;
	a.push_back(11);
	a.push_back(2);
	a.push_back(7);
	a.push_back(8);
	a.push_back(6);
	a.push_back(2);
	a.push_back(1);
	a.push_back(1);
	a.push_back(4);

	List b = a.divideList();
	

	return 0;
}