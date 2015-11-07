/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Env.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 18:01:14 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/07 02:26:35 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>
#include "Env.class.hpp"

Env::Env(void) : _logger("debug.log") {
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	this->_updateSize();
	return ;
}

Env::Env(Env const & src) : _logger("debug.log") {
	*this = src;
	return ;
}

Env::~Env( void ) {
	endwin();
	return ;
}

Env	&		Env::operator=( Env const & src ) {
	// TO DO
	(void)src;
	return *this;
}

/* GETTERS */
int		Env::getSizeX( void ) const { return this->_mapSizeX; }
int		Env::getSizeY( void ) const { return this->_mapSizeY; }

/* PUBLICS METHODS */
void		Env::addPlayer( GameEntity & entity ) {
	this->_player = &entity;
}

void		Env::addEntity( GameEntity & entity ) {
	int i = 0;
	while (this->_entities[i]) i++;
	this->_entities[i] = &entity;
}

int			Env::updateAll( void ) {
	this->_oldTime = clock();
	this->_updateSize();
	this->_drawCorners();
	this->_drawEntities();
	if (this->_keyHook() == -1)
		return (-1);
	this->_timeHandler();
	clear();
	refresh();
	return (0);
}

/* PRIVATES METHODS */
void		Env::_timeHandler(void) {
	int delta = clock() - this->_oldTime;
	if (delta < Env::_fps)
		usleep(Env::_fps - delta);
}

void		Env::_updateSize(void) {
	getmaxyx(stdscr, this->_mapSizeY, this->_mapSizeX);
}

void		Env::_drawEntities( void ) const {
	// Player
	mvprintw(this->_player->getPosY(), this->_player->getPosX(), ">");
	// Enemy
	for (int i = 0; this->_entities[i]; i++) {
		mvprintw(this->_entities[i]->getPosY(), this->_entities[i]->getPosX(), ">");
	}
}

void		Env::_drawCorners(void) const {
	for (int i = 0; i < this->_mapSizeX; i++) {
		mvprintw(0, i, "-");
		mvprintw(this->_mapSizeY - 1, i, "-");
	}
	for (int i = 0; i < this->_mapSizeX; i++) {
		mvprintw(i, 0, "|");
		mvprintw(i, this->_mapSizeX - 1, "|");
	}
}

int				Env::_keyHook(void) const {
	int		ch;
	int moved = 0;

	while (ch = getch()) {
		if (ch == ERR)
			break ;
		else if ((ch == K_UP || ch == K_DOWN || ch == K_LEFT || ch == K_RIGHT) && moved == 0) {
			if (ch == K_UP)
				this->_player->incPosXY(0, -1);
			else if (ch == K_DOWN)
				this->_player->incPosXY(0, 1);
			else if (ch == K_LEFT)
				this->_player->incPosXY(-1, 0);
			else if (ch == K_RIGHT)
				this->_player->incPosXY(1, 0);
			moved = 1;
		}
		else if (ch == ECHAP)
			return (-1);
	}
	return (0);
}

const int		Env::_fps = 1000000 / 60;
