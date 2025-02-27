#pragma once

# include <iostream>
# include <string>
# include <sstream>
# include <algorithm>
# include <deque>
# include <vector>
# include <sys/time.h>
# include "NumberArray.hpp"


void FordJohnson_vector(std::vector<int> &vector);
void FordJohnson_deque(std::deque<int> &deque);

class ParsingError : public std::exception{
	public:
		virtual const char *what() const throw(){
			return "Parsing Error";
		}
};

template<typename T>
void fill(T &container, char **argv, int size){
	for(int i = 1; i < size; ++i){
		std::stringstream ss(argv[i]);
		int num;
		ss >> num;
		if (!ss.fail())
			container.push_back(num);
		else{
			std::cout << argv[i] << std::endl;
			throw(ParsingError());
		}
	}
}

class	PmergeMeV
{
	public:
		PmergeMeV() {};
		PmergeMeV(std::vector<int> &vec) {merge_me.load(vec);};
		PmergeMeV(PmergeMeV const & rhs) {*this = rhs;};
		PmergeMeV(NumberVector const &mm) : merge_me(mm) {};
		~PmergeMeV() {};

		void	fjSort(){
			if (merge_me.getLen() == 1)
				return;

			pairSwap();
			splitMe();

			PmergeMeV big_sorting = PmergeMeV(halfbig.getVector());
			big_sorting.fjSort();
			halfbig = big_sorting.getMergeMe();

			reload();
			reinsert();
		};

		NumberVector&	getMergeMe() {return merge_me;};

		virtual void	pairSwap(){
			for (unsigned int i = 0; i < merge_me.getLen() - 1; i += 2){
				if (merge_me[i] < merge_me[i + 1]){
					Number tmp = merge_me[i];
					merge_me[i] = merge_me[i + 1];
					merge_me[i + 1] = tmp;
				}
			}
		};

		virtual void	splitMe(){
			unsigned int i = 0;	
			Number	pr = Number();

			for (; i < merge_me.getLen() - 1; i += 2){
				pr.setValue(merge_me[i + 1].getIndex());
				pr.setIndex(merge_me[i].getIndex());
				pairing.push(pr);
				halfbig.push(merge_me[i]);
				remain.push(merge_me[i + 1]);
			}

			if (merge_me.getLen() % 2){
				pr.setValue(merge_me[i].getIndex());
				pr.setIndex(-1);
				pairing.push(pr);
				remain.push(merge_me[i]);
			}
		};
		
		virtual void	reload(){
			unsigned int	index;	
			Number			to_insert = Number();

			merge_me.clear();

			index = halfbig.getVector().front().getIndex();
			index = pairing.getByIndex(index).getValue();

			to_insert = remain.getByIndex(index);
			merge_me.push(to_insert);

			for (unsigned int i = 0; i < halfbig.getLen(); i++)
				merge_me.push(halfbig[i]);
		};
		
		virtual void	reinsert(){
			getOrder();
	
			for (size_t i = 0; i < the_order.size(); i++)
			{
				unsigned int	index;
				unsigned int	end;

				if (the_order[i] < static_cast<int>(halfbig.getLen())){
					index = halfbig[the_order[i]].getIndex();
					end = merge_me.getBigPosByIndex(index, the_order[i] + i + 1);
				}
				
				else{
					index = -1;
					end = merge_me.getLen() - 1;
				}
				
				index = pairing.getByIndex(index).getValue();
				binaryInsert(remain.getByIndex(index), end);
			}
		};
		
		virtual void	getOrder(){
			unsigned int	group = 1;
			unsigned int	current = 2;
			unsigned int	g = 0;

			while (group)
			{
				g = nextGroupSize(g, group);
				unsigned int maxi = std::min(current + g, remain.getLen() + 1);
				
				if (current + g > remain.getLen())
					group = -1;
				
				for (unsigned int i = maxi; i > current; i--)
					the_order.push_back(i - 2);
				
				current += g;
				++group;
			}
		};
		
		virtual unsigned int	nextGroupSize(unsigned int g, unsigned int group){
			unsigned int gs = 1;
			
			for (unsigned i = 0; i < group; ++i)
				gs *= 2;
			
			return (gs - g);
		};

	private:
		void	binaryInsert(Number r, long int right){
			long int						left = 0;
			long int						pos;
			std::vector<Number>::iterator	it = merge_me.getVector().begin();
			
			while (1)
			{
				if (right - left == 1){
					if (r < merge_me[left])
						pos = left - 1;
					else if (merge_me[right] < r)
						pos = right;
					else
						pos = left;
					break ;
				}
				pos = (left + right) / 2;
				if (merge_me[pos] < r){
					if (pos == merge_me.getLen() - 1 || pos == left)
						break ;
					left = pos;
				}
				
				else if (r < merge_me[pos]){
					if (pos == 0)
					{
						pos = -1;
						break;
					}
					if (pos == right)
						break;
					right = pos;
				}
				else
					break ;
			}
			
			merge_me.getVector().insert(it + pos + 1, r);
			merge_me.increase();
		};

