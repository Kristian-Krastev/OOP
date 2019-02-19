#include <iostream>

struct Student {
	char name[32];
	int fn;

	/*Student(char n[], int _fn) {
		strcpy(name, n);
		fn = _fn;
	}*/
};



void change_fn(Student& pesho, int number) {

	pesho.fn = number;

}
void change_name(Student& pesho, const char* name) {

	strcpy(pesho.name, name);

}

void read_name_from_stdIn(Student& pesho) {
	char buff[128];

	char c;

	std::cin.get(c);
	if (c != '\n') {
		std::cin.putback(c);
	}

	std::cin.getline(buff, 128);

	strcpy(pesho.name, buff);
}
void read_fn_from_stdIn(Student& pesho) {
	size_t fn;
	std::cin >> fn;

	pesho.fn = fn;
}

void fill_arr(Student* arr, size_t arr_size) {
	for (int i = 0; i < arr_size; i++) {

		read_name_from_stdIn(arr[i]);
		read_fn_from_stdIn(arr[i]);
	}

}

void print_arr(Student* arr, size_t arr_size) {
	for (int i = 0; i < arr_size; i++) {

		std::cout << arr[i].name << ' ' << arr[i].fn;
		std::cout << std::endl;
	}

}

//void readStudentFromStdin(Student& s) {
//
//	char buff[1024];
//
//	char c;
//
//	std::cin.get(c);
//
//	if (c != '\n')
//
//		std::cin.putback(c);
//
//	std::cout << "enter name :\n";
//
//	std::cin.getline(buff, 1024);
//
//	size_t inputLen = strlen(buff);
//
//	strncpy(s.name, buff, inputLen);
//
//	std::cout << "enter fn :\n";
//
//	std::cin >> s.fn;
//
//	memset(buff, 0, 1024);
//
//}

int main() {


	Student pesho;
	strcpy(pesho.name, "Pesho");
	pesho.fn = 45230;
	std::cout << pesho.name << ' ' << pesho.fn;

	change_fn(pesho, 12345);

	std::cout << std::endl;

	std::cout << pesho.name << ' ' << pesho.fn;
	std::cout << std::endl;


	const size_t size = 5;


	Student student_arr[size];
	fill_arr(student_arr, size);
	print_arr(student_arr, size);

	//readStudentFromStdin(pesho);

	return 0;
}