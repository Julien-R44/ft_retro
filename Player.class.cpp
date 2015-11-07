/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 06:39:04 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/07 08:06:16 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

Player::Player( int posX, int posY ) : GameEntity(posX, posY), shoots(0), kills(0), ammo(0) {

}

Player::Player( Player const & src ) : GameEntity(0, 0) {
	*this = src;
}

Player::~Player( void ) {
	return ;
}

Player &		Player::operator=( Player const & src ) {
	GameEntity::operator=(src);
	return *this;
}
