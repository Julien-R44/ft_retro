/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 02:27:08 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/01 04:09:53 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>
# include <fstream>
# include <cstring>
# include <ctime>
# include <sstream>

class Logger {

	struct	s_log_cmd
	{
		std::string	cmd;
		void		(Logger::*ptrFunc)( std::string str ) const;
	};
	typedef struct s_log_cmd t_log_cmd;

public:
	Logger( std::string filename );
	~Logger();

	void		log( std::string const & dest, std::string const & message );

private:
	void		_logToFile( std::string str ) const;
	void		_logToConsole(std::string str ) const;
	std::string	_makeLogEntry( std::string str ) const;


	std::string		_filename;
	t_log_cmd		_logCmd[2];
};


#endif
