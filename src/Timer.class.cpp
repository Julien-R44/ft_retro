/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timer.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 23:27:38 by jripoute          #+#    #+#             */
/*   Updated: 2015/11/08 00:37:47 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Timer.class.hpp"

Timer::Timer(void) {
	_startTime = time(NULL);
}

Timer::Timer(Timer const & src) {
	*this = src;
}

Timer::~Timer(void) {
}

Timer & 	Timer::operator=(Timer const & src) {
	return *this;
}

double 		Timer::getElapsedTime( void ) const {
	return (difftime(time(NULL),_startTime));
}

void			Timer::restart(void) {
	_startTime = time(NULL);
}
