/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 19:16:43 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/08 07:26:44 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.class.hpp"

GameEntity::GameEntity ( int posx, int posy ):
	_posX(posx),
	_posY(posy),
	_minX(0),
	_minY(0),
	_maxY(0),
	_maxX(0),
	_dirX(0),
	_dirY(0)
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

void				GameEntity::setMaxMinXY( int maxx, int maxy, int minx, int miny ) {
	this->_maxX = maxx;
	this->_maxY = maxy;

	this->_minX = minx;
	this->_minY = miny;
}

int					GameEntity::incPosXY(int x, int y) {
	if (this->_posX + x > this->_minX && this->_posX + x < this->_maxX \
	&& this->_posY + y > this->_minY && this->_posY + y < this->_maxY-1) {
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

void				GameEntity::setDirXY( int x, int y ) {
	this->_dirX = x;
	this->_dirY = y;
}

/*
	- Getters
 */
int					GameEntity::getPosX( void ) const { return this->_posX; }
int					GameEntity::getPosY( void ) const { return this->_posY; }
int					GameEntity::getDirX( void ) const { return this->_dirX; }
int					GameEntity::getDirY( void ) const { return this->_dirY; }
