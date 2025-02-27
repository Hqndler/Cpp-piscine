#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed{

    private:
        int _nbr;
        static const int _fix = 8;

    public:
        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;

        Fixed(void);
        ~Fixed(void);
        Fixed(const int n);
        Fixed(const float f);
        Fixed(const Fixed &f);
        Fixed &operator=(const Fixed &f);

};

std::ostream &operator<<(std::ostream &o, Fixed const &f);

#endif