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
        _list.push_back(static_cast<int>(l));
    }
    std::cout << "Before:\t";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
    std::clock_t    startV = std::clock();
    size_t size = _vector.size();
     std::clock_t    startL = std::clock();
    size_t sizeL = _vector.size();
    _vector = sort(_vector);
    std::clock_t    endV = std::clock();
    _list = sort(_list);
     std::clock_t    endL = std::clock();
    double  timeV = static_cast<double>(endV - startV) / CLOCKS_PER_SEC;
    double  timeL = static_cast<double>(endL - startL) / CLOCKS_PER_SEC;
    std::cout << "After:\t";
    // for (size_t i = 0; i < _vector.size(); i++)
    //     std::cout << _vector[i] << " ";
    for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector :" << timeV << " us" << std::endl;
    std::cout << "Time to process a range of " << _list.size() << " elements with std::vector :" << timeL << " us" << std::endl;
    if (!checkSort() || size != _vector.size() || sizeL != _list.size())
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
    // for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end() - 1; it++)
    // {
    //     int n = *it;
    //     for (std::vector<int>::iterator it2 = it + 1; it2 != _vector.end(); it2++)
    //         if (n == *it2)
    //             return false;
    // }
    for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
    {
        int n = *it;
        for (std::list<int>::iterator it2 = it; it2 != _list.end(); it2++)
        {
            ++it2;
            if (it2 == _list.end())
                break;
            if (n == *it2)
                return false;
        }
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
    jacobsthal.push_back(0);
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
    std::vector<int> pend;
    for (int i = 3; i <= numElements; ++i)
        pend.push_back(i);
    std::vector<int> jacobsthal = generateJacobsthal(numElements);
    int level = 2;
    int i = -1;
    while (++i < numElements)
    {
        int current = jacobsthal[level + 1];
        int prev = jacobsthal[level];
        int count = current - prev;
        if (count > (int)pend.size())
            break;
        int start = count - 1;
        for (int i = 0; i < count; ++i)
        {
            order.push_back(pend[start - i]);
            pend.erase(pend.begin() + start - i);
        }
        ++level;
    }
    for (int i = 0; i < (int)pend.size(); ++i)
        order.push_back(pend[i]);
    return (order);
}

void PmergeMe::insert(std::vector<std::pair<int, int> > const &pairs, std::vector<int> &S) const
{
    std::vector<int> insertionOrder = generateInsertionOrder(S.size());
    std::vector<int> tmp = S;
    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        int idx = insertionOrder[i];
        if (idx > static_cast<int>(tmp.size()))
            continue;
        int small = 0;
        for (size_t i = 0; i < pairs.size(); ++i)
        {
            if (tmp[idx - 1] == pairs[i].second)
            {
                small = pairs[i].first;
                break;
            }
        }
        int insertPos = binarySearch(S, small, tmp[idx - 1]);
        S.insert(S.begin() + insertPos, small);
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
    for (size_t i = 0; i < pairs.size(); ++i)       
        bigs.push_back(pairs[i].second);
    std::vector<int> S = sort(bigs);
    if (!pairs.empty())
    {
        for (size_t i = 0; i < pairs.size(); ++i)
        {
            if (pairs[i].second == S[0])
            {
                S.insert(S.begin(), pairs[i].first);
                break;
            }
        }
    }
    if (!pairs.empty())
        insert(pairs, S);
    if (unpaired != -1)
    {
        int pos = binarySearch(S, unpaired, S.size());
        S.insert(S.begin() + pos, unpaired);
    }
    return (S);
}
//algo for vector

//algo for list
int PmergeMe::binarySearch(std::list<int> const &S, int n, int maxPos) const
{
    int left = 0;
    int right = std::min(maxPos, static_cast<int>(S.size()) - 1);
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        std::list<int>::const_iterator it = S.begin();
        std::advance(it, mid);
        if (*it < n)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (left);
}

std::list<int> PmergeMe::generateJacobsthalList(int maxIndex) const
{
    std::list<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    while (jacobsthal.back() < maxIndex + 1)
    {
        int size = jacobsthal.size();
        std::list<int>::reverse_iterator it = jacobsthal.rbegin();
        std::list<int>::reverse_iterator it2 = it++;
        int next = (size == 1) ? 1 : *it2 + (2 * *it);
        jacobsthal.push_back(next);
    }
    return (jacobsthal);
}

