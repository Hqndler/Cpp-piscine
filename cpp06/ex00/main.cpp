#include "Convert.hpp"

int main(int argc, char **argv){
    if (argc != 2){
        std::cerr << "Enter only one number" << std::endl;
        return 1;
    }
    std::string str = static_cast<std::string>(argv[1]);
    Convert::converter(str);
    return 0;
}