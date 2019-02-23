#pragma once

#include <iostream>

struct Destination {

	char city[32];
	int kilometers;
};

//one way to initialize structure's data
//we pass Destination param by '&' because we will make copy otherwise
void init_destination(Destination& dest, const char* city, int k); 

//const because we dont change destination's data
void print_destination(const Destination& dest);