#include "Span.hpp"

Span::Span(unsigned int N) : _N(N), _numbers(0) {
	if (DEBUG) {
		std::cout << "Span parameter constructor called" << std::endl;
	}
}

// Copy Constructor
Span::Span(const Span &other) {
	if (DEBUG) {
		std::cout << "Span copy constructor called" << std::endl;
	}
	this->_N = other._N;
	this->_numbers = other._numbers;
}

// Assignment Operator
Span &Span::operator=(const Span &other) {
	if (DEBUG) {
		std::cout << "Span Assignment Operator called" << std::endl;
	}
	if (this != &other) {
		this->_N = other._N;
		this->_numbers = other._numbers;
	}
	return *this;
}

// ----Destructor
Span::~Span() {
	if (DEBUG) {
		std::cout << "Span destructor called" << std::endl;
	}
}


// Methods
void Span::addNumber(int value) {
	if (_numbers.size() != _N) {
		_numbers.push_back(value);
	} else {
		throw MaximumCapacity();
	}
}

void Span::printNumbers() const {
	int index = 0;
	for (std::vector<int>::const_iterator it = _numbers.begin(); it != _numbers.end(); it++, index++)
	{
		std::cout << "Numbers[" << index << "] = " << *it << std::endl;
	}
}


/*	Sort the numbers in ascending order, then iterate through
	to find the smallest difference between consecutive numbers
*/
int Span::shortestSpan() {
	if (_numbers.size() < 2) {
		throw MaximumCapacity();
	} else {
		std::vector<int>::iterator first = _numbers.begin();
		std::vector<int>::iterator last = _numbers.end();
		sort(first, last);
		int shortest = INT_MAX;
		for (size_t i = 0; i != _numbers.size() - 1; i++)
		{
			// std::cout << "( " << _numbers[i+1] << " - " << _numbers[i] << " ) = " << _numbers[i+1] - _numbers[i] << std::endl;
			if (shortest > (_numbers[i + 1] - _numbers[i])) {
				shortest = _numbers[i + 1] - _numbers[i];
				// std::cout << "\tshortest: " << shortest << std::endl;
			}
		}
		return shortest;
	}
}

/*	Find the minimum and maximum values in the container,
	then compute the differente between them
*/
int Span::longestSpan() {
	if (_numbers.size() < 2) {
		throw SpanError() ;
	} else {
		int min = *std::min_element(_numbers.begin(), _numbers.end());
		int max = *std::max_element(_numbers.begin(), _numbers.end());
		return max - min;
	}
}


void Span::populateVector(int max, int min) {
	if (static_cast<unsigned int>(max - min + 1) < _N)
	{
		throw std::out_of_range("Range is too low to generate numbers");
	}
	
	std::set<int> uniqueNumbers;
	srand(static_cast<unsigned int>(time(0)));

	while(uniqueNumbers.size() < _N) {
		int number = min + rand() % (max - min + 1);
		uniqueNumbers.insert(number);
	}
	_numbers.assign(uniqueNumbers.begin(), uniqueNumbers.end());
}
