/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 04:16:46 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/08 06:08:15 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"

Enemy::Enemy(int x, int y):
	GameEntity(x-1, rand() % (y - 1) + 1),
	_reloading(0)
{
	return ;
}

Enemy::Enemy(Enemy const & src): GameEntity(0, 0) {
	*this = src;
}

Enemy::~Enemy( void ) {

}

Enemy &		Enemy::operator=( Enemy const & src ) {
	GameEntity::operator=(src);
	return *this;
}

GameEntity & Enemy::shoot(int maxX, int maxY , int minX, int minY) const {
	GameEntity *bullet = new GameEntity(this->_posX-2, this->_posY);
	bullet->setDirXY(-1, 0);
	return *bullet;
}

bool		Enemy::reload( void ) {
	_reloading++;
	if (_reloading == Enemy::_reloadTime) {
		_reloading = 0;
		return true;
	}
	return false;
}

const int	Enemy::_reloadTime = 100;
