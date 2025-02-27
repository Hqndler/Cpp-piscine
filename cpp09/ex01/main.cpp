#include "RPN.hpp"

int main(int argc, char **argv){
    if (argc != 2 || (argv[1] && !argv[1][0])){
        std::cout << "Please write a reverse polish notation" << std::endl;
        return (1);
    }

    try{
        rpn(argv[1]);
    }

    catch (std::exception &e){
        std::cout << e.what() << std::endl;
        return (1);
    }

    return (0);
}