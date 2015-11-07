/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Env.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 18:01:14 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/07 06:23:05 by y0ja             ###   ########.fr       */
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
	srand(time(NULL));
	this->_updateSize();
	for (int i = 0; i < MAX_ENEMIES; i++) { this->_enemies[i] = 0; }
	for (int i = 0; i < MAX_ENTITIES; i++) { this->_entities[i] = 0; }
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
void		Env::addEnemy( Enemy & enemy ) {
	int i = 0;
	while (this->_enemies[i]) i++;
	this->_enemies[i] = &enemy;
}
void		Env::addEntity( GameEntity & entity ) {
	int i = 0;
	while (this->_entities[i]) i++;
	this->_entities[i] = &entity;
}
void		Env::addPlayer( GameEntity & entity ) {
	this->_player = &entity;
}

int			Env::updateAll( void ) {
	this->_oldTime = clock();
	this->_updateSize();
	this->_genEnemy();
	this->_updateEntities();
	this->_updateEnemies();
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
void		Env::_updateSize(void) {
	getmaxyx(stdscr, this->_mapSizeY, this->_mapSizeX);
}

void		Env::_updateEntities( void ) {
	for (int i = 0, j = 0; this->_entities[i]; i++) {
		if (this->_entities[i]->incPosXY(1, 0) == -1) {
			delete this->_entities[i];
			this->_entities[i] = NULL;
			for (j = i; this->_entities[j+1]; j++) {
				this->_entities[j] = this->_entities[j+1];
			}
			this->_entities[j] = NULL;
			return ;
		}
	}
}

void		Env::_genEnemy( void ) {
	static int frame = 0;
	frame++;

	if (frame == 60) {
		Enemy *enemy = new Enemy(this->_mapSizeX-1, this->_mapSizeY);
		enemy->setMaxXY(this->_mapSizeX, this->_mapSizeY);
		addEnemy(*enemy);
		frame = 0;
	}
}

void		Env::_updateEnemies( void ) {
	static int 	frame = 0;
	int			vecx = 0;


	frame++;
	if (frame == 6)
		vecx = -1;
	for (int i = 0, j = 0; this->_enemies[i]; i++) {
		if (this->_enemies[i]->incPosXY(vecx, 0) == -1) {
			delete this->_enemies[i];
			this->_enemies[i] = NULL;
			for (j = i; this->_enemies[j+1]; j++) {
				this->_enemies[j] = this->_enemies[j+1];
			}
			this->_enemies[j] = NULL;
		}
	}
	if (frame == 6) {
		frame = 0;
		vecx = 0;
	}
}

void		Env::_drawEntities( void ) const {
	int i;

	mvprintw(this->_player->getPosY(), this->_player->getPosX(), ">");
	for (i = 0; this->_entities[i]; i++)
		mvprintw(this->_entities[i]->getPosY(), this->_entities[i]->getPosX(), ".");
	for (i = 0; this->_enemies[i]; i++)
		mvprintw(this->_enemies[i]->getPosY(), this->_enemies[i]->getPosX(), "<");
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

void		Env::_timeHandler(void) const {
	int delta = clock() - this->_oldTime;
	if (delta < Env::_fps)
		usleep(Env::_fps - delta);
}

int				Env::_keyHook(void) {
	int		ch;
	int moved = 0;

	while (ch = getch()) {
		if (ch == ERR)
			break ;
		if ((ch == K_UP || ch == K_DOWN || ch == K_LEFT || ch == K_RIGHT) && moved == 0) {
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
		else if (ch == K_SPACE) {

			GameEntity *bullet = new GameEntity(this->_player->getPosX()+1, this->_player->getPosY());
			bullet->setMaxXY(this->_mapSizeX, this->_mapSizeX);
			addEntity(*bullet);
		}
		else if (ch == ECHAP)
			return (-1);
	}
	return (0);
}

const int		Env::_fps = 1000000 / 60;
