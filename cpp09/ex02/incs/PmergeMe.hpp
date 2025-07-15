#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <stdexcept>
# include <limits>
# include <cerrno>
# include <vector>
# include <sys/time.h>

class PmergeMe
{
	private:
		std::vector<int>	_vector;

		PmergeMe(void);
		PmergeMe(PmergeMe const &cpy);
		PmergeMe	&operator=(PmergeMe const &assign);

	public:
		PmergeMe(char **, int &);
		~PmergeMe(void);
		
		void	sort(std::vector<int> &);

		bool	onlyDigit(const char *) const;
		bool	isSort(void);
};

# endif