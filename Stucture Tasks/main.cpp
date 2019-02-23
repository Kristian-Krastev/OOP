#include "Student.h"
#include "Destination.h"

const size_t DEST_SIZE = 5;

int main() {

	//Destination Task

	Destination first_destination;				
	strcpy(first_destination.city, "Plovdiv");	// most basic way to
	first_destination.kilometers = 165;			// initialize structure's data

	std::cout << "City name: " << first_destination.city << std::endl;
	std::cout << "Kilometers to Sofia city: " << first_destination.kilometers << std::endl;


	Destination second_destination;
	init_destination(second_destination, "Varna", 469);	// initializing struct's data using functions
	print_destination(second_destination);

	std::cout << '\n';

	// array of type - Destination with number of elements = "DEST_SIZE"
	Destination dest_array[DEST_SIZE];

	init_destination(dest_array[0], "Plovdiv", 165);
	init_destination(dest_array[1], "Varna", 469);
	init_destination(dest_array[2], "Burgas", 393);
	init_destination(dest_array[3], "Vidin", 199);
	init_destination(dest_array[4], "Dobrich", 512);

	for (int i = 0; i < DEST_SIZE; ++i) {
		print_destination(dest_array[i]);
		std::cout << std::endl;
	}


	// Student Task

	size_t n;
	std::cout << "How many Students would you like: ";
	std::cin >> n;

	//pointer of type - Student pointing to an array with 'n' students
	Student* st_arr = new Student[n];		

	for (int i = 0; i < n; i++) {
		read_student_from_STDin(st_arr[i]);		//reading all the students from the standart input
	}

	sort_student_array(st_arr, n);
	std::cout << '\n';

	for (int i = 0; i < n; i++) {
		write_student_to_STDout(st_arr[i]);		// writing all the students to the standart output
	}


	//dont forget to delete the taken memory that we allocated
	delete[] st_arr;


	return 0;
}