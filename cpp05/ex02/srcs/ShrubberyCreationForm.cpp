/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/24 14:16:15 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", "NoTarget", 145, 137)
{
	if (MSG)
		std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("ShrubberyCreationForm", target, 145, 137)
{
	if (MSG)
		std::cout << "ShrubberyCreationForm name constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (MSG)
		std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & cpy) : AForm(cpy)
{
	if (MSG)
		std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = cpy;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & assign)
{
	if (MSG)
		std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	(void)assign;
	return *this;
}

void	ShrubberyCreationForm::do_exec(void) const
{
	std::string		file_name;
	
	file_name = this->getTarget();
	file_name.append("_shrubbery");
	std::ofstream 	ofs(file_name.c_str());
	if (!ofs.is_open())
	{
		std::cerr << "Can't create outfile" << std::endl;
		return ;
	}
	ofs <<"          &&& &&  & &&" << std::endl;
	ofs <<"      && &\\/&\\|& ()|/ @, &&" << std::endl;
	ofs <<"      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	ofs <<"   &() &\\/&|()|/&\\/ '%_ & ()" << std::endl; 
	ofs <<"  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	ofs <<"&&   && & &| &| /& & % ()& /&&" << std::endl;
	ofs <<" ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	ofs <<"     &&     \\|||" << std::endl;
	ofs <<"             |||" << std::endl;
	ofs <<"             |||" << std::endl;
	ofs <<"             |||" << std::endl;
	ofs <<"       , -=-~  .-^- _" << std::endl;
	ofs.close();
}
