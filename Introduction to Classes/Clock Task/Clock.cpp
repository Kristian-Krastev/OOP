#include "Clock.h"
#include <time.h>


Clock::Clock()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}


Clock::~Clock()
{
}

int Clock::get_hours() const
{
	return hours;
}

int Clock::get_minutes() const
{
	return minutes;
}

int Clock::get_seconds() const
{
	return seconds;
}

void Clock::set_H(int h)
{
	if (h <= 0 || h >= MAX_HOURS) {
		hours = 0;
	}
	else {
		hours = h;
	}
}

void Clock::set_M(int m)
{
	if (m <= 0 || m >= MAX_MINUTES) {
		minutes = 0;
	}
	else {
		minutes = m;
	}
}

void Clock::set_S(int s)
{
	if (s <= 0 || s >= MAX_SECONDS) {
		seconds = 0;
	}
	else {
		seconds = s;
	}
}

void Clock::print() const
{
	if (hours < 10) {
		std::cout << '0';
	}
	std::cout << hours << ':';

	if (minutes < 10) {
		std::cout << '0';
	}
	std::cout << minutes << ':';

	if (seconds < 10) {
		std::cout << '0';
	}
	std::cout << seconds << '\n';
}

void Clock::nextTick()
{
	++seconds;
	if (seconds >= MAX_SECONDS) {
		minutes++;
		seconds = 0;
	}

	if (minutes >= MAX_MINUTES) {
		hours++;
		minutes = 0;
	}

	if (hours >= MAX_HOURS) {
		hours = 0;
	}


}

void Clock::syncTime()
{
	time_t curTime;
	time(&curTime);		//reading the current time as a large number
					 // see more : UNIX UTC

	tm* timeInfo; //a pointer to structure in which we have separated fields
				//for minutes, seconds..etc

	timeInfo = localtime(&curTime); //formating the current time as local

	set_H(timeInfo->tm_hour);
	set_M(timeInfo->tm_min);
	set_S(timeInfo->tm_sec);

}
