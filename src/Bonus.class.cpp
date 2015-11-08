/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bonus.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 08:06:31 by jripoute          #+#    #+#             */
/*   Updated: 2015/11/08 11:51:38 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bonus.class.hpp"

#include <stdlib.h>
Bonus::Bonus(int posx, int posy, int bonustype):
	GameEntity(posx, posy),
	_bonusType(bonustype)
{
	Bonus::_nbInstance += 1;
	return ;
}

Bonus::Bonus(Bonus const & src): GameEntity(0, 0) {
	Bonus::_nbInstance += 1;
	*this = src;
}

Bonus::~Bonus( void ) {
	Bonus::_nbInstance -= 1;
	return ;
}

Bonus & Bonus::operator=(Bonus const & src) {
	return *this;
}

void		Bonus::draw(void) const {
	std::string	toDraw;

	if (this->_bonusType == B_LIFE)
		toDraw = "L";
	else if (this->_bonusType == B_HEAL)
		toDraw = "H";
	else if (this->_bonusType == B_MONEY)
		toDraw = "$";
	mvprintw(_posY, _posX, toDraw.c_str());
}

// Getters
int			Bonus::getBonusType(void) const { return this->_bonusType; }
// Static
int			Bonus::getNbInstance(void) { return Bonus::_nbInstance; }
int			Bonus::_nbInstance = 0;
