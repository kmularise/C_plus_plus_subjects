#include "Fixed.hpp"

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return rawBits;
}

Fixed& Fixed::operator=(const Fixed& source) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &source) {
        rawBits = source.getRawBits();
    }
    return *this;
}

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    rawBits = 0;
}

Fixed::Fixed(const Fixed& source) {
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(source.getRawBits());
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

void    Fixed::setRawBits(int const rawBits) {
    this->rawBits = rawBits;
}
