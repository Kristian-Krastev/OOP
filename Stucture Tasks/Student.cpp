#include "Student.h"


void read_student_from_STDin(Student& st) {
	char buff[128];

	char c;

	std::cout << "Enter name: ";
	std::cin.get(c);		//<--- from here

	if (c != '\n') {			// we are doing this because after we read a number from std in 
		std::cin.putback(c);	// the '\n' symbol is not read
								// and if we try to read the next name we would get '\n' instead
	}						//<--- to here 

	std::cin.getline(buff, 128);	// reading the name of our Student with getline
	strcpy(st.name, buff);			//initializing student's name

	std::cout << "Enter fn: ";
	size_t fn;
	std::cin >> fn;

	st.fn = fn;
}

void write_student_to_STDout(const Student& st) {

	std::cout << "Name: " << st.name << std::endl;
	std::cout << "FN: " << st.fn << std::endl;
}

void sort_student_array(Student* st_arr, size_t array_size) // simple insertion sort
{
	Student current_elem;

	for (int i = 1; i < array_size; ++i) {
		current_elem = st_arr[i];

		int j = i - 1;
		while (j >= 0 && st_arr[j].fn > current_elem.fn) {

			st_arr[j + 1] = st_arr[j];

			--j;
		}

		st_arr[j + 1] = current_elem;

	}

}
