/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bonus.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 08:06:31 by jripoute          #+#    #+#             */
/*   Updated: 2015/11/08 08:10:18 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bonus.class.hpp"

Bonus::Bonus(int posx, int posy): GameEntity(posx, posy) {

}

Bonus::Bonus(Bonus const & src): GameEntity(0, 0) {
	*this = src;
}

Bonus::~Bonus( void ) {
	return ;
}

Bonus & Bonus::operator=(Bonus const & src) {
	return *this;
}
