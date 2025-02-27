#pragma once

# include "Number.hpp"
# include <vector>
# include <deque>

class	NumberVector
{
	public:
		NumberVector() : len(0) {};
		NumberVector(std::vector<Number> const & vect) : nbs(vect), len(vect.size()) {};
		~NumberVector() {};
		
		virtual Number &	    operator[](unsigned int i) {return nbs[i];};
		NumberVector &	operator=(NumberVector const & rhs) {
			nbs = rhs.nbs;
			len = rhs.len;
			return *this;
		};
		
		std::vector<Number>&	getVector() {return nbs;};
		unsigned int	getLen() {return len;};
		virtual void			increase() {++len;};

		virtual unsigned int	getBigPosByIndex(unsigned int index, unsigned int end);

		virtual Number &	getByIndex(unsigned int index);

		void	load(std::vector<int> vect);

		virtual void	clear(){
			nbs.clear();
			len = 0;
		};

		virtual void	push(Number nb){
			nbs.push_back(nb);
			len++;
		};

		class	ParsingException: public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Error: Bad entry");
				}
		};

		class	OutOfRangeException: public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Error: Out of range index");
				}
		};


	private:
		std::vector<Number>	nbs;
		unsigned int		len;
};

class	NumberDeque 
{
	public:
		NumberDeque() : len(0) {};
		NumberDeque(std::deque<Number> const & deq) : nbs(deq), len(deq.size()) {};
		~NumberDeque() {};
		
		Number &	    operator[](unsigned int i) {return nbs[i];};
		NumberDeque &	operator=(NumberDeque const & rhs) {
			nbs = rhs.nbs;
			len = rhs.len;
			return *this;
		};
		
		std::deque<Number>&	getDeque() {return nbs;};
		unsigned int		getLen() {return len;};
		void				increase() {++len;};

		unsigned int	getBigPosByIndex(unsigned int index, unsigned int end){
			for (; end != 0;  end--)
				if (nbs[end].getIndex() == index)
					return (end);
			throw(OutOfRangeException());
		};

		Number &	getByIndex(unsigned int index){
			for(unsigned int i = 0; i < len; i++)
				if (nbs[i].getIndex() == index)
					return(nbs[i]);
			throw(OutOfRangeException());
		};

		void	load(std::deque<int> deq);

		void	clear(){
			nbs.clear();
			len = 0;
		};

		void	push(Number nb){
			nbs.push_back(nb);
			len++;
		};

		class	ParsingException: public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Error: Bad entry");
				}
		};

		class	OutOfRangeException: public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Error: Out of range index");
				}
		};


	private:
		std::deque<Number>	nbs;
		unsigned int		len;
};