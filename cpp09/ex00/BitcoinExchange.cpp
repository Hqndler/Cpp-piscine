#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void){
	time = std::tm();
	return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &b){
	static_cast<void>(b);
	return;
}

BitcoinExchange::~BitcoinExchange(void){
	return;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &b){
	static_cast<void>(b);
	return *this;
}

float BitcoinExchange::find_in_map(){
	std::map<time_t, float>::iterator it = data.begin();
	time_t t = mktime(&time);
	if (t < it->first)
		return 0;

	it = data.upper_bound(t);
	it--;
	return (it->second * val);
}

void BitcoinExchange::loadinput(std::string input){
	std::ifstream infile;
	std::string line, date, value;
	std::stringstream ss;
	size_t idx;

	infile.open(input.c_str());
	if (!infile.is_open()){
		std::cerr << "Could'nt open " << input << std::endl;
		throw(OpenError());
		return;
	}

	std::getline(infile, line);
	while(std::getline(infile, line)){
		idx = line.find('|');
		if (idx == std::string::npos){
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = line.substr(0, idx);
		value = line.substr(idx + 1);
		if (check_date(date)){
			try{
				check_value(value);
			}
			catch (std::exception &e){
				std::cout << e.what() << std::endl;
				continue;
			}
			std::cout << date << "=>" << value << " = " << find_in_map() << std::endl;
		}
		else
			continue;
	}
	data.clear();
	infile.close();
}

void BitcoinExchange::showmap(void){
	std::map<time_t, float>::iterator it = data.begin();
	std::ofstream outfile;
	while (it != data.end()){
		std::cout << it->first << " -> " << it->second << std::endl;
		it++;
	}
}

void BitcoinExchange::loadcsv(void){
	std::ifstream infile;
	std::string line, date, value;
	size_t idx;

	infile.open("data.csv");
	if (!infile.is_open()){
		std::cerr << "Coudl'nt open data.csv" << std::endl;
		throw(OpenError());
		return;
	}

	std::getline(infile, line);
	while (std::getline(infile, line)){
		idx = line.find(',');
		if (idx == std::string::npos){
			std::cerr << "Error while parsing data.csv" << std::endl;
			continue;
		}
		check_date(line.substr(0, idx));
		try{ check_value(line.substr(idx + 1));	}
		catch (std::exception &e){ static_cast<void>(e); }
		data.insert(std::make_pair(mktime(&time), val));
	}
	infile.close();
	return;
}

bool BitcoinExchange::check_value(std::string value){
	std::stringstream ss;
	ss << value;
	ss >> val;

	if (ss.fail())
		return throw(TooLargeNumber()), false;

	if (val < 0)
		return throw(NotPositiveNumber()), false;

	else if (val > 1000)
		return throw(TooLargeNumber()), false;

	return true;
}

bool BitcoinExchange::check_mounth(std::string date){
	bool check = true;

	//  check année bissextile avec fevrier
	if ((time.tm_year + 1900) % 4 == 0 && time.tm_mon == 1 && time.tm_mday > 29)
			check = false;

	if ((time.tm_year + 1900) % 4 != 0 && time.tm_mon == 1 && time.tm_mday > 28)
			check = false;

	if ((time.tm_mon == 3 || time.tm_mon == 5 || time.tm_mon == 8 || time.tm_mon == 10) && time.tm_mday > 30)
			check = false;

	return (check) ? true : (std::cerr << "Error: bad input => " << date << std::endl, false);
}

bool BitcoinExchange::check_date(std::string date){
	const char *tmp = date.c_str();
	if (!strptime(tmp, "%Y-%m-%d", &time))
		return std::cerr << "Error: bad input => " << date << std::endl, false;
	return check_mounth(date);
}