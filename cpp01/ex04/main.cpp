#include <iostream>
#include <fstream>
#include <string>

void replace(std::string file, std::string s1, std::string s2){
    std::ifstream infile;

    infile.open(file.c_str());
    if (!infile.is_open()){
        std::cerr << "Bad rights on `" << file << "`." << std::endl;
        return;
    }

    std::ofstream outfile((file + ".replace").c_str());
    if (!outfile.is_open()){
        std::cerr << "Couldn't create `" << file << ".replace`." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infile, line)){
        int offset = 0;
        while (true){
            std::size_t check = line.find(s1, offset);
            if (check == std::string::npos)
                break;
            line.erase(check, s1.length()).insert(check, s2);
            offset += check + s2.length();
            }
        outfile << line << std::endl;
    }
}

int main(int argc, char **argv){
    if (argc != 4){
        std::cerr << "Bad input" << std::endl;
        return 1;
    }
    replace(argv[1], argv[2], argv[3]);
    return 0;
}