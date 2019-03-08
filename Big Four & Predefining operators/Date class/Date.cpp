#include "Date.h"
#include <time.h>

const int daysInMonth[] = { 0,31,28,31,30,31,30,31,31,31,31,30,31 };


Date::Date(size_t d, size_t m, size_t y): day(d), month(m), year(y)
{
}


Date::~Date()
{
}

int Date::operator-(const Date & other) const
{
	int totalDays = 0;
	totalDays += day;

	for (int i = month - 1; i > 0; i--)
	{
		totalDays += daysInMonth[i];
	}
	for (int i = year - 1; i > 1900; i--)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				totalDays += 366;
			else
				totalDays += 365;
		}
		else
		{
			if (year % 4 == 0)
				totalDays += 366;
			else
				totalDays += 365;
		}
	}

	return totalDays;
}

bool Date::operator<(const Date & other) const
{
	//return (this->year < other.year || this->month < other.month || this->day < other.day);
	// wont work, for example: 2000:02:03 will be > than 2000:01:05

	if (this->year > other.year)
		return false;
	
	else if (this->year < other.year)
		return true;

	else {
		if (this->month > other.month)
			return false;
		else if (this->month < other.month)
			return true;
		else {
			if (this->day > other.day)
				return false;

			else if (this->day <= other.day)
				return true;
		}
	}
}

bool Date::operator<=(const Date & other) const
{
	return (*this < other || *this == other);
}

bool Date::operator>(const Date & other) const
{
	return !(*this <= other);
}

bool Date::operator>=(const Date & other) const
{
	return (*this > other || *this == other);
}

bool Date::operator==(const Date & other) const
{
	return (this->year == other.year && this->month == other.month && this->day == other.day);
}

Date::operator bool() const
{
	time_t curTime;

	time(&curTime);

	tm* timeInfo;
	timeInfo = localtime(&curTime); //formating the current time as local

	Date temp_date(timeInfo->tm_mday, timeInfo->tm_mon + 1, timeInfo->tm_year + 1900);

	return (*this < temp_date);
}

ostream & operator<<(std::ostream & os, const Date & obj)
{
	os << obj.day << '/' << obj.month << '/' << obj.year << '\n';
	return os;
}
