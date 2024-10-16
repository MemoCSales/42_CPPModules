# include "Array.hpp"

template <typename T> 
Array<T>::Array() : _elements(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array &other) {
	this->_size = other._size;
	this->_elements = new T[_size];
	for (size_t i = 0; i < _size; i++) {
		this->_elements[i] = other._elements[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this != &other) {
		delete [] _elements;
		this->_size = other._size;
		this->_elements = new T[_size];
		for (size_t i = 0; i < _size; i++) {
			this->_elements[i] =  other._elements[i];
		}
	}
	return *this;
}

template <typename T>
int& Array<T>::operator[](int index) {
	if (index < 0 || index >= static_cast<int>(_size)) {
		// std::cout << "index: " << index << std::endl;
		// std::cout << "_size: " << _size << std::endl;
		throw ArrayOutOfBounds();
	}
	return _elements[index];
}

template <typename T>
Array<T>::~Array() {
	delete [] _elements;
}

template <typename T>
size_t Array<T>::size() const {
	return _size;
}
