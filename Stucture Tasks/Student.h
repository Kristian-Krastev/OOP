#pragma once

#include <iostream>

struct Student {

	char name[32];
	size_t fn;		// size_t = unsigned int

};


void read_student_from_STDin(Student& st);

void write_student_to_STDout(const Student& st);

void sort_student_array(Student* st_arr, size_t array_size);

