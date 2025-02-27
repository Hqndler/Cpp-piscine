#include <ctime>
#include <iostream>
#include <iomanip>

int main(void)
{
    time_t  now = std::time(0);
    tm      *local = localtime(&now);

    std::cout << local->tm_year + 1900 << std::endl;
    std::cout << std::setfill('0') << std::setw(2) << local->tm_mon + 1 << std::endl;
    std::cout << std::setfill('0') << std::setw(2) << local->tm_mday << std::endl;
    std::cout << std::setfill('0') << std::setw(2) << local->tm_hour << std::endl;
    std::cout << std::setfill('0') << std::setw(2) << local->tm_min << std::endl;
    std::cout << std::setfill('0') << std::setw(2) << local->tm_sec << std::endl;
    return 0;
}