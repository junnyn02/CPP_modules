#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av, int &ac)
{
    for (int i = 1; i < ac; i++)
    {
        if (!onlyDigit(av[i]))
            throw(std::runtime_error("Error: unknown character"));
        long l = strtol(av[i], NULL, 10);
        if (l < 0)
            throw(std::runtime_error("Error: not a positive number"));
        if (errno == ERANGE && l < std::numeric_limits<int>::min())
            throw(std::runtime_error("Error: not a positive number"));
        if (errno == ERANGE && l > std::numeric_limits<int>::max())
            throw(std::runtime_error("Error: overflow"));
        _vector.push_back(static_cast<int>(l));
    }
    // sort(_vector);
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << "_vector[" << i << "]: " << _vector[i] << " ";
    std::cout << std::endl;
    sort(_vector);
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << "_vector[" << i << "]: " << _vector[i] << " ";
    std::cout << std::endl;
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe::PmergeMe(PmergeMe const &cpy)
{
    *this = cpy;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &assign)
{
    (void)assign;
    return *this;
}

void    PmergeMe::sort(std::vector<int> &array)
{
    int n = array.size();
    if (n <= 1)
        return ;
    std::vector<std::pair<int, int> > pairs;
    int unpaired = -1;
    
    for (int i = 0; i < n; i += 2) {
        if (i + 1 < n)
        {
            if (array[i] > array[i + 1])
                std::swap(array[i], array[i + 1]);
            pairs.push_back(std::make_pair(array[i], array[i + 1]));
        }
        else
            unpaired = array[i];
    }
    std::vector<int> larger_elts;
    for (size_t i = 0; i < pairs.size(); ++i)
        larger_elts.push_back(pairs[i].second);
    sort(larger_elts);
    std::vector<int> S = larger_elts;
    std::vector<int> smaller_elts;
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it < pairs.end(); ++it)
    {
            if (it->second == S[0])
            {
                S.insert(S.begin(), it->first);
                pairs.erase(it);
                break;
            }
    }
    for (size_t i = 0; i < pairs.size(); ++i)
        smaller_elts.push_back(pairs[i].first);
    for (size_t i = 0; i < smaller_elts.size(); ++i)
        S.push_back(smaller_elts[i]);
    if (unpaired != -1)
        S.push_back(unpaired);
    _vector = S;
}

bool    PmergeMe::onlyDigit(const char *input) const
{
    for (int i = 0; input[i] != '\0' ; i++)
    {
        if (!isdigit(input[i]) && input[i] != '-' && input[i] != '+')
            return false;
    }
    return true;
}

bool    PmergeMe::isSort()
{
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end() - 1; it++)
    {
        if (*(it + 1) < *it)
            return false;
    }
    return true;
}

