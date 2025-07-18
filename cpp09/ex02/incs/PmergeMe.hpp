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
    	std::vector<int> 	generateJacobsthal(int maxIndex) const;
    	std::vector<int> 	generateInsertionOrder(int numElements) const;
    	void 				insert(std::vector<std::pair<int, int> > const &pairs, std::vector<int> const &S, std::vector<int> &result) const;
		int 				binarySearch(std::vector<int> const &S, int n, int maxPos) const;

		//list algo
		std::list<int>	sort(std::list<int> &);
		void 			insert(std::list<std::pair<int, int> > &pairs, std::list<int> const &S, std::list<int> &result) const;
    	std::list<int> 	generateJacobsthalList(int maxIndex) const;
    	std::list<int> 	generateInsertionOrderList(int numElements) const;
		int				binarySearch(std::list<int> const &S, int n, int maxPos) const;		
		
	public:
		PmergeMe(char **, int &);
		~PmergeMe(void);

		bool	checkSort(void);
};

# endif