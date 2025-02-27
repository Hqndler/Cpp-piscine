#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span{

	private:
		size_t size;
		std::vector<int> vect;

		class SpanFullException : public std::exception{
			public:
				virtual const char *what() const throw(){
					return "Span Exception : Span is full";
				}
		};

		class SpanEmptyException : public std::exception{
			public:
				virtual const char *what() const throw(){
					return "Span Exception : Span is empty";
				}
		};

		class SpanNotEnoughValueException : public std::exception{
			public:
				virtual const char *what() const throw(){
					return "Span Exception : Span don't have enough values";
				}
		};

		class SpanOutOfRangeException : public std::exception{
			public:
				virtual const char *what() const throw(){
					return "Span Exception : Span index out of range";
				}
		};

		class SpanDistanceException : public std::exception{
			public:
				virtual const char *what() const throw(){
					return "Span Exception : No distance found in span";
				}
		};

	public:
		Span(void);
		Span(const size_t size);
		Span(const Span &s);
		Span &operator=(const Span &s);
		~Span(void);

		void add_number(int nb);
		void add_range(std::vector<int> v);
		size_t shortest_span(void);
		size_t longest_span(void);

};

#endif