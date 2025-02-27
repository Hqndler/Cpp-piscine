#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
	if (argc != 2){
        std::cerr << "No input provided" << std::endl;
        return 1;
    }
    std::string input(argv[1]);
    BitcoinExchange btc;
    try{
        btc.loadcsv();
        btc.loadinput(input);
    }
    catch (std::exception &e){
        static_cast<void>(e);
    }
    return 0;
}