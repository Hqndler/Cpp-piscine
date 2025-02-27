#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <iomanip>

struct Data{
		char c;
		int i;
		float f;
		double d;

		bool bc;
		bool bi;
		bool bf;
		bool bd;

		std::string s;
};

class Convert{

	private:
		Convert(void);
		Convert(std::string s);
		Convert(const Convert &c);
		Convert &operator=(const Convert &c);

	public:
		static int get_type(std::string s);
		static int parsing(std::string s);
		static Data charcast(Data d);
		static Data intcast(Data d);
		static Data floatcast(Data d);
		static Data doublecast(Data d);
		static Data dspecast(Data d);
		static Data fspecast(Data d);
		static void printnumber(Data d);
		virtual ~Convert(void);

		static void converter(std::string s);

};

#endif