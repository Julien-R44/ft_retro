/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigShip.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 08:23:21 by jripoute          #+#    #+#             */
/*   Updated: 2015/11/08 09:13:00 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BigShip.class.hpp"

BigShip::BigShip(int x, int maxRandY): Enemy(x, maxRandY) {
	// this->_maxY -= 10;
	this->_posY = 3;
}

BigShip::BigShip(BigShip const & src): Enemy(0, 0) {
	*this = src;
}

BigShip::~BigShip(void) {
	return ;
}

BigShip &	BigShip::operator=(BigShip const & src) {
	return *this;
}

void		BigShip::draw(void) const {
	mvprintw(_posY, _posX,		"   /|");
	mvprintw(_posY+1, _posX,	"  /-|");
	mvprintw(_posY+2, _posX,	" /--|");
	mvprintw(_posY+3, _posX,	"/---|");
	mvprintw(_posY+4, _posX, 	"|---|");
	mvprintw(_posY+5, _posX, 	"\\---|");
	mvprintw(_posY+6, _posX, 	" \\--|");
	mvprintw(_posY+7, _posX, 	"  \\-|");
	mvprintw(_posY+7, _posX, 	"   \\|");
}
