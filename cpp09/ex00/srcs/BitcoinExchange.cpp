#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char const *input, char const *csv) : _input(input), _csv(csv)
{
    if (!BitcoinExchange::checkFormat(input, csv))
        throw(std::runtime_error("Error: Bad format file"));
    // if (!_input.is_open())
    //     throw(std::runtime_error("Error: Can't open file"));
    if (!_csv.is_open())
    {
        _input.close();
        throw(std::runtime_error("Error: Can't open file"));
    }
}

BitcoinExchange::~BitcoinExchange(void)
{
    // _input.close();
    // _csv.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy)
{
    *this = cpy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &assign)
{
    (void)assign;
    return *this;
}

bool    BitcoinExchange::checkFormat(std::string const &input, std::string const &csv)
{
    if (input.compare(input.size() - 4, 4, ".txt") != 0)
        return false;
    if (csv.compare(csv.size() - 4, 4, ".csv") != 0)
        return false;
    return true;
}

void    BitcoinExchange::fillDB(void)
{
    for(std::string tmp; std::getline(_csv, tmp, '\n');)
    {
        std::size_t   pos = tmp.find(",");
        if (tmp.substr(0, pos) != "date")
            _data.insert(std::pair<std::string, float>(tmp.substr(0, pos), strtof(tmp.substr(pos + 1).c_str(), NULL)));
    }
    for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++)
    {
        std::cout << it->first << "=" << it->second << std::endl; // a supp
    }
    _csv.close();
}

void    BitcoinExchange::checkInput(void)
{
    for(std::string tmp; std::getline(_input, tmp, '\n');)
    {
        std::size_t   pos = tmp.find("|");
        if (tmp.substr(0, pos) != "date")
            _data.insert(std::pair<std::string, float>(tmp.substr(0, pos), strtof(tmp.substr(pos + 1).c_str(), NULL)));
    }
    for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++)
    {
        std::cout << it->first << "=" << it->second << std::endl; // a supp
    }
    _csv.close();
}
