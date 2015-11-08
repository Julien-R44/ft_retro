/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigShip.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 08:23:21 by jripoute          #+#    #+#             */
/*   Updated: 2015/11/08 08:25:54 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BigShip.class.hpp"

BigShip::BigShip(void) {

}

BigShip::BigShip(BigShip const & src) {
	*this = src;
}

BigShip::~BigShip(void) {
	return ;
}

BigShip &	BigShip::operator=(BigShip const & src) {
	return *this;
}
