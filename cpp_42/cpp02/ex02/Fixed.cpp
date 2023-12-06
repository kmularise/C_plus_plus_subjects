#include "Fixed.hpp"
#include <cmath>

int Fixed::getRawBits(void) const {
    return rawBits;
}

Fixed& Fixed::operator=(const Fixed& source) {
    if (this != &source) {
        rawBits = source.getRawBits();
    }
    return *this;
}

Fixed::Fixed() {
    rawBits = 0;
}

Fixed::Fixed(const Fixed& source) {
    this->setRawBits(source.getRawBits());
}

Fixed::~Fixed() {
}

void    Fixed::setRawBits(int const rawBits) {
    this->rawBits = rawBits;
}


Fixed::Fixed(const int value) : rawBits(value << fractionalBits) {
}

Fixed::Fixed(const float value) : rawBits(roundf(value * (1 << fractionalBits))) {
}

float Fixed::toFloat() const {
    return static_cast<float>(this->getRawBits()) / (1 << fractionalBits);
}

int Fixed::toInt() const {
    return this->getRawBits() >> fractionalBits;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->getRawBits() > other.getRawBits();
}
bool Fixed::operator<(const Fixed& other) const {
    return this->getRawBits() < other.getRawBits();
}
bool Fixed::operator>=(const Fixed& other) const {
    return this->getRawBits() >= other.getRawBits();
}
bool Fixed::operator<=(const Fixed& other) const {
    return this->getRawBits() <= other.getRawBits();
}
bool Fixed::operator==(const Fixed& other) const {
    return this->getRawBits() == other.getRawBits();
}
bool Fixed::operator!=(const Fixed& other) const {
    return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed newFixed;
    newFixed.setRawBits(this->getRawBits() + other.getRawBits());
    return newFixed;
}
Fixed Fixed::operator-(const Fixed& other) const {
    Fixed newFixed;
    newFixed.setRawBits(this->getRawBits() - other.getRawBits());
    return newFixed;
}
Fixed Fixed::operator*(const Fixed& other) const {
    Fixed newFixed;
    long rawValue = static_cast<long>(this->getRawBits()) * static_cast<long>(other.getRawBits());
    newFixed.setRawBits(rawValue >> fractionalBits);
    return newFixed;
};
Fixed Fixed::operator/(const Fixed& other) const {
    Fixed newFixed;
    newFixed.setRawBits((this->getRawBits() << fractionalBits) / other.getRawBits());
    return newFixed;
};

Fixed& Fixed::operator++() {
    rawBits += 1;
    return *this;
};// pre-increment

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
};// post-increment

Fixed& Fixed::operator--() {
    rawBits -= 1;
    return *this;
};// pre-decrement

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
};// post-decrement

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream & outputStream, Fixed const & source) {
    outputStream << source.toFloat();
    return outputStream;
}