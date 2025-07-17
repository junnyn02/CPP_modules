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
    std::clock_t    start = std::clock();
    _vector = sort(_vector);
    std::clock_t    end = std::clock();
    double  time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "After:\t";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector :" << time << " us" << std::endl;
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

// int    PmergeMe::binarySearch(std::vector<int> const &S, int n, int maxPos) const
// {
//     int left = 0;
//     int right = std::min(maxPos, (int)S.size() - 1);
//     while(left <= right)
//     {
//         int mid = left + (right - left) / 2;
//         if (S[mid] < n)
//             left = mid + 1;
//         else
//             right = mid -1;
//     }
//     return (left);
// }

// std::vector<int>    PmergeMe::generateJacobsthal(int maxIndex) const
// {
//     std::vector<int> jacobsthal;
//     jacobsthal.push_back(0);
//     jacobsthal.push_back(1);
    
//     int next = 1;
//     while (next <= maxIndex) {
//         next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
//         jacobsthal.push_back(next);
//     }
//     return jacobsthal;
// }
    
// // std::vector<int>    PmergeMe::generateInsertionOrder(int numElements) const
// // {
// //     std::vector<int> order;
// //     std::vector<int> jacobsthal = generateJacobsthal(numElements);
// //     for (size_t i = 2; i < jacobsthal.size() && jacobsthal[i] - 2 <= numElements; i++)
// //     {
// //         int start = jacobsthal[i];
// //         int end = jacobsthal[i - 1] + 1;
// //         for (int j = start; j >= end; j--)
// //         {
// //             if (j - 2 <= numElements)
// //                 order.push_back(j - 2);
// //         }
// //     }
// //     return (order);
// // }

// std::vector<int> PmergeMe::generateInsertionOrder(int numElements) const {
//     std::vector<int> order;
//     std::vector<int> jacobsthal;

//     jacobsthal.push_back(1);
//     while (jacobsthal.back() < numElements + 1) {
//         int size = jacobsthal.size();
//         int next = jacobsthal[size - 1];
//         if (size == 1)
//             next = 1;
//         else
//             next = jacobsthal[size - 1] + 2 * jacobsthal[size - 2];
//         jacobsthal.push_back(next);
//     }

//     std::vector<bool> inserted(numElements, false);

//     // 1. Insérer dans l’ordre inverse Jacobsthal
//     for (int i = jacobsthal.size() - 1; i >= 0; --i) {
//         int idx = jacobsthal[i] - 1; // -1 car index de tableau
//         if (idx < numElements && !inserted[idx]) {
//             order.push_back(idx);
//             inserted[idx] = true;
//         }
//     }

//     // 2. Compléter avec les indices manquants
//     for (int i = 0; i < numElements; ++i) {
//         if (!inserted[i]) {
//             order.push_back(i);
//             inserted[i] = true;
//         }
//     }

//     return order;
// }

// void PmergeMe::insert(std::vector<int> const &smaller_elts, std::vector<int> const &big_elts, std::vector<int> &S) const {
//     std::vector<std::pair<int, int> > pairs;

//     for (size_t i = 0; i < smaller_elts.size(); ++i)
//         pairs.push_back(std::make_pair(smaller_elts[i], big_elts[i]));

//     // Le premier élément de smaller_elts a déjà été inséré
//     std::vector<std::pair<int, int> > remainingPairs(pairs.begin() + 1, pairs.end());

//     std::vector<int> insertionOrder = generateInsertionOrder(remainingPairs.size());

//     for (size_t i = 0; i < insertionOrder.size(); ++i) {
//         int idx = insertionOrder[i];
//         if (idx >= static_cast<int>(remainingPairs.size()))
//             continue;

//         int small = remainingPairs[idx].first;
//         int big = remainingPairs[idx].second;

//         // Chercher où se trouve `big` dans S
//         int maxPos = 0;
//         for (size_t j = 0; j < S.size(); ++j) {
//             if (S[j] == big) {
//                 maxPos = j;
//                 break;
//             }
//         }

//         int insertPos = binarySearch(S, small, maxPos);
//         S.insert(S.begin() + insertPos, small);
//     }
// }


// // void    PmergeMe::insert(std::vector<int> const &smaller_elts, std::vector<int> const &big_elts, std::vector<int> &S) const
// // {
// //     std::vector<int> remainingSmall;
// //     for (size_t i = 1; i < smaller_elts.size(); i++)
// //         remainingSmall.push_back(smaller_elts[i]);
// //     std::vector<int> insertionOrder = generateInsertionOrder(remainingSmall.size());
// //     for (size_t i = 0; i < insertionOrder.size(); i++)
// //     {
// //         int idx = insertionOrder[i];
// //         if (idx < static_cast<int>(remainingSmall.size()))
// //         {
// //             int maxPos = 0;
// //             for (size_t j = 0; j < S.size(); j++) 
// //             {
// //                 if (S[j] == big_elts[idx + 1])
// //                 {
// //                     maxPos = j;
// //                     break;
// //                 }
// //             }
// //             int insertPos = binarySearch(S, remainingSmall[idx], maxPos);
// //             S.insert(S.begin() + insertPos, remainingSmall[idx]);
// //         }
// //     }
// // }

