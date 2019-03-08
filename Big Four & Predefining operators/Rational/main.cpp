#include "Rational.h"

int main() {

	Rational a(2, 3);
	Rational b(3, 2);
	Rational c(5, 6);

	Rational arr[3];
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;

	Rational x(2, 3);
	Rational res = poly(arr, 2, x);

	res.simplify();

	std::cout << res;

	return 0;
}