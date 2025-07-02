#include "Span.hpp"

Span::Span(void)
{
}

Span::~Span(void)
{
}

Span::Span(unsigned int N) : _size(N)
{
}

Span::Span(Span const &cpy)
{
	*this = cpy;
}

Span	&Span::operator=(Span const &assign)
{
	if (this != &assign)
		this->_size = assign._size;
	return (*this);
}

void	Span::addNumber(int const &x)
{
	if (this->_tab.size() == _size)
		throw (Span::NoSpaceLeft());
	_tab.push_back(x);
}

void	Span::addNumber(std::vector<int>::iterator it, std::vector<int>::iterator ite)
{
	while (it != ite)
	{
		if (this->_tab.size() == _size)
			throw (Span::NoSpaceLeft());
		_tab.push_back(*it);
		it++;
	}
}


int Span::shortestSpan(void) const
{
	if (_tab.size() <= 1)
		throw (Span::NotEnoughNumber());
	int	min = abs(_tab[0] - _tab[1]);
	for(unsigned long i = 0; i < _tab.size() - 1; i++)
	{
		for (unsigned long j = i + 1; j < _tab.size(); j++)
		{
			if (abs(_tab[i] - _tab[j]) < min)
				min = abs(_tab[i] - _tab[j]);
		}
	}
	return min;
}

int Span::longestSpan(void) const
{
	if (_tab.size() <= 1)
		throw (Span::NotEnoughNumber());
	int	max = abs(_tab[0] - _tab[1]);
	for(unsigned long i = 0; i < _tab.size() - 1; i++)
	{
		for (unsigned long j = i + 1; j < _tab.size(); j++)
		{
			if (abs(_tab[i] - _tab[j]) > max)
				max = abs(_tab[i] - _tab[j]);
		}
	}
	return max;
}

const char *Span::NoSpaceLeft::what(void) const throw()
{
	return ("Can't store more elements");
}

const char *Span::NotEnoughNumber::what(void) const throw()
{
	return ("Not enough numbers stored");
}