// std::vector<int>    PmergeMe::sort(std::vector<int> &array)
// {
//     int n = array.size();
//     if (n <= 1)
//         return array;
//     std::vector<std::pair<int, int> > pairs;
//     int unpaired = -1;
//     for (int i = 0; i < n; i += 2) {
//         if (i + 1 < n)
//         {
//             if (array[i] > array[i + 1])
//                 std::swap(array[i], array[i + 1]);
//             pairs.push_back(std::make_pair(array[i], array[i + 1]));
//         }
//         else
//             unpaired = array[i];
//     }
//     std::vector<int> big_elts;
//     std::vector<int> smaller_elts;
//     for (size_t i = 0; i < pairs.size(); i++)
//     {
//         big_elts.push_back(pairs[i].second);
//         smaller_elts.push_back(pairs[i].first);
//     }
//     std::vector<int> S = sort(big_elts);
//     if (!smaller_elts.empty())
//         S.insert(S.begin(), smaller_elts[0]);
//     if (smaller_elts.size() > 1)
//        insert(smaller_elts, big_elts, S);
//     if (unpaired != -1)
//     {
//         int index = binarySearch(S, unpaired, S.size());
//         S.insert(S.begin() + index, unpaired);
//     }
//     return (S);
// }

int PmergeMe::binarySearch(std::vector<int> const &S, int n, int maxPos) const {
    int left = 0;
    int right = std::min(maxPos, static_cast<int>(S.size()) - 1);
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (S[mid] < n)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

std::vector<int> PmergeMe::generateJacobsthal(int maxIndex) const {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(1);
    while (jacobsthal.back() < maxIndex + 1) {
        int size = jacobsthal.size();
        int next = (size == 1) ? 1 : jacobsthal[size - 1] + 2 * jacobsthal[size - 2];
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

std::vector<int> PmergeMe::generateInsertionOrder(int numElements) const {
    std::vector<int> order;
    std::vector<int> jacobsthal = generateJacobsthal(numElements);
    std::vector<bool> inserted(numElements, false);

    for (int i = jacobsthal.size() - 1; i >= 0; --i) {
        int idx = jacobsthal[i] - 1;
        if (idx < numElements && !inserted[idx]) {
            order.push_back(idx);
            inserted[idx] = true;
        }
    }

    for (int i = 0; i < numElements; ++i) {
        if (!inserted[i]) {
            order.push_back(i);
        }
    }

    return order;
}

void PmergeMe::insert(std::vector<std::pair<int, int> > const &pairs, std::vector<int> const &, std::vector<int> &result) const {
    std::vector<std::pair<int, int> > remainingPairs = pairs; // ← ici la correction

    std::vector<int> insertionOrder = generateInsertionOrder(remainingPairs.size());

    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        int idx = insertionOrder[i];
        if (idx >= static_cast<int>(remainingPairs.size()))
            continue;

        int small = remainingPairs[idx].first;
        int big = remainingPairs[idx].second;

        int maxPos = 0;
        for (size_t j = 0; j < result.size(); ++j) {
            if (result[j] == big) {
                maxPos = j;
                break;
            }
        }

        int insertPos = binarySearch(result, small, maxPos);
        result.insert(result.begin() + insertPos, small);
    }
}


std::vector<int> PmergeMe::sort(std::vector<int> &array) {
    int n = array.size();
    if (n <= 1)
        return array;

    std::vector<std::pair<int, int> > pairs;
    int unpaired = -1;

    for (int i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            int a = array[i], b = array[i + 1];
            if (a > b)
                std::swap(a, b);
            pairs.push_back(std::make_pair(a, b));
        } else {
            unpaired = array[i];
        }
    }

    std::vector<int> bigs;
    for (size_t i = 0; i < pairs.size(); ++i)
        bigs.push_back(pairs[i].second);

    std::vector<int> S = sort(bigs); // Recursive sort on bigs

    std::vector<int> result = S;

    // ⛔ ne pas insérer manuellement pairs[0].first
    // ✅ insérer tous les petits via insert()
     if (!pairs.empty())
        S.insert(S.begin(), pairs[0].first);
    if (!pairs.empty())
        insert(pairs, S, result);

    if (unpaired != -1) {
        int pos = binarySearch(result, unpaired, result.size());
        result.insert(result.begin() + pos, unpaired);
    }

    return result;
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

