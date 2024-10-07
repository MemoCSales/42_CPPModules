#include "Serializer.hpp"

// ++++Constructor
Serializer::Serializer(void) {
	if (DEBUG) {
		std::cout << "Serializer default constructor called" << std::endl;
	}
}


uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
