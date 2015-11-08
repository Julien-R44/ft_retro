/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timer.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 23:27:41 by jripoute          #+#    #+#             */
/*   Updated: 2015/11/08 00:37:34 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_CLASS_HPP
# define TIMER_CLASS_HPP

# include <time.h>

class Timer {

public:
	Timer( void );
	Timer(Timer const & src);
	~Timer( void );

	Timer &	operator=(Timer const & src);

	void			restart();
	double 			getElapsedTime(void) const;

private:
	time_t		_startTime;
};

#endif
