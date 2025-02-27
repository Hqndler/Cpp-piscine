#include "Point.hpp"

static void print_result(Point a, Point b, Point c, Point p, std::string point, std::string name){
    if (bsp(a, b, c, p))
        std::cout << point << " is inside " << name << std::endl;
    else
        std::cout << point << " is outside " << name << std::endl;
}

int main(void)
{
	Point	A(0.0f, 0.0f);
	Point	B(0.0f, 4.0f);
	Point	C(-3.0f, 0.0f);
	Point	D(1.0f, 1.0f);
	Point	E(5.0f, 2.0f);
	Point	F(4.0f, 6.0f);
	Point	G(1.0f, -1.0f);
	Point	H(7.0f, -1.0f);
	Point	I(12.0f, -4.0f);
	Point	J(-1.0f, 1.0f);
	Point	K(3.0f, 3.0f);
	Point	L(4.0f, -1.0f);
	Point	M(7.0f, -2.0f);

	print_result(A, B, C, J, "J", "ABC");
    print_result(A, B, C, A, "A", "ABC");
    print_result(A, B, C, K, "K", "ABC");
    print_result(A, B, C, G, "G", "ABC");
    print_result(D, E, F, K, "K", "DEF");
    print_result(D, E, F, A, "A", "DEF");
    print_result(D, E, F, F, "F", "DEF");
	print_result(D, E, F, L, "L", "DEF");
    print_result(G, H, I, M, "M", "GHI");
    print_result(G, H, I, L, "L", "GHI");
    print_result(G, H, I, B, "B", "GHI");
    print_result(G, H, I, J, "J", "GHI");
    print_result(B, C, I, J, "J", "BCI");
    print_result(B, C, I, L, "L", "BCI");
    print_result(B, C, I, G, "G", "BCI");
    print_result(C, C, I, K, "K", "BCI");

	return 0;
}