#ifndef _WORKER_H_
#define _WORKER_H_

#include <string.h>

class Worker
{
private:
	char name[32];
	size_t year;
	double salary;

public:
	Worker();
	~Worker();

public:
	const char* get_name() const;
	size_t get_year() const;
	double get_salary() const;

	void set_name(const char*);
	void set_year(size_t);
	void set_salary(double);

	void set_data(const char*, size_t, double);
};

#endif