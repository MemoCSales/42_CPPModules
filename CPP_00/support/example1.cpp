#include <string>
#include <iostream>

/*
	Calling a constructor == Creating an object of the class
*/
class Car
{
	public:														//Access specifier
		Car();													//Constructor
		Car(std::string pbrand, std::string pmodel, int pyear);	//ATTRIBUTE -> Declaration of a parameterized constructor for the 'Car' class
		std::string brand;										//ATTRIBUTE -> Declaration of a public member veriable 'brand' of type 'std::string'
		std::string model;
		int year;												//Declaration of a public member variable of type int
};

// Constructor definition outside the class
Car::Car(void)
{
	std::cout << "Hello world !" << std::endl;
	brand = "default brand";
	model = "default model";
	year= 0;
	return ;
};

// Constructor definition outside the class
Car::Car(std::string pbrand, std::string pmodel, int pyear)
{
	brand = pbrand;												//sets the brand member variable to the value of pbrand
	model = pmodel;
	year = pyear;
	// return ;
};

int main() {
	Car car1;													//Creates an object 'car1' of the class Car using the default constructor
	Car car2("Ford", "Mustang", 1969);							//Creates an object 'car2' of the 'Car' class using a param... constructor

	std::cout << car1.brand << " " << car1.model << " " << car1.year << std::endl;
	std::cout << car2.brand << " " << car2.model << " " << car2.year << std::endl;
	return (0);
}