#include "PMergeMe.hpp"

/* J'ai pas réussi à le faire en template sorry le code va être horrible et va beaucoup se repeter */

int main(int argc, char **argv){
    if (argc == 1){
        std::cout << "Please enter a sequence of number to be sorted out" << std::endl;
        return 1;
    }
    std::vector<int> vector;
    std::deque<int> deque;
    try{
        fill(vector, argv, argc);
        fill(deque, argv, argc);
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
        return (1);
    }

    try{
        FordJohnson_vector(vector);
        FordJohnson_deque(deque);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}