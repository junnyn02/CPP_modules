#include "RPN.hpp"

RPN::RPN(std::string const &input) : _input(input), _result(0)
{
}

RPN::~RPN(void)
{
}

RPN::RPN(RPN const &cpy)
{
    *this = cpy;
}

RPN &RPN::operator=(RPN const &assign)
{
    (void)assign;
    return *this;
}

bool    RPN::isop(std::string::iterator &c) const
{
    if ((*c == '+' && isdigit(*(c + 1 ))) || (*c == '-' && isdigit(*(c + 1 ))))
        return false;
    else if (*c != '+' && *c != '-' && *c != '/' && *c != '*')
        return false;
    return true;
}

bool    RPN::isnumber(std::string::iterator &c) const
{
    if ((*c == '+' && isdigit(*(c + 1))) || (*c == '-' && isdigit(*(c + 1))))
        return true;
    else if (isdigit(*c))
        return true;
    return false;
}

bool RPN::add(int const &a, int const &b)
{
    if (a > 0 && b > 0 && a > std::numeric_limits<int>::max() - b)
        return false;
    if (a < 0 && b < 0 && a < std::numeric_limits<int>::min() - b)
        return false;
    _result = b + a;
    return true;
}

bool RPN::substract(int const &a, int const &b)
{
    if (a > 0 && b < 0 && a > std::numeric_limits<int>::max() + b)
        return false;
    if (a < 0 && b > 0 && a < std::numeric_limits<int>::min() + b)
        return false;
    _result = b - a;
    return true;
}

bool RPN::multiply(int const &a, int const &b)
{
    if (a > 0 && b > 0 && a > std::numeric_limits<int>::max() / b)
        return false;
    if (a < 0 && b < 0 && a < std::numeric_limits<int>::max() / b)
        return false;
    if (a > 0 && b < 0 && b < std::numeric_limits<int>::min() / a)
        return false;
    if (a < 0 && b > 0 && a < std::numeric_limits<int>::min() / b)
        return false;
    _result = b * a;
    return true;
}

void    RPN::calcul(char const &c)
{
    if (_stack.size() <= 1)
        throw (std::runtime_error("Error: invalid format"));
    int a = _stack.top();
    _stack.pop();
    int b = _stack.top();
    _stack.pop();
    if (c == '+')
    {
        if (!add(a, b))
           throw("Error: Overflow");
    }
    else if (c == '-')
    {
        if (!substract(a, b))
           throw("Error: Overflow");
    }
    else if (c == '*')
    {
        if (!multiply(a, b))
           throw("Error: Overflow");
    }
    else if (c == '/')
    {
        if (a == 0)
            throw(std::runtime_error("Error: Division by zero"));
        if (b == std::numeric_limits<int>::min() && a == -1)
            throw(std::runtime_error("Error: Overflow"));
        _result = b / a;
    }
    _stack.push(_result);
    _result = 0;
}

void    RPN::pushNumber(std::string::iterator &it)
{
    std::string::iterator tmp = it;
    if (*it == '-' || *it == '+')
        it++;
    while (it != _input.end() && !isspace(*it))
    {
        if (!isdigit(*it))
            throw(std::runtime_error("Error: not a number"));
        it++;
    }
    long l = strtol(std::string(tmp, it).c_str(), NULL, 10);
    if (errno == ERANGE && l < std::numeric_limits<int>::min())
        throw(std::runtime_error("Error: not a positive number"));
    if (errno == ERANGE && l > std::numeric_limits<int>::max())
        throw(std::runtime_error("Error: too large a number"));
    _stack.push(l);
}

void    RPN::parser(void)
{
    for(std::string::iterator it = _input.begin(); it != _input.end(); it++)
    {
        while (isspace(*it))
            it++;
        if (isop(it))
            calcul(*it);
        else if (isnumber(it))
            pushNumber(it);
        else
            throw (std::runtime_error("Error: invalid input"));
        if (it == _input.end())
            break;
    }
    if (_stack.size() != 1)
        throw (std::runtime_error("Error: invalid input"));
    std::cout << _stack.top() << std::endl;
    _stack.pop();
}
