#include "Rational.h"



Rational::Rational(int n, int d) : numerator(n), denominator(d) {
	if (denominator == 0) //or throw exception...

		denominator = 1;

}


//Euclidean's algorithm ...
int Rational::gcd(int a, int b) {

	a = abs(a);
	b = abs(b);

	long long temp = 0;

	while (b != 0) {

		temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}



void Rational::simplify() {

	long long g = gcd(numerator, denominator);

	numerator /= g;
	denominator /= g;
}



Rational Rational::simplified() const {

	Rational r = *this;

	r.simplify();

	return r;
}

Rational& Rational::operator+=(const Rational& rhs) {

	numerator = numerator * rhs.denominator +

		rhs.numerator * denominator;


	denominator *= rhs.denominator;


	return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {

	numerator = numerator * rhs.denominator -

		rhs.numerator * denominator;



	denominator *= rhs.denominator;


	return *this;
}



Rational& Rational::operator*=(const Rational& rhs) {

	numerator *= rhs.numerator;

	denominator *= rhs.denominator;


	return *this;
}



Rational& Rational::operator/=(const Rational& rhs) {

	numerator *= rhs.denominator;

	denominator *= rhs.numerator;

	return *this;
}


//single operators + , - , * , / etc should not be friend functions , because 
//they use the public operators += and etc
//const because a + b = c it not valid , copy because the result is a new object 

const Rational operator+(const Rational& lhs, const Rational& rhs) {

	//creating the new object using copy constructor

	//then use operator+=

	return Rational(lhs) += rhs;

}

const Rational poly(const Rational coef[], int n, const Rational & x)
{
	Rational res(0, 1);

	for (int i = 0; i <= n; ++i) {

		Rational temp_mult(1, 1);
		for (int j = 0; j < n - i; ++j) {
			temp_mult *= x;
		}

		res += (coef[i] * temp_mult);

	}

	return res;
}



const Rational operator-(const Rational& lhs, const Rational& rhs) {

	return Rational(lhs) -= rhs;

}



const Rational operator*(const Rational& lhs, const Rational& rhs) {

	return Rational(lhs) *= rhs;
}



const Rational operator/(const Rational& lhs, const Rational& rhs) {

	return Rational(lhs) /= rhs;
}


Rational::operator bool() const {



	return numerator != 0;

}


Rational& Rational::operator++() {



	numerator += denominator;

	return *this;

}


const Rational Rational::operator++(int) {


	Rational temp(*this); //old value

	this->operator++(); //increment our value



	return temp; //return the old

}



Rational& Rational::operator--() {

	numerator -= denominator;

	return *this;

}



const Rational Rational::operator--(int) {

	Rational temp(*this);

	this->operator--();

	return temp;

}


std::ostream& operator<<(std::ostream& ofs, const Rational& r) {

	return ofs << r.numerator << '/'

		<< r.denominator;

}



std::istream& operator>>(std::istream& ifs, Rational& r) {

	return ifs >> r.numerator >> r.denominator;

}