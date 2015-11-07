/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 02:27:05 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/07 00:04:35 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.class.hpp"

Logger::Logger( std::string filename ) : _filename(filename) {
	this->_logCmd[0].ptrFunc = &Logger::_logToConsole;
	this->_logCmd[1].ptrFunc = &Logger::_logToFile;;
	this->_logCmd[0].cmd = "logToConsole";
	this->_logCmd[1].cmd = "logToFile";
	return ;
}

Logger::~Logger( void ) {
	return ;
}

void			Logger::log( std::string const & dest, std::string const & message) {
	for (int i = 0; i < 2; i++) {
		if (strcmp(dest.c_str(), this->_logCmd[i].cmd.c_str()) == 0) {
			(this->*_logCmd[i].ptrFunc)(this->_makeLogEntry(message));
			return ;
		}
	}
	std::cout << "Logger Error: Bad destination." << std::endl;
}

void			Logger::_logToFile( std::string str ) const {
	std::ofstream	ofs;

	ofs.open(this->_filename.c_str(), std::ios_base::app);
	if (ofs) {
		ofs << str;;
		ofs.close();
	} else {std::cout << "Logger Error: Can't log on this file." << std::endl; }
}

void			Logger::_logToConsole( std::string str ) const {
	std::cout << str;
	return ;
}

std::string		Logger::_makeLogEntry( std::string str ) const {
	std::stringstream	newString;
	newString << time(NULL) << " [ " << str << " ] " << std::endl;
	return (newString.str());
}
