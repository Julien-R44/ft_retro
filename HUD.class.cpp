/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HUD.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 06:52:10 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/08 07:14:02 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HUD.class.hpp"

HUD::HUD(int mapX, int mapY): mapX(mapX), mapY(mapY), _timer(), _mapOffsetX(30), _mapOffsetY(1) {
	// Map
	maxX = this->_mapOffsetX + this->mapX;
	maxY = this->_mapOffsetY + this->mapY;
	minX = this->_mapOffsetX;
	minY = this->_mapOffsetY;

	// Scores Tab
	_tabOffsetX = 2;
	_tabOffsetY = 2;
	_tabSizeX = 20;
	_tabSizeY = 10;

	return ;
}

HUD::HUD(HUD const & src) {
	*this = src;
}

HUD::~HUD(void) {
	return ;
}

HUD & 			HUD::operator=( HUD const & src) {
	this->mapX = src.mapX;
	this->mapY = src.mapY;
	return *this;
}

void			HUD::displayHUD(Player & player) const {
	_displayInfo(player);
	_displayBar(player);
	attron(COLOR_PAIR(4));
	_drawSquare(mapX, mapY, _mapOffsetX, _mapOffsetY);
	attroff(COLOR_PAIR(4));
}

void			HUD::_displayInfo(Player & player) const {
	double killPerShoot = 0;

	attron(COLOR_PAIR(4));
	_drawSquare(20, 10, 2, 1);
	attroff(COLOR_PAIR(4));
	mvprintw(this->_tabOffsetY + 1, this->_tabOffsetX + 2, "Life left: %d", player.life);
	mvprintw(this->_tabOffsetY + 3, this->_tabOffsetX + 2, "Kills: %d", player.kills);
	mvprintw(this->_tabOffsetY + 5, this->_tabOffsetX + 2, "Shoots: %d", player.shoots);
	mvprintw(this->_tabOffsetY + 7, this->_tabOffsetX + 2, "Time: %0.f sec.", _timer.getElapsedTime());
}

void			HUD::_displayBar(Player & player) const {
	attron(COLOR_PAIR(4));
	_drawSquare(mapX, 1, 30, maxY+2);
	attroff(COLOR_PAIR(4));

	attron(COLOR_PAIR(5));
	_drawSquare(player.health * mapX / 100, 1, 30, maxY+2);
	attroff(COLOR_PAIR(5));
	mvprintw(maxY+1, 30, "Health: %d%%.", player.health);
}

void			HUD::_drawSquare(int x, int y, int offx, int offy) const {
	for (int i = offx; i < (offx + x); i++) {
		mvprintw(offy, i, " ");
		mvprintw(offy + y, i, " ");
	}
	for (int i = offy; i < (offy + y + 1); i++) {
		mvprintw(i, offx, " ");
		mvprintw(i, offx + x, " ");
	}
}

int				HUD::getMapOffsetX(void) const { return this->_mapOffsetX; }
int				HUD::getMapOffsetY(void) const { return this->_mapOffsetY; }
