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

bool    RPN::isop(char const &c) const
{
    if (c != '+' && c != '-' && c != '/' && c != '*')
        return false;
    return true;
}

void    RPN::parser(void)
{
    for(std::string::iterator it = _input.begin(); it != _input.end(); it++)
    {
        if (!isdigit(*it) && !isop(*it) && !isspace(*it))
            throw (std::runtime_error("Error: invalid input"));
    }
}

