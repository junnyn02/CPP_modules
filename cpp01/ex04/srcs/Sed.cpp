/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/10 14:41:44 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed( char **av, const char *name ) : _ifs( av[1] ), _ofs( name ), _old_str( av[2] ), _word( av[3] )
{
}

Sed::~Sed( void )
{
}

int	Sed::check_ifs_open( void )
{
	if (!_ofs.is_open())
	{
		std::cout << "Can't create outfile" << std::endl;
		_ifs.close();
		return (1);
	}
	return (0);
}

int	Sed::has_find( void )
{
	std::size_t	pos;
	char		c;
	
	while(_ifs.get(c))
		_line.append(1, c);
	pos = _line.find(_old_str);
	if (pos != std::string::npos)
		return (0);
	_new_line = _line;
	return (1);
}

void	Sed::replace_word( void )
{
	std::size_t	pos;
	std::size_t	i = 0;

	pos = _line.find(_old_str, i);
	while (i <= _line.length() && pos != std::string::npos)
	{
		pos = _line.find(_old_str, i);
		if (pos != std::string::npos)
		{
			_new_line.append(_line, i, pos - i);
			_new_line.append(_word);
			i = pos + _old_str.length();
		}
		else
		{
			_new_line.append(_line, i, _line.length());
			break;
		}
	}
}

void	Sed::copy_line( void )
{
	_ofs << _new_line;
}

void	Sed::close_iofs( void )
{
	_ifs.close();
	_ofs.close();
}