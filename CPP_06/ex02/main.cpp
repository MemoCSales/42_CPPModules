# include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	srand(time(0));
	int randNumber = rand();

	if (randNumber % 3 == 0)
		return new A();
	else if (randNumber % 3 == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "Pointer type is: " << WHITE << dynamic_cast<A*>(p) << DEFAULT;
		std::cout << " of class " << GREEN << "A" << DEFAULT << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "Pointer type is: " << WHITE << dynamic_cast<B*>(p) << DEFAULT;
		std::cout << " of class " << BLUE << "B" << DEFAULT << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << "Pointer type is: " << WHITE << dynamic_cast<C*>(p) << DEFAULT;
		std::cout << " of class " << YELLOW << "C" << DEFAULT << std::endl;
	} else {
		std::cout << "Pointer type is NULL" << std::endl;
	}
}

void identify(Base& p) {
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "This is an " << GREEN << "A" << DEFAULT << " class. With address: " << WHITE << &a << DEFAULT << std::endl;
		return ;
	}
	catch(const std::bad_cast& e) {}
	
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "This is an " << BLUE << "B" << DEFAULT << " class. With address: " << WHITE << &b << DEFAULT << std::endl;
		return ;
	}
	catch(const std::bad_cast& e) {}

	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "This is an " << YELLOW << "C" << DEFAULT << " class. With address: " << WHITE << &c << DEFAULT << std::endl;
		return ;
	}
	catch(const std::bad_cast& e) {}

	std::cout << "Unkown type" << std::endl;
}

int main() {

	Base* class1 = generate();

	std::cout << "Identify the class via pointer: " << std::endl;
	identify(class1);
	Base& class1Ref = *class1;
	std::cout << "\nIdentify the class via reference: " << std::endl;
	identify(class1Ref);

	delete class1;
	return 0;
}