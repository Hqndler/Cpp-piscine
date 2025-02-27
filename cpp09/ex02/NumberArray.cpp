# include "NumberArray.hpp"

unsigned int NumberVector::getBigPosByIndex(unsigned int index, unsigned int end){
	for (; end != 0;  end--)
		if (nbs[end].getIndex() == index)
			return (end);
	throw(OutOfRangeException());
}

Number & NumberVector::getByIndex(unsigned int index){
	for(unsigned int i = 0; i < len; i++)
		if (nbs[i].getIndex() == index)
			return(nbs[i]);
	throw(OutOfRangeException());
}

void NumberVector::load(std::vector<int> vect){
	for(unsigned int i = 0; i < vect.size(); ++i){
		Number  nb = Number();
		nb.setIndex(i);
		nb.setValue(vect[i]);
		nbs.push_back(nb);
		++len;
	}
}

void NumberDeque::load(std::deque<int> deq){
	for(unsigned int i = 0; i < deq.size(); ++i){
		Number  nb = Number();
		nb.setIndex(i);
		nb.setValue(deq[i]);
		nbs.push_back(nb);
		++len;
	}
}