# include "MutantStack.hpp"
# include <iomanip>
# include <list>

int main()
{

	// MUTANTSTACK
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top(last) element in the stack: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size of the stack: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	// LIST
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << "Last element in the list: " << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << "Size of the stack: " << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);
	std::list<int>::iterator itList = mlist.begin();
	std::list<int>::iterator iteList = mlist.end();
	++itList;
	--itList;
	std::list<int> s(mlist);

	std::cout << CYAN << "TEST MUTANTSTACK AGAINST LIST:" << DEFAULT << std::endl;
	std::cout << std::left << std::setw(10) << "Stack" << std::setw(10) << "List" << std::endl;
	std::cout << std::string(20, '-') << std::endl;
	while (itList != iteList && it != ite) {
		std::cout << std::left << std::setw(5) << *it << "  --  " << std::setw(10) <<  *itList << std::endl;
		++it;
		++itList;
	}
	// std::stack<int> s(mstack);
	return 0;
}

// int main()
// {
// 	std::list<int> mstack;
// 	mstack.push_back(5);
// 	mstack.push_back(17);
// 	std::cout << mstack.back() << std::endl;
// 	mstack.pop_back();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	//[...]
// 	mstack.push_back(0);
// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite) {
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::list<int> s(mstack);
// 	return 0;
// }
