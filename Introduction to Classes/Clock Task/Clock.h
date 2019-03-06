#ifndef _CLOCK_H_
#define _CLOCK_H_

#include <iostream>

const int MAX_HOURS = 24;
const int MAX_MINUTES = 60;
const int MAX_SECONDS = 60;

class Clock
{
	
private:
	int hours;
	int minutes;
	int seconds;

public:
	Clock();
	~Clock();

public:
	int get_hours()const;
	int get_minutes()const;
	int get_seconds()const;

	void set_H(int);
	void set_M(int);
	void set_S(int);

	void print()const;
	void nextTick();

	void syncTime();
};

#endif