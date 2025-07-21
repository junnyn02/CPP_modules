#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <stdexcept>
# include <limits>
# include <cerrno>
# include <vector>
# include <list>
# include <ctime>

class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::list<int>		_list;

		PmergeMe(void);
		PmergeMe(PmergeMe const &cpy);
		PmergeMe	&operator=(PmergeMe const &assign);
		
		bool				onlyDigit(const char *) const;

		//vector algo
		std::vector<int>	sort(std::vector<int> &);
    	std::vector<int> 	generateJacobsthal(int) const;
    	std::vector<int> 	generateInsertionOrder(int) const;
    	void 				insert(std::vector<std::pair<int, int> > const &, std::vector<int> &) const;
		int 				binarySearch(std::vector<int> const &, int, int) const;

		//list algo
		std::list<int>	sort(std::list<int> &);
		void			insert(std::list<std::pair<int, int> > const &, std::list<int> &) const;
    	std::list<int> 	generateJacobsthalList(int) const;
    	std::list<int> 	generateInsertionOrderList(int) const;
		int				binarySearch(std::list<int> const &, int , int) const;		
		
	public:
		PmergeMe(char **, int &);
		~PmergeMe(void);

		bool	checkSort(void);
};

# endif