/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 19:16:43 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/07 02:56:06 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.class.hpp"

GameEntity::GameEntity ( int posx, int posy ): _posX(posx), _posY(posy) {
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
	this->_maxX = x;
	this->_maxY = y;
}

int					GameEntity::incPosXY(int x, int y) {
	if (this->_posX + x > 0 && this->_posX + x < this->_maxX \
	&& this->_posY + y > 0 && this->_posY + y < this->_maxY-1) {
		this->_posX += x;
		this->_posY += y;
		return (1);
	}
	return (-1);
}

int					GameEntity::setPosXY(int x, int y) {
	this->_posX = x;
	this->_posY = y;
	return (0);
}

/*
	- Getters
 */
int					GameEntity::getPosX( void ) const { return this->_posX; }
int					GameEntity::getPosY( void ) const { return this->_posY; }
