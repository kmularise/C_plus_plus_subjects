#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed c(Fixed(1) / Fixed(2));
	std::cout << c << std::endl;
	Fixed d(Fixed(4.0f));
	Fixed e(Fixed(4));
	std::cout << (d == e) << std::endl;
	Fixed f(Fixed(1));
	std::cout << f << std::endl;
	std::cout << --f << std::endl;
	std::cout << f-- << std::endl;
	std::cout << f << std::endl;
	return 0;
}