#include <string>
#include <iostream>

//Creating Class Methods
class Car {
	public:
		int speed(int maxSpeed);
};

int Car::speed(int maxSpeed) {
	return maxSpeed;
}

int main() {
	Car myObj;
	std::cout << myObj.speed(200) << std::endl;
	return (0);
}
