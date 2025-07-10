#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char const *input, char const *csv) : _input(input), _csv(csv), _leap_y(false)
{
    if (!BitcoinExchange::checkFormat(input, csv))
        throw(std::runtime_error("Error: Bad format file"));
    if (!_input.is_open())
        throw(std::runtime_error("Error: Can't open file"));
    if (!_csv.is_open())
    {
        _input.close();
        throw(std::runtime_error("Error: Can't open file"));
    }
}

BitcoinExchange::~BitcoinExchange(void)
{
    this->_data.clear();
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
    _csv.close();
}

bool    BitcoinExchange::validYear(std::string const &year)
{
   _year = atoi(year.c_str());
    if (_year < 1800 || _year > 2025)
        return false;
    if (_year % 4 == 0)
    {
        if (_year % 100 == 0)
        {
            if (_year % 400 == 0)
                this->_leap_y = true;
        }
        this->_leap_y = true;
    }
    return (true);
}

bool    BitcoinExchange::validMonth(std::string const &month)
{
    _month = atoi(month.c_str());
    if (_month <= 0 || _month > 12)
        return false;
    return (true);
}

bool    BitcoinExchange::validDay(std::string const &day)
{
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    _day = atoi(day.c_str());
    if (_leap_y && _month == 2)
    {
        month[1] += 1;
        _leap_y = false;
    }
    if (_day <= 0 || _day > month[_month - 1])
        return false;
    return (true);
}

void    BitcoinExchange::checkDate(std::string const &date)
{
    std::string::const_iterator it = date.begin();
    std::size_t ymd = 0;
    std::size_t pos = 0;
    while (pos != std::string::npos)
    {
        std::size_t old_pos = pos;
        pos = date.find("-", old_pos);
        switch (ymd)
        {
            case 0:
                if (!validYear(date.substr(old_pos, pos - old_pos)))
                    throw(std::runtime_error("Error: Bad input => " + date));
                break;
            case 1:
                if (!validMonth(date.substr(old_pos, pos - old_pos)))
                    throw(std::runtime_error("Error: Bad input => " + date));
                break;
            case 2:
                if (!validDay(date.substr(old_pos, pos)))
                    throw(std::runtime_error("Error: Bad input => " + date));
                break;
        }
        if (pos != std::string::npos)
            pos += 1;
        it += pos;
        ymd++;
    }
}

void    BitcoinExchange::checkValue(std::string const &value) const
{
    std::size_t pos = value.find('.');
    if (pos == std::string::npos)
    {
        long l = strtol(value.c_str(), NULL, 10);
        if (l < 0)
            throw(std::runtime_error("Error: not a positive number"));
        if (l > 1000)
            throw(std::runtime_error("Error: too large a number"));
    }
    else
    {
        float f = strtof(value.c_str(), NULL);
        if (f < 0)
            throw(std::runtime_error("Error: not a positive number"));
        if (errno == ERANGE && f > std::numeric_limits<float>::max())
            throw(std::runtime_error("Error: too large a number"));
        if (f > 1000)
            throw(std::runtime_error("Error: too large a number"));
    }
}

int   BitcoinExchange::diff(std::string const &date, const int &begin) const
{
    std::string tmp = date;
    switch (begin)
    {
        case 0:
            return (_year - atoi(tmp.substr(0, 4).c_str()));
        case 5:
            return (_month - atoi(tmp.substr(5, 2).c_str()));
        case 8:
            return (_day - atoi(tmp.substr(8, 2).c_str()));
    }
    return (0);
}

std::map<std::string, float>::iterator	BitcoinExchange::findYear(void)
{
    std::map<std::string, float>::iterator closest = _data.begin();
    while (closest != _data.end() && diff(closest->first, 0) > 0)
        closest++;
    if (closest != _data.end() && diff(closest->first, 0) == 0)
    {
        std::cout << " [GOTOFINDMONTH] ";
        closest = findMonth(closest);
    }
    else if (closest != _data.begin() && (closest == _data.end() || diff(closest->first, 0) < 0))
        {
            closest--;
            std::cout << "[CLOSEST] " << closest->first << " ";
        }
    return closest;
}

std::map<std::string, float>::iterator	BitcoinExchange::findMonth(std::map<std::string, float>::iterator &closest)
{
    // std::map<std::string, float>::iterator new_closest = closest;
    while (closest != _data.end() && diff(closest->first, 5) > 0)
        closest++;
    if (closest != _data.end() && diff(closest->first, 5) == 0)
        closest = findDay(closest);
    else if (closest == _data.end() || diff(closest->first, 5) < 0)
        closest--;
    return closest;
}

std::map<std::string, float>::iterator	BitcoinExchange::findDay(std::map<std::string, float>::iterator closest)
{
    // std::map<std::string, float>::iterator new_closest = closest;
    while (closest != _data.end() && diff(closest->first, 8) > 0)
        closest++;
    if (closest == _data.end() || diff(closest->first, 8) < 0)
        closest--;
    return closest;
}

void    BitcoinExchange::convertValue(std::string const &value)
{
    std::map<std::string, float>::iterator closest = findYear();
    float   result = strtof(value.c_str(), NULL) * closest->second;
    std::cout << result;
}

void    BitcoinExchange::checkInput(void)
{
    for(std::string tmp; std::getline(_input, tmp, '\n');)
    {
        std::size_t   pos = tmp.find("|");
        if (tmp.substr(0, pos) != "date ")
        {
            try
            {
                checkDate(tmp.substr(0, pos));
                if (pos == std::string::npos)
                    std::cerr << "Error: no value" << std::endl;
                else
                {
                    checkValue(tmp.substr(pos + 1));
                    std::cout << tmp.substr(0, pos) << " => " << strtof(tmp.substr(pos + 1).c_str(), NULL) << " = ";
                    convertValue(tmp.substr(pos + 1));
                    std::cout << std::endl;
                }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
    }
    _input.close();
}
