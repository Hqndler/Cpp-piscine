#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>    
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <ctime>

class BitcoinExchange{

	private:
		std::map<time_t, float> data;
		float val;
		std::tm time;
		BitcoinExchange(const BitcoinExchange &b);
		BitcoinExchange &operator=(const BitcoinExchange &b);

		class NotPositiveNumber : public std::exception{
			public:
				virtual const char *what() const throw(){
					return "Error: not a positive number";
				}
		};

		class TooLargeNumber : public std::exception{
			public:
				virtual const char *what() const throw(){
					return "Error: too large number";
				}
		};

		class OpenError : public std::exception{
			public:
				virtual const char *what() const throw(){
					return "";
				}
		};

	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);

		void loadcsv(void);
		void loadinput(std::string input);
		void showmap(void);

		float find_in_map(void);

		bool check_mounth(std::string date);
		bool check_date(std::string date);
		bool check_value(std::string value);

};

#endif