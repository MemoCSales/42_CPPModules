# include "Span.hpp"

int main()
{
	// try	{
	// 	Span sp = Span(5);
	// 	sp.addNumber(6);
	// 	sp.addNumber(3);
	// 	sp.addNumber(17);
	// 	sp.addNumber(9);
	// 	sp.addNumber(11);
	// 	// sp.addNumber(42);
	// 	// sp.printNumbers();
	// 	std::cout << sp.shortestSpan() << std::endl;
	// 	std::cout << sp.longestSpan() << std::endl;
	// 	// sp.printNumbers();
	// }
	// catch(const std::exception& e)	{
		// std::cerr << RED << "Exception: " << DEFAULT << e.what() << '\n';
	// }

	try
	{
		int max = 5;
		Span sp2 = Span(max);
		
		int minValue = 1;
		int maxValue = 200;
		sp2.populateVector(maxValue, minValue);
		// sp2.addNumber(200);
		// sp2.printNumbers();
		std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
		
	}
	catch(const std::exception& e)	{
		std::cerr << RED << "Exception: " << DEFAULT << e.what() << '\n';
	}
	
	
	return 0;
}
