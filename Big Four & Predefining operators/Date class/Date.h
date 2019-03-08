#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

using std::cout;
using std::ostream;

class Date
{
private:
	size_t day;
	size_t month;
	size_t year;

public:
	Date(size_t d = 1, size_t m = 1, size_t y = 1900);
	~Date();

public:
	int operator-(const Date& other)const;

	bool operator<(const Date& other)const;
	bool operator<=(const Date& other)const;
	bool operator>(const Date& other)const;
	bool operator>=(const Date& other)const;
	bool operator==(const Date& other)const;

	operator bool()const;

	//operator<< is friend function because it is not right to be one of the class' methods
	//because it has nothing to do with the class, it only prints its data
	friend ostream& operator<<(std::ostream& os, const Date& obj);
};

#endif