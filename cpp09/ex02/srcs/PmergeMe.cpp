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
        for (size_t j = 0; j < _vector.size(); j++)
        {
            if (l == _vector[j])
                throw(std::runtime_error("Error: Duplicate number"));
        }
        _vector.push_back(static_cast<int>(l));
    }
    std::cout << "Before:\t";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
    std::clock_t    startV = std::clock();
    size_t size = _vector.size();
    _vector = sort(_vector);
    std::clock_t    endV = std::clock();
    double  timeV = static_cast<double>(endV - startV) / CLOCKS_PER_SEC;
    std::cout << "After:\t";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector :" << timeV << " us" << std::endl;
    if (!checkSort() || size != _vector.size())
        throw(std::runtime_error("Error: not sorted"));
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

bool    PmergeMe::checkSort(void)
{
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end() - 1; it++)
    {
        int n = *it;
        for (std::vector<int>::iterator it2 = it + 1; it2 != _vector.end(); it2++)
            if (n == *it2)
                return false;
    }
    return true;
}

//algo for vector
int PmergeMe::binarySearch(std::vector<int> const &S, int n, int maxPos) const
{
    int left = 0;
    int right = std::min(maxPos, static_cast<int>(S.size()) - 1);
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (S[mid] < n)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (left);
}

std::vector<int> PmergeMe::generateJacobsthal(int maxIndex) const
{
    std::vector<int> jacobsthal;
    jacobsthal.push_back(1);
    while (jacobsthal.back() < maxIndex + 1)
    {
        int size = jacobsthal.size();
        int next = (size == 1) ? 1 : jacobsthal[size - 1] + 2 * jacobsthal[size - 2];
        jacobsthal.push_back(next);
    }
    return (jacobsthal);
}

std::vector<int> PmergeMe::generateInsertionOrder(int numElements) const
{
    std::vector<int> order;
    std::vector<int> jacobsthal = generateJacobsthal(numElements);
    std::vector<bool> inserted(numElements, false);

    for (int i = jacobsthal.size() - 1; i >= 0; --i)
    {
        int idx = jacobsthal[i] - 1;
        if (idx < numElements && !inserted[idx])
        {
            order.push_back(idx);
            inserted[idx] = true;
        }
    }
    for (int i = 0; i < numElements; i++)
    {
        if (!inserted[i])
            order.push_back(i);
    }
    return (order);
}

void PmergeMe::insert(std::vector<std::pair<int, int> > const &pairs, std::vector<int> const &, std::vector<int> &result) const
{
    std::vector<int> insertionOrder = generateInsertionOrder(pairs.size());
    for (size_t i = 0; i < insertionOrder.size(); i++)
    {
        int idx = insertionOrder[i];
        if (idx >= static_cast<int>(pairs.size()))
            continue;
        int small = pairs[idx].first;
        int big = pairs[idx].second;
        int maxPos = 0;
        for (size_t j = 0; j < result.size(); j++)
        {
            if (result[j] == big)
            {
                maxPos = j;
                break;
            }
        }
        int insertPos = binarySearch(result, small, maxPos);
        result.insert(result.begin() + insertPos, small);
    }
}

std::vector<int> PmergeMe::sort(std::vector<int> &array)
{
    int size = array.size();
    if (size <= 1)
        return array;
    std::vector<std::pair<int, int> > pairs;
    int unpaired = -1;
    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            int a = array[i];
            int b = array[i + 1];
            if (a > b)
                std::swap(a, b);
            pairs.push_back(std::make_pair(a, b));
        }
        else
            unpaired = array[i];
    }
    std::vector<int> bigs;
    for (size_t i = 0; i < pairs.size(); i++)
        bigs.push_back(pairs[i].second);
    std::vector<int> S = sort(bigs);
    std::vector<int> result = S;
    if (!pairs.empty())
        S.insert(S.begin(), pairs[0].first);
    if (!pairs.empty())
        insert(pairs, S, result);
    if (unpaired != -1)
    {
        int pos = binarySearch(result, unpaired, result.size());
        result.insert(result.begin() + pos, unpaired);
    }
    return (result);
}
//algo for vector

// //algo for list
// std::list<int> PmergeMe::generateJacobsthalList(int maxIndex) const
// {
//     std::list<int> jacobsthal;
//     jacobsthal.push_back(1);
//     while (jacobsthal.back() < maxIndex + 1)
//     {
//         int size = jacobsthal.size();
//         int next;
//         if (size == 1)
//             next = 1;
//         else
//         {
//             std::list<int>::iterator it = jacobsthal.end();
//             --it;
//             int prev1 = *it;
//             --it;
//             int prev2 = *it;
//             next = prev1 + 2 * prev2;
//         }
//         jacobsthal.push_back(next);
//     }
//     return (jacobsthal);
// }

