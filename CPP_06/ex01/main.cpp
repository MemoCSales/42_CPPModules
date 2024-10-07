#include "Serializer.hpp"

int main() {
	Data* dataStruct = new Data;

	std::cout << "Data struct pointer: " << dataStruct << std::endl;

	uintptr_t serializeNumber = Serializer::serialize(dataStruct);
	std::cout << "Serialize: " << serializeNumber << std::endl;

	assert(dataStruct == Serializer::deserialize(serializeNumber));
	std::cout << "Deserialize: " << Serializer::deserialize(serializeNumber) << std::endl;

	return 0;
}
