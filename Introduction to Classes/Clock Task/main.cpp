#include "Clock.h"



int main() {

	Clock c;
	c.set_H(23);
	c.set_M(59);
	c.set_S(59);

	c.print();

	std::cout << c.get_hours() << '\n';
	std::cout << c.get_minutes() << '\n';
	std::cout << c.get_seconds() << '\n';

	c.nextTick();

	c.print();

	c.syncTime();

	c.print();

	return 0;
}