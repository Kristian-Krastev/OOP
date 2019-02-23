#include "Destination.h"

void init_destination(Destination & dest, const char * city, int k)
{
	strcpy(dest.city, city);
	dest.kilometers = k;
}

void print_destination(const Destination & dest)
{
	std::cout << "City name: " << dest.city << std::endl;
	std::cout << "Kilometers to Sofia city: " << dest.kilometers << std::endl;
}