std::list<int> PmergeMe::generateInsertionOrderList(int numElements) const
{
    std::list<int> order;
    std::list<int> pend;
    for (int i = 3; i <= numElements; ++i)
        pend.push_back(i);
    std::list<int> jacobsthal = generateJacobsthalList(numElements);
    int level = 2;
    int i = -1;
    while (++i < numElements)
    {
        std::list<int>::iterator it = jacobsthal.begin();
        std::advance(it, level);
        std::list<int>::iterator it2 = it++;
        int current = *it;
        int prev = *it2;
        int count = current - prev;
        if (count > (int)pend.size())
            break;
        int start = count - 1;
        for (int i = 0; i < count; ++i)
        {
            std::list<int>::iterator idx = pend.begin();
            std::advance(idx, start - i);
            order.push_back(*idx);
            pend.erase(idx);
        }
        ++level;
    }
    for (std::list<int>::iterator nb = pend.begin(); nb != pend.end(); ++nb)
        order.push_back(*nb);
    return (order);
}

void PmergeMe::insert(std::list<std::pair<int, int> > const &pairs, std::list<int> &S) const
{
    std::list<int> insertionOrder = generateInsertionOrderList(S.size());
    std::list<int> tmp = S;
    for (std::list<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
        std::cout << "[" << it->first << ", " << it->second << "], ";
    std::cout << std::endl;
    std::cout << "S: ";
    for (std::list<int>::iterator it = S.begin(); it != S.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "Insertion Order: ";
    for (std::list<int>::iterator it = insertionOrder.begin(); it != insertionOrder.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    for (std::list<int>::iterator it = insertionOrder.begin(); it != insertionOrder.end(); ++it)
    {
        int idx = *it;
        if (*it > static_cast<int>(tmp.size()))
            continue;
        int small = 0;
        std::list<int>::iterator pos = tmp.begin();
        std::advance(pos, idx - 1);
        for (std::list<std::pair<int, int> >::const_iterator it2 = pairs.begin(); it2 != pairs.end(); ++it2)
        {
            if (it2->second == *pos)
            {
                small = it2->first;
                break;
            }
        }
        std::cout << "idx to insert = " << idx << "=" << small;
        int insertPos = binarySearch(S, small, *pos);
        std::list<int>::iterator start = S.begin();
        std::advance(start, insertPos);
        std::cout << " at " << *start << std::endl;
        S.insert(start, small);
        std::cout << "after S: ";
        for (std::list<int>::iterator it = S.begin(); it != S.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
}

std::list<int> PmergeMe::sort(std::list<int> &array)
{
    int size = array.size();
    if (size <= 1)
        return array;
    std::list<std::pair<int, int> > pairs;
    int unpaired = -1;
    for (std::list<int>::iterator it = array.begin(); it != array.end(); std::advance(it, 1))
    {
        std::list<int>::iterator it2 = it++;
        if (it != array.end())
        {
            if (*it2 > *it)
                std::swap(*it, *it2);
            pairs.push_back(std::make_pair(*it2, *it));
        }
        else
            unpaired = *it;
        if (it == array.end())
            break;
    }
    std::list<int> bigs;
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        bigs.push_back(it->second);
    }
    std::list<int> S = sort(bigs);
    std::cout << "before pairs: ";
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        std::cout << "[" << it->first << ", " << it->second << "], ";
    std::cout << std::endl;
    if (!pairs.empty())
    {
        for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        {
            if (it->second == *(S.begin()))
            {
                S.insert(S.begin(), it->first);
                break;
            }
        }
    }
    std::cout << "before S: ";
    for (std::list<int>::iterator it = S.begin(); it != S.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    if (!pairs.empty())
        insert(pairs, S);
    if (unpaired != -1)
    {
        int pos = binarySearch(S, unpaired, S.size());
        std::list<int>::iterator it = S.begin();
        std::advance(it, pos);
        S.insert(it, unpaired);
    }
    return (S);
}
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
