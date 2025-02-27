#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point{

    private:
        const Fixed _x;
        const Fixed _y;

    public:
        Point(void);
        ~Point(void);
        Point(const Point &p);
        Point &operator=(const Point &p);

        Point(const float x, const float y);
        Fixed get_x(void) const;
        Fixed get_y(void) const;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif