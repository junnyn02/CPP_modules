#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <stdexcept>
# include <limits>
# include <cerrno>
# include <vector>
# include <ctime>

// class PmergeMe {
// public:
//     std::vector<int> sort(std::vector<int> &array);

// private:
//     int binarySearch(std::vector<int> const &S, int n, int maxPos) const;
//     std::vector<int> generateJacobsthal(int maxIndex) const;
//     std::vector<int> generateInsertionOrder(int numElements) const;
//     void insert(std::vector<std::pair<int, int> > const &pairs, std::vector<int> const &S, std::vector<int> &result) const;
// };

class PmergeMe
{
	private:
		std::vector<int>	_vector;

		PmergeMe(void);
		PmergeMe(PmergeMe const &cpy);
		PmergeMe	&operator=(PmergeMe const &assign);

		//vector algo
		std::vector<int>	sort(std::vector<int> &);
		// std::vector<int>    generateJacobsthal(int maxIndex) const;
		// std::vector<int>    generateInsertionOrder(int numElements) const;
		int binarySearch(std::vector<int> const &S, int n, int maxPos) const;
    std::vector<int> generateJacobsthal(int maxIndex) const;
    std::vector<int> generateInsertionOrder(int numElements) const;
    void insert(std::vector<std::pair<int, int> > const &pairs, std::vector<int> const &S, std::vector<int> &result) const;
		// void				insert(std::vector<int> const &, std::vector<int> const &, std::vector<int> &) const;
		bool				onlyDigit(const char *) const;
		// int					binarySearch(std::vector<int> const &S, int n, int maxPos) const;
		//vector algo

	public:
		PmergeMe(char **, int &);
		~PmergeMe(void);
};

# endif