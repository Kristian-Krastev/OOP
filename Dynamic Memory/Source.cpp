#include <iostream>
using namespace std;

char* cut_str(const char* str, char ch) {

	size_t count = 0;
	size_t len = strlen(str);

	for (int i = 0; i < len; ++i) {
		if (str[i] == ch)
			count++;
	}

	char* new_str = new char[len - count + 1];
	int cnt = 0;

	while (*str != '\0') {
		if (*str == ch) {
			++str;
			continue;
		}

		new_str[cnt++] = *str;

		++str;
	}

	new_str[cnt] = '\0';
	
	return new_str;
}


int main() {

	char* str = cut_str("Kristian Krastev", 'K');

	cout << str;

	delete[] str;

	return 0;
}