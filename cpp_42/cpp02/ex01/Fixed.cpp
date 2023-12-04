#include "Fixed.hpp"
#include <cmath>

int Fixed::getRawBits(void) const {
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


Fixed::Fixed(const int value) : rawBits(value << fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : rawBits(roundf(value * (1 << fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat() const {
    return static_cast<float>(this->getRawBits()) / (1 << fractionalBits);
}

int Fixed::toInt() const {
    return this->getRawBits() >> fractionalBits;
}

std::ostream& operator<<(std::ostream & outputStream, Fixed const & source) {
    outputStream << source.toFloat();
    return outputStream;
}