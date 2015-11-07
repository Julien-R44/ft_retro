/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HUD.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 06:52:10 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/07 08:12:27 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HUD.class.hpp"

HUD::HUD(int mapX, int mapY): mapX(mapX), mapY(mapY), _mapOffsetX(30), _mapOffsetY(1) {
	// Map
	maxX = this->_mapOffsetX + this->mapX;
	maxY = this->_mapOffsetY + this->mapY;
	minX = this->_mapOffsetX;
	minY = this->_mapOffsetY;

	// Scores Tab
	_tabOffsetX = 2;
	_tabOffsetY = 2;
	_tabSizeX = 20;
	_tabSizeY = 17;
	return ;
}

HUD::HUD(HUD const & src) {
	*this = src;
}

HUD::~HUD(void) {
	return ;
}

HUD & 	HUD::operator=( HUD const & src) {
	this->mapX = src.mapX;
	this->mapY = src.mapY;
	return *this;
}

void	HUD::displayInfo(Player & player) const {
	double killPerShoot = 0;
	// Edges
	for (int i = this->_tabOffsetX; i < (this->_tabOffsetX + this->_tabSizeX); i++) {
		mvprintw(this->_tabOffsetY, i, "-");
		mvprintw(this->_tabOffsetY + this->_tabSizeY, i, "-");
	}
	for (int i = this->_tabOffsetY; i < (this->_tabOffsetY + this->_tabSizeY+1); i++) {
		mvprintw(i, this->_tabOffsetX, "|");
		mvprintw(i, this->_tabOffsetX + this->_tabSizeX, "|");
	}
	// Text
	mvprintw(this->_tabOffsetY + 2, this->_tabOffsetX + 2, "Kills: %d", player.kills);
	mvprintw(this->_tabOffsetY + 4, this->_tabOffsetX + 2, "Shoots: %d", player.shoots);
}

int		HUD::getMapOffsetX(void) const { return this->_mapOffsetX; }
int		HUD::getMapOffsetY(void) const { return this->_mapOffsetY; }
