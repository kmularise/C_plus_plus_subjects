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
};

std::ostream& operator<<(std::ostream& outputStream, Fixed const& source);

#endif