#include "Span.hpp"

void ex_main(void){
    Span sp = Span(5);
    sp.add_number(6);
    sp.add_number(3);
    sp.add_number(17);
    sp.add_number(9);
    sp.add_number(11);
    std::cout << sp.shortest_span() << std::endl;
    std::cout << sp.longest_span() << std::endl;

}

int main(void){
    ex_main();
    std::cout << "create an empty span max size 5 -> try shortest span" << std::endl;
    Span sp = Span(5);
    try{
        std::cout << sp.shortest_span() << std::endl;
    }
    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << "try longest" << std::endl;
    try{
        std::cout << sp.longest_span() << std::endl;
    }
    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << "insert 7 numbers" << std::endl;
    try{
        for (int i = 0; i < 7; i++){
            std::cout << i;
            sp.add_number(i);
            std::cout << ", ";
        }
    }
    catch (const std::exception &e){
        std::cout << std::endl;
        std::cerr << e.what() << std::endl;
    }
    std::cout << "shortest span is " << sp.shortest_span() << std::endl;
    std::cout << "longest span is " << sp.longest_span() << std::endl;

    std::cout << "try to insert 12.000 elements using add range inside the 5 elements span lul" << std::endl;
    std::vector<int> vect (12000, 42);
    for (int i = 0; i < 12000; i++)
        vect[i] = i;

    try{
        sp.add_range(vect);
    }
    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << "create a span with 15.000 max size, test of copy constructor" << std::endl;
    Span bsp = Span(15000);
    Span bigsp = Span(bsp);

    try{
        bigsp.add_range(vect);
    }
    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    try{
        std::cout << "shortest span is " << bigsp.shortest_span() << std::endl;
        std::cout << "longest span is " << bigsp.longest_span() << std::endl;
    }
    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}