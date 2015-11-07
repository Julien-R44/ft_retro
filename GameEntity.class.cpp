/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 19:16:43 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/07 02:11:27 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.class.hpp"

GameEntity::GameEntity ( int posx, int posy, int maxx, int maxy ):
	_posX(posx),
	_posY(posy),
	_maxX(maxx),
	_maxY(maxy)
{
	return ;
}

GameEntity::GameEntity( GameEntity const & src ) {
	*this = src;
	return ;
}

GameEntity::~GameEntity( void ) {
	return ;
}

GameEntity &		GameEntity::operator=( GameEntity const & src ) {
	this->_posX = src._posX;
	this->_posY = src._posY;
	return *this;
}

void				GameEntity::setMaxXY( int x, int y ) {
	if ((x < 0 || x > this->_maxX) || (y < 0 || y > this->_maxY))
		return ;
	this->_maxX = x;
	this->_maxY = y;
}

#include <iostream>

void				GameEntity::incPosXY(int x, int y) {
	if (this->_posX + x > 0 && this->_posX + x < this->_maxX)
		this->_posX += x;
	if (this->_posY + y > 0 && this->_posY + y < this->_maxY-1)
		this->_posY += y;
}

void				GameEntity::setPosXY(int x, int y) {
	this->_posX = x;
	this->_posY = y;
}

/*
	- Getters
 */
int					GameEntity::getPosX( void ) const { return this->_posX; }
int					GameEntity::getPosY( void ) const { return this->_posY; }
