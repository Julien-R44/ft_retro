/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 04:16:46 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/07 05:15:05 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"

Enemy::Enemy(int x, int y): GameEntity(x-1, rand() % (y - 1) + 1) {
// Enemy::Enemy(int x, int y): GameEntity(10, 5) {
	// (void)x;
	// (void)y;
	// this->setPosXY(10, 5);
	return ;
}

Enemy::Enemy(Enemy const & src): GameEntity(0, 0) {
	*this = src;
}

Enemy::~Enemy( void ) {

}

Enemy &		Enemy::operator=( Enemy const & src ) {
	Enemy::operator=(src);
	return *this;
}
