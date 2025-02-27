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

        Fixed &operator=(Fixed const &f);
        
        bool operator>(Fixed const &f);
        bool operator<(Fixed const &f);
        bool operator>=(Fixed const &f);
        bool operator<=(Fixed const &f);
        bool operator==(Fixed const &f);
        bool operator!=(Fixed const &f);

        Fixed operator+(Fixed const &f);
        Fixed operator-(Fixed const &f);
        Fixed operator*(Fixed const &f);
        Fixed operator/(Fixed const &f);

        Fixed operator++(void);
        Fixed operator++(int);
        Fixed operator--(void);
        Fixed operator--(int);

        static Fixed &min(Fixed &l, Fixed &r);
        static const Fixed &min(Fixed const &l, Fixed const &r);
        static Fixed &max(Fixed &l, Fixed &r);
        static const Fixed &max(Fixed const &l, Fixed const &r);
        
};

std::ostream &operator<<(std::ostream &o, Fixed const &f);

#endif