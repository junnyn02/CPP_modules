# include <iostream>
# include <algorithm>
# include <stdexcept>
# include <limits>
# include <cerrno>
# include <vector>
# include <list>
# include <ctime>

std::vector<int> generateJacobsthal(int maxIndex)
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

std::vector<int> generateInsertionOrderFromJacobsthal(int numElements)
{
    std::vector<int> order;
    std::vector<int> pend;
    for (int i = 3; i < numElements; ++i)
        pend.push_back(i);
    for (int i = 0; i < (int)pend.size(); ++i)
    {
        std::cout << pend[i] << " ";
    }
    std::cout << std::endl;
    // Generate Jacobsthal sequence up to numElements
    std::vector<int> jacobsthal = generateJacobsthal(numElements);
    for (int i = 0; i < (int)jacobsthal.size(); ++i)
    {
        std::cout << jacobsthal[i] << " ";
    }
    std::cout << std::endl;
    // Start from level 2 (i.e., J(3))
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
    return order;
}

int main()
{
    int numElements = 25;
    std::vector<int> order = generateInsertionOrderFromJacobsthal(numElements);

    std::cout << "Insertion order: ";
    for (int i = 0; i < (int)order.size(); ++i)
    {
        std::cout << order[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}