#include "MutantStack.hpp"
#include <list>

int main( void )
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		std::cout << "mstack.begin() nb: " << *it << std::endl;
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		std::cout << "pre increment nb: " << *it << std::endl;
		--it;
		while (it != ite)
		{
			std::cout << "nb: " << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		// MutantStack<int>::const_iterator cit = mstack.cbegin();
		// *cit = 7;
	}
	{
		std::cout << "---------------List Test---------------" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << "top: " << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::cout << "mstack.begin() nb: " << *it << std::endl;
		std::list<int>::iterator ite = mstack.end();
		++it;
		std::cout << "pre increment nb: " << *it << std::endl;
		--it;
		while (it != ite)
		{
			std::cout << "nb: " << *it << std::endl;
			++it;
		}
		// std::stack<int> s(mstack);
		return 0;
	}
}