		NumberVector		merge_me;
		NumberVector		halfbig;
		NumberVector		remain;
		NumberVector		pairing;
		std::vector<int>	the_order;
};

class	PmergeMeD 
{
	public:
		PmergeMeD() {};
		PmergeMeD(std::deque<int> &deq) {merge_me.load(deq);};
		PmergeMeD(PmergeMeD const & rhs) {*this = rhs;};
		PmergeMeD(NumberDeque const &mm) : merge_me(mm) {};
		~PmergeMeD() {};

		void	fjSort(){
			if (merge_me.getLen() == 1)
				return;
			
			pairSwap();
			splitMe();

			PmergeMeD big_sorting = PmergeMeD(halfbig.getDeque());
			big_sorting.fjSort();
			halfbig = big_sorting.getMergeMe();

			reload();
			reinsert();
		};

		NumberDeque&	getMergeMe() {return merge_me;};

	private:
		void	pairSwap(){
			for (unsigned int i = 0; i < merge_me.getLen() - 1; i += 2){
				if (merge_me[i] < merge_me[i + 1]){
					Number tmp = merge_me[i];
					merge_me[i] = merge_me[i + 1];
					merge_me[i + 1] = tmp;
				}
			}
		};

		void	splitMe(){
			unsigned int i = 0;	
			Number	pr = Number();

			for (; i < merge_me.getLen() - 1; i += 2){
				pr.setValue(merge_me[i + 1].getIndex());
				pr.setIndex(merge_me[i].getIndex());
				pairing.push(pr);
				halfbig.push(merge_me[i]);
				remain.push(merge_me[i + 1]);
			}

			if (merge_me.getLen() % 2){
				pr.setValue(merge_me[i].getIndex());
				pr.setIndex(-1);
				pairing.push(pr);
				remain.push(merge_me[i]);
			}
		};
		
		void	reload(){
			unsigned int	index;	
			Number			to_insert = Number();

			merge_me.clear();

			index = halfbig.getDeque().front().getIndex();
			index = pairing.getByIndex(index).getValue();

			to_insert = remain.getByIndex(index);
			merge_me.push(to_insert);

			for (unsigned int i = 0; i < halfbig.getLen(); i++)
				merge_me.push(halfbig[i]);
		};
		
		void	reinsert(){
			getOrder();
	
			for (size_t i = 0; i < the_order.size(); i++)
			{
				unsigned int	index;
				unsigned int	end;

				if (the_order[i] < static_cast<int>(halfbig.getLen())){
					index = halfbig[the_order[i]].getIndex();
					end = merge_me.getBigPosByIndex(index, the_order[i] + i + 1);
				}
				
				else{
					index = -1;
					end = merge_me.getLen() - 1;
				}
				
				index = pairing.getByIndex(index).getValue();
				binaryInsert(remain.getByIndex(index), end);
			}
		};
		
		void	getOrder(){
			unsigned int	group = 1;
			unsigned int	current = 2;
			unsigned int	g = 0;

			while (group)
			{
				g = nextGroupSize(g, group);
				unsigned int maxi = std::min(current + g, remain.getLen() + 1);
				
				if (current + g > remain.getLen())
					group = -1;
				
				for (unsigned int i = maxi; i > current; i--)
					the_order.push_back(i - 2);
				
				current += g;
				++group;
			}
		};
		
		unsigned int	nextGroupSize(unsigned int g, unsigned int group){
			unsigned int gs = 1;
			
			for (unsigned i = 0; i < group; ++i)
				gs *= 2;
			
			return (gs - g);
		};
		
		void	binaryInsert(Number r, long int right){
			long int						left = 0;
			long int						pos;
			std::deque<Number>::iterator	it = merge_me.getDeque().begin();

			while (1)
			{
				if (right - left == 1){
					if (r < merge_me[left])
						pos = left - 1;
					else if (merge_me[right] < r)
						pos = right;
					else
						pos = left;
					break ;
				}
				pos = (left + right) / 2;
				if (merge_me[pos] < r){
					if (pos == merge_me.getLen() - 1 || pos == left)
						break ;
					left = pos;
				}
				
				else if (r < merge_me[pos]){
					if (pos == 0)
					{
						pos = -1;
						break;
					}
					if (pos == right)
						break;
					right = pos;
				}
				else
					break ;
			}
			merge_me.getDeque().insert(it + pos + 1, r);
			merge_me.increase();
		};

		NumberDeque			merge_me;
		NumberDeque			halfbig;
		NumberDeque			remain;
		NumberDeque			pairing;
		std::deque<int>		the_order;
};

template<typename NumberArray>
void printNumber(NumberArray array){
	for (unsigned int i = 0; i < array.getLen(); i++)
	{
		std::cout << array[i];
		if (i != array.getLen() - 1)
			std::cout << " ";
		else
			std::cout << std::endl;
	}
}

