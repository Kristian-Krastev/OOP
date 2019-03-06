#include "Worker.h"
#include <iostream>



int main() {
	Worker w_arr[10];
	w_arr[0].set_data("Pesho", 1992, 800.30);
	w_arr[1].set_data("Georgi", 1995, 900.20);
	w_arr[2].set_data("Ivan", 1997, 650.20);
	w_arr[3].set_data("Kaloian", 1992, 700.20);
	w_arr[4].set_data("Stoyan", 1993, 950.20);
	w_arr[5].set_data("Teodor", 1999, 1000.40);
	w_arr[6].set_data("Todor", 1994, 820.50);
	w_arr[7].set_data("Simeon", 1992, 930.20);
	w_arr[8].set_data("Peter", 1995, 1110.50);
	w_arr[9].set_data("Kiro", 1993, 1032);

	size_t input_year;
	std::cout << "Enter year: ";
	std::cin >> input_year;

	for (int i = 0; i < 10; ++i) {
		if (w_arr[i].get_year() == input_year) {
			std::cout << w_arr[i].get_name() << '\n';
		}

	}

	double sum_salary = 0;
	for (int i = 0; i < 10; ++i) {
		sum_salary += w_arr[i].get_salary();

	}
	std::cout << "The average salary is: " << sum_salary / 10;

	return 0;
}