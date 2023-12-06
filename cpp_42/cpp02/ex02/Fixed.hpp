#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int rawBits;
        static const int fractionalBits = 8;
    public:
        Fixed(const int value);
        Fixed(const float value);
        float toFloat() const;
        int toInt() const;
        Fixed();
        Fixed(const Fixed& source);
        ~Fixed();
        Fixed& operator=(const Fixed& source);
        int getRawBits(void) const;
        void    setRawBits(int const rawBits);
        
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed& operator++();    // pre-increment
        Fixed operator++(int);  // post-increment
        Fixed& operator--();    // pre-decrement
        Fixed operator--(int);  // post-decrement


        static Fixed& min( Fixed &a, Fixed &b );
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max( Fixed &a, Fixed &b );
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& outputStream, Fixed const& source);

#endif