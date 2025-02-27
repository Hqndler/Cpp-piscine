#include "Point.hpp"

static Fixed get_intercept(Point const a, Fixed const slope){
    return a.get_y() - a.get_x() * slope;
}

static Fixed get_slope(Point const a, Point const b){
    return (a.get_y() - b.get_y()) / (a.get_x() - b.get_x());
}

static Fixed get_distance(Point const a, Point const b, Point const p){
    if (a.get_x() == b.get_x())
        return p.get_x() - a.get_x();
    
    Fixed slope = get_slope(a, b);
    Fixed inter = get_intercept(a, slope);

    return p.get_y() - slope * p.get_x() - inter;
}

static bool same_side(Point const a, Point const b, Point const c, Point const point){
    Fixed dist_c = get_distance(a, b, c);
    Fixed dist_p = get_distance(a, b, point);

    return ((dist_c * dist_p) > 0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
    bool res = false;

    res = same_side(a, b, c, point);
    res &= same_side(b, c, a, point);
    res &= same_side(c, a, b, point);

    return res;
}