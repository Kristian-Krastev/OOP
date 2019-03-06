#include "Worker.h"



Worker::Worker()
{
	strcpy(name, "Unknown");
	year = 0;
	salary = 0;
}


Worker::~Worker()
{
}

const char * Worker::get_name() const
{
	return name;
}

size_t Worker::get_year() const
{
	return year;
}

double Worker::get_salary() const
{
	return salary;
}

void Worker::set_name(const char* new_name)
{
	strcpy(name, new_name);
}

void Worker::set_year(size_t year)
{
	if (year) {
		this->year = year;
	}
}

void Worker::set_salary(double sal)
{
	this->salary = sal;
}

void Worker::set_data(const char * name, size_t year, double salary)
{
	set_name(name);
	set_year(year);
	set_salary(salary);
}
