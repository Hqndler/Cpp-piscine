#include "PMergeMe.hpp"

void FordJohnson_vector(std::vector<int> &vector){
    struct timeval begin, end;

    std::cout << "Vector" << std::endl;
    std::cout << "Before : ";
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    PmergeMeV pm = PmergeMeV(vector);
    gettimeofday(&begin, 0);
    pm.fjSort();
    gettimeofday(&end, 0);

    std::cout << "After : ";
    printNumber(pm.getMergeMe());
    std::cout << std::endl;

    long sec = end.tv_sec - begin.tv_sec;
    long msec = end.tv_usec - begin.tv_usec;
    double timer = sec * 1000000.0 + msec; // 1m
    std::cout << "time to process a range of : " << vector.size() << " with std::vector : " << timer << " us" << std::endl;
    std::cout << std::endl;
}

void FordJohnson_deque(std::deque<int> &deque){
    struct timeval begin, end;

    std::cout << "Deque" << std::endl;

    PmergeMeD pm = PmergeMeD(deque);
    gettimeofday(&begin, 0);
    pm.fjSort();
    gettimeofday(&end, 0);

    long sec = end.tv_sec - begin.tv_sec;
    long msec = end.tv_usec - begin.tv_usec;
    double timer = sec * 1000000.0 + msec; // 1m
    std::cout << "time to process a range of : " << deque.size() << " with std::deque : " << timer << " us" << std::endl;
}