// std::list<int> PmergeMe::generateInsertionOrderList(int numElements) const
// {
//     std::list<int> order;
//     std::list<int> jacobsthal = generateJacobsthalList(numElements);
//     std::list<bool> inserted(numElements, false);

//     if (!jacobsthal.empty())
//     {
//         std::list<int>::iterator it = --jacobsthal.end();
//         while (1)
//         {
//             int idx = *it - 1;
//             if (idx < numElements && !inserted[idx])
//             {
//                 order.push_back(idx);
//                 // inserted[idx] = true;
//             }
//             if (it == jacobsthal.begin())
//                 break;
//             --it;
//         }
//     }
//     return (order);
//     // for (int i = jacobsthal.size() - 1; i >= 0; --i)
//     // {
//     //     int idx = jacobsthal[i] - 1;
//     //     if (idx < numElements && !inserted[idx])
//     //     {
//     //         order.push_back(idx);
//     //         inserted[idx] = true;
//     //     }
//     // }
//     // for (int i = 0; i < numElements; i++)
//     // {
//     //     if (!inserted[i])
//     //         order.push_back(i);
//     // }
//     // return (order);
// }

// int PmergeMe::binarySearch(std::list<int> const &S, int n, int maxPos) const
// {
//     int left = 0;
//     int right = std::min(maxPos, static_cast<int>(S.size()) - 1);
//     while (left <= right)
//     {
//         int mid = left + (right - left) / 2;
//         if (S[mid] < n)
//             left = mid + 1;
//         else
//             right = mid - 1;
//     }
//     return (left);
// }

// void PmergeMe::insert(std::list<std::pair<int, int> > &pairs, std::list<int> const &, std::list<int> &result) const
// {
//     std::list<int> insertionOrder = generateInsertionOrderList(pairs.size());
//     for (size_t i = 0; i < insertionOrder.size(); ++i)
//     for (std::list<int>::iterator it = insertionOrder.begin(); it != insertionOrder.end(); it++)
//     {
//         int idx = *it;
//         if (idx >= static_cast<int>(pairs.size()))
//             continue;
//         std::list<std::pair<int, int> >::iterator it_pair = pairs.begin();
//         for (int i = 0; i < idx && it_pair != pairs.end(); ++i, ++it_pair){
//         }
//         int small = it_pair->first;
//         int big = it_pair->second;
//         int maxPos = 0;
//         for (std::list<int>::iterator it = result.begin(); it != result.end(); it++)
//         {
//             if (*it == big)
//             {
//                 maxPos = *it;
//                 break;
//             }
//         }
//         int insertPos = binarySearch(result, small, maxPos);
//         result.insert(result.begin() + insertPos, small);
//     }
// }

// std::list<int>  PmergeMe::sort(std::list<int> &array)
// {
//     int size = array.size();
//     if (size <= 1)
//         return array;
//     std::list<std::pair<int, int> > pairs;
//     int unpaired = -1;
//     for (std::list<int>::iterator it = array.begin(); it != array.end(); std::advance(it, 2))
//     {
//         std::list<int>::iterator next = it;
//         ++next;
//         if (next != array.end())
//         {
//             int a = *it;
//             int b = *next;
//             if (a > b)
//                 std::swap(a, b);
//             pairs.push_back(std::make_pair(a, b));
//         }
//         else
//             unpaired = *it;
//     }
//     std::list<int> bigs;
//     for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
//         bigs.push_back(it->second);
//     std::list<int> S = sort(bigs);
//     std::list<int> result = S;
//     if (!pairs.empty())
//         S.insert(S.begin(), pairs[0].first);
//     if (!pairs.empty())
//         insert(pairs, S, result);
//     if (unpaired != -1)
//     {
//         int pos = binarySearch(result, unpaired, result.size());
//         result.insert(result.begin() + pos, unpaired);
//     }
//     return (result);
// }
//algo for list

bool    PmergeMe::onlyDigit(const char *input) const
{
    for (int i = 0; input[i] != '\0' ; i++)
    {
        if (!isdigit(input[i]) && input[i] != '-' && input[i] != '+')
            return false;
    }
    return true;
}
