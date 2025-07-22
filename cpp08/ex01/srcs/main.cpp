#include "Span.hpp"

void printTestHeader(const std::string& title, const std::string &color)
{
    std::string box = "[ TEST: " + title + " ]";
    std::cout << color << box << COLOR_RESET << std::endl;
}

int main( void )
{
	{
		printTestHeader("SIZE 0", COLOR_GREEN);
		Span sp(0);
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		printTestHeader("SIZE INT 5", COLOR_GREEN);
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		printTestHeader("Trying add 1 nb", COLOR_CYAN);
		try
		{
			sp.addNumber(0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest Span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl;
		printTestHeader("SIZE INT 1000 w/ range it(1000)", COLOR_GREEN);
		Span sp = Span(1000);
		std::vector<int> v(1000);
		std::vector<int>::iterator it = v.begin();
		srand(time(0));
		for (std::vector<int>::iterator ite = v.end(); it != ite; it++)
			*it = rand() % 10000000;
		try
		{
			sp.addNumber(v.begin(), v.end());
			std::cout << "shortest Span: " << sp.shortestSpan() << std::endl;
			std::cout << "longest Span: " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		printTestHeader("SIZE INT 100 w/ range it(1000)", COLOR_GREEN);
		Span sp = Span(100);
		std::vector<int> v(1000);
		std::vector<int>::iterator it = v.begin();
		srand(time(0));
		for (std::vector<int>::iterator ite = v.end(); it != ite; it++)
			*it = rand() % 10000000;
		try
		{
			sp.addNumber(v.begin(), v.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest Span: " << sp.longestSpan() << std::endl;
	}
	return 0;
}