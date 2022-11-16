/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:57:07 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/15 23:06:25 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include <fstream>

# define RED1 "\033[38;5;196m"
# define RESET "\033[0m"

ShrubberyCreationForm::ShrubberyCreationForm(void):
Form("ShrubberyCreationForm", 145, 137),
_target("")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name):
Form(name, 145, 137),
_target(name)
{
	std::cout << "ShrubberyCreationForm '" << name << "' constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &ref): Form(ref)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	if (this != &ref)
		*this = ref;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &ref)
{
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this != &ref)
	{
		_target = ref._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned())
		throw Form::NotSignedException();
	if (executor.getGrade() > this->getGradeExecReq())
		throw Form::GradeTooLowException();
	std::cout << "ShrubberyCreationForm '" << this->getName() << "' executed by '" << executor.getName() << "'" << std::endl;
	std::ofstream file;
	file.open((this->_target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
	if (!file.good())
	{
		std::cout << RED1 << "Error opening file '" << this->_target << "_shrubbery'" << RESET << std::endl;
		file.close();
		return ;
	}
    file << "                             *    .//                           " << std::endl;
    file << "                    .,*/****//*, (.%##(//(*(/(/*,               " << std::endl;
    file << "                  *#/%*,///*(/.*((/((((%(%%(&%%%@#((/*          " << std::endl;
    file << "          *,*(*/(*((/,(**#(/%####(((/#&@#%*%@/#&/#%#%(/         " << std::endl;
    file << "           //*(*(((/(##(#####&#(&/#(((%%%%*/&%%%&&&%&%(         " << std::endl;
    file << "     ,,( *//,#/#(#%.((((/%%##@%%%&%&#&#(#/#&%(#(&%#(#%(##       " << std::endl;
    file << "    ,./#,/(*/((#((*(/#&(%@&&%&&@@@@#/%&%&%&&#&#@&&%%/(/ %(*/,   " << std::endl;
    file << "    /**/#(//(//*,/%/#&(%@%&&&&&@@&%&&%#&%#.@%#&&#@@&%((&(#/((   " << std::endl;
    file << "      /((@%##&(##%(&##%@%/(&@@@@&@@*@(%#/#((&&#&/#@&%@&(%(&%*., " << std::endl;
    file << "  ,(//*//*#/(/,/(&#%@#%@%(&@#&@@@&%&&@&&%%&%#%%(##&&&&#&@&&%*#(," << std::endl;
    file << "     /*##%(/((*/#&%%##&#@&(&&%@@%@%@&#&&%#&/&#(%#%&%##%&&&%&#,  " << std::endl;
    file << "     *,,/*((#%%#%##%%@%& %#@&(@&@@@@@@&@@(##(&##&/%%&#%(#&&&/%, " << std::endl;
    file << "    ##/.#(/*#((%(#(%%%%##&/%*&@@@@@&%&%(@@#&(@&&&%&&(&%(%%&&.*/ " << std::endl;
    file << "  ,#,.*(%/%(%#%(%&%@/@@&&%@&&&@&&&@@%/&@%@&%*#%&(@*.@#&*( %/    " << std::endl;
    file << "   *(*(/#(#/##/#%%%&&&&/%&&%@&(&&@&&&&%@@&@&,.##&(%@&&%,#/      " << std::endl;
    file << "   ,#//%(#/.,%#%,& (% .#&&&#%&%&@@&&&@%@@&%#/%/#(.(%&%%*        " << std::endl;
    file << "      .,(    ##*    ..%&%%(*%%@%@@#&#@%&*( ,*/.(                " << std::endl;
    file << "              .          .##/#@#%(&/%%%( ,..                    " << std::endl;
    file << "                              (/#% ( #                          " << std::endl;
    file << "                               ((%                              " << std::endl;
    file << "                               /#%                              " << std::endl;
    file << "                              ,*&%                              " << std::endl;
    file << "                            .**//(%.                            " << std::endl;
    file << "                                                                " << std::endl;
	file.close();
	std::cout << "'" << executor.getName() << "' executed form '" << this->getName() << "'" << std::endl;
}