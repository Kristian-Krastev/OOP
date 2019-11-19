// Author : Vasilena Peycheva
// Author : Ivan Filipov

#include<iostream> //cin, cout



#include<string.h> // strlen , strcat ///



//#include<ctype.h> isalpha, isdigit, islower etc could be found,

//it is a part of string.h


//task1 - > a standard function from ctype.h 

bool isAlpha(char c) {



	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');

}

//task2 -> also a standard function

bool isDigit(char c) {



	return c >= '0' && c <= '9';

}


//task3 

void toUpper(char* str) {

	//protects our function
	//from invalid usage

	if (str == nullptr)

		return;

	//the standard way of iterating a string

	size_t i = 0;

	//loop until the terminating symbol

	while (str[i] != '\0') {

		if (islower(str[i]))	// using islower from ctype.h

			str[i] -= 'a' - 'A';   //using the fact that the lower letters are before

								//the upper ones, so changing is just 

								//'moving around into the ASCII table'

		i++;

	}

}

//task4

void changeSpSymbol(char* str, char toChange, char changeWith) {

	if (str == nullptr)

		return;


	size_t i = 0;

	while (str[i] != '\0') {

		if (str[i] == toChange)

			str[i] = changeWith;



		i++;

	}

}

//task5 !!! atoi already included by string.h !!! 

int m_atoi(const char* str) { //we will not change the string's

								//contain so passing it by const 

								//is the right way to go

	//will not compile in debug mode when nullptr or NULL passed,

	//but just to insure everything 

	if (str == nullptr)

		return 0; // maybe



	int result = 0;



	int sign = 1;

	if (*str == '-') { // the first char is -

		sign = -1;

		str++; //moves the pointer one position forward

	}



	size_t i = 0;

	while (str[i] != '\0') {

		result *= 10; // a new space at the end of the number

		result += str[i] - '0'; //putting the new digit at the end



		i++;

	}



	return result * sign;
}


//task6

bool isPalindrome(const char* str) {

	if (str == nullptr)

		return false;


	size_t len = strlen(str);

	size_t i = 0;

	while (i < len / 2) {		//looking at the front and at the end

		if (str[i] != str[len - (i + 1)]) // the last element is on index str[len-1]

			return false;

		else

			i++;

		//if the first half is the reversed second
	}
	return true;
}

//task7

void reverse(char* str) {

	size_t len = strlen(str);

	size_t i = 0;

	while (i < len / 2) { //looking at the front and at the end

		std::swap(str[i], str[len - (i + 1)]);

		i++;

	}
}
