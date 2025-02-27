#include "Convert.hpp"

Convert::Convert(void){
	return;
}

Convert::~Convert(void){
	return;
}
// ouais faut pas regarder ça 
int Convert::parsing(std::string s){
	int	state = 0;

	for (unsigned int i = 0 ; i < s.size(); i++){
		switch (state){
			case 0:
				if (isdigit(s[i]))
					state = 1;
				else if ((s[i] != '+' || s[i] != '-'))
					state = 6;
				else
					state = 7;
				break;
			case 1:
				if (s[i] == '.')
					state = 8;
				else if (!isdigit(s[i]))
					state = 7;
				break;
			case 2:
				if (s[i] == 'f')
					state = 3;
				else if (!isdigit(s[i]))
					state = 7;
				break;
			case 3:
				state = 7;
				break;
			case 6:
				if (isdigit(s[i]))
					state = 1;
				else
					state = 7;
				break;
			case 7:
				break;
			case 8:
				if (isdigit(s[i]))
					state = 2;
				else
					state = 7;
				break;
			default:
				state = 7;
				break;
		}
		if (state == 7)
			break;
	}
	if (state == 6 || state == 8)
		state = 7;
	return state;
}

int Convert::get_type(std::string s){
	std::string const dspe[3] = {"-inf", "+inf", "nan"};
	std::string const fspe[3] = {"-inff", "+inff", "nanf"};

	if (s.size() == 1 && isprint(s[0]) && !isdigit(s[0]))
		return 0;

	for (int i = 0; i < 3; i++){
		if (s.compare(dspe[i]) == 0)
			return 4;
		if (s.compare(fspe[i]) == 0)
			return 5;
	}
	return (parsing(s));
}

Data Convert::charcast(Data d){
	d.c = d.s[0];
	d.bc = true;

	d.i = static_cast<int>(d.c);
	d.bi = true;

	d.f = static_cast<float>(d.c);
	d.bf = true;

	d.d = static_cast<double>(d.c);
	d.bd = true;
	return d;
}

Data Convert::intcast(Data d){
	std::stringstream ss;

	ss << d.s;
	ss >> d.d;
	if (ss.fail())
		d.bd = false;
	else
		d.bd = true;

	if (!ss.fail() && d.d <= static_cast<double>(std::numeric_limits<int>::max()) && d.d >= static_cast<double>(std::numeric_limits<int>::min())){
		d.i = static_cast<int>(d.d);
		d.bi = true;
	}

	if (d.bi && d.i <= static_cast<int>(std::numeric_limits<char>::max()) && d.i >= static_cast<int>(std::numeric_limits<char>::min())){
		d.c = static_cast<char>(d.i);
		d.bc = true;
	}

	d.f = static_cast<float>(d.d);
	d.bf = true;
	return d;
}

Data Convert::floatcast(Data d){
	std::stringstream ss;

	ss << d.s;
	ss >> d.f;
	if (ss.fail())
		return d;
	d.bf = true;

	if (d.f <= static_cast<float>(std::numeric_limits<char>::max()) && d.f >= static_cast<float>(std::numeric_limits<char>::min())){
		d.c = static_cast<char>(d.f);
		d.bc = true;
	}
	if (d.f <= static_cast<float>(std::numeric_limits<int>::max()) && d.f >= static_cast<float>(std::numeric_limits<int>::min())){
		d.i = static_cast<int>(d.f);
		d.bi = true;
	}

	d.d = static_cast<double>(d.f);
	d.bd = true;
	return d;
}

Data Convert::doublecast(Data d){
	std::stringstream ss;

	ss << d.s;
	ss >> d.d;
	if (ss.fail())
		return d;
	d.bd = true;

	if (d.d <= static_cast<double>(std::numeric_limits<char>::max()) && d.d >= static_cast<double>(std::numeric_limits<char>::min())){
		d.c = static_cast<char>(d.d);
		d.bc = true;
	}
	if (d.d <= static_cast<double>(std::numeric_limits<int>::max()) && d.d >= static_cast<double>(std::numeric_limits<int>::min())){
		d.i = static_cast<int>(d.d);
		d.bi = true;
	}
	if ((d.d <= static_cast<double>(std::numeric_limits<float>::max()) && d.d >= static_cast<double>(std::numeric_limits<float>::min())) || d.d == 0){
		d.f = static_cast<float>(d.d);
		d.bf = true;
	}
	return d;
}

Data Convert::dspecast(Data d){
	d.d = std::strtod(d.s.c_str(), NULL);
	d.bd = true;

	d.f = static_cast<float>(d.d);
	d.bf = true;
	return d;
}

Data Convert::fspecast(Data d){
	d.f = std::strtof(d.s.c_str(), NULL);
	d.bf = true;

	d.d = static_cast<double>(d.f);
	d.bd = true;
	return d;
}

void Convert::printnumber(Data d){
	if (d.bc){
		if (isprint(d.c))
			std::cout << "char : " << d.c << std::endl;
		else
			std::cout << "char : " << "Non displayable" << std::endl;
	}
	else
		std::cout << "char : impossible" << std::endl;
	
	if (d.bi)
		std::cout << "int : " << d.i << std::endl;
	else
		std::cout << "int : impossible" << std::endl;

	if (d.bf)
		std::cout << "float : " << std::fixed << std::setprecision(1) << d.f << "f" << std::endl;
	else
		std::cout << "float : impossible" << std::endl;

	if (d.bd)
		std::cout << "double : " << std::fixed << std::setprecision(1) << d.d << std::endl;
	else
		std::cout << "double : impossible" << std::endl;
}

void Convert::converter(std::string str){
	int type = 4;
	Data d = {0, 0, 0, 0, false, false, false, false, str};

	Data (*fcast[])(Data) = {
		charcast, 
		intcast, 
		doublecast, 
		floatcast, 
		dspecast, 
		fspecast
	};

	type = get_type(d.s);

	if (type == 7){
		std::cerr << "Parsing error" << std::endl;
		return;
	}

	d = fcast[type](d);
	printnumber(d);
}

Convert::Convert(std::string s){
	static_cast<void>(s);
}

Convert::Convert(const Convert &c){
	static_cast<void>(c);
	return;
}