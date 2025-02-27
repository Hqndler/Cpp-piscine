#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{

    private:
        int _nbr;
        static const int _fix = 8;

    public:
        int getRawBits(void) const;
        void setRawBits(int const raw);

        Fixed(void);
        ~Fixed(void);
        Fixed(const Fixed &f);
        Fixed &operator=(const Fixed &f);

};

#endif