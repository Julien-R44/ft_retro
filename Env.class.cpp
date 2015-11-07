/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Env.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 18:01:14 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/07 08:05:28 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>
#include "Env.class.hpp"

Env::Env(void) : _hud(160, 20), _logger("debug.log") {
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	srand(time(NULL));
	for (int i = 0; i < MAX_ENEMIES; i++) { this->_enemies[i] = 0; }
	for (int i = 0; i < MAX_BULLETS; i++) { this->_bullets[i] = 0; }
	// ADD PLAYER
	Player *player = new Player(_hud.maxX / 2, _hud.maxY / 2);
	player->setMaxMinXY(_hud.maxX, _hud.maxY, _hud.minX, _hud.minY);
	this->addPlayer(*player);
	return ;
}

Env::Env(Env const & src) : _hud(50, 20), _logger("debug.log") {
	*this = src;
	return ;
}

Env::~Env( void ) {
	endwin();
	delete this->_player;
	return ;
}

Env	&			Env::operator=( Env const & src ) {
	// TO DO
	(void)src;
	return *this;
}

/* PUBLICS METHODS */
void			Env::addEnemy( Enemy & enemy ) {
	int i = 0;
	while (this->_enemies[i]) i++;
	this->_enemies[i] = &enemy;
}
void			Env::addBullet( GameEntity & entity ) {
	int i = 0;
	while (this->_bullets[i]) i++;
	this->_bullets[i] = &entity;
}

void			Env::addPlayer( Player & entity ) {
	this->_player = &entity;
}

int				Env::updateAll( void ) {
	this->_oldTime = clock();
	this->_hud.displayInfo(*this->_player);
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
void			Env::_updateEntities( void ) {
	for (int i = 0, j = 0; this->_bullets[i]; i++) {
		if (this->_bullets[i]->incPosXY(1, 0) == -1) {
			delete this->_bullets[i];
			this->_bullets[i] = NULL;
			for (j = i; this->_bullets[j+1]; j++) {
				this->_bullets[j] = this->_bullets[j+1];
			}
			this->_bullets[j] = NULL;
			return ;
		}
		// Check collision
		for (int k = 0, l = 0; this->_enemies[k]; k++) {
			if (this->_bullets[i]->getPosX() == this->_enemies[k]->getPosX()
			&& this->_bullets[i]->getPosY() == this->_enemies[k]->getPosY())
			{
				delete this->_enemies[k];
				this->_enemies[k] = NULL;
				for (l = k; this->_enemies[l+1]; l++) {
					this->_enemies[l] = this->_enemies[l+1];
				}
				this->_enemies[l] = NULL;

				this->_player->kills++;

				// delete this->_bullets[i];
				// this->_bullets[i] = NULL;
				// for (j = i; this->_bullets[j+1]; j++) {
				// 	this->_bullets[j] = this->_bullets[j+1];
				// }
				// this->_bullets[j] = NULL;

			}

		}
	}
}

void			Env::_updateEnemies( void ) {
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

void			Env::_genEnemy( void ) {
	static int frame = 0;
	frame++;

	if (frame == 60) {
		Enemy *enemy = new Enemy(_hud.maxX+1, _hud.maxY+1);
		enemy->setMaxMinXY(_hud.maxX, _hud.maxY, _hud.minX, _hud.minY);
		addEnemy(*enemy);
		frame = 0;
	}
}

void			Env::_drawEntities( void ) const {
	int i;

	mvprintw(this->_player->getPosY(), this->_player->getPosX(), ">");
	for (i = 0; this->_bullets[i]; i++)
		mvprintw(this->_bullets[i]->getPosY(), this->_bullets[i]->getPosX(), ".");
	for (i = 0; this->_enemies[i]; i++)
		mvprintw(this->_enemies[i]->getPosY(), this->_enemies[i]->getPosX(), "<");
}

void			Env::_drawCorners(void) const {
	for (int i = this->_hud.minX; i < (this->_hud.minX + this->_hud.mapX); i++) {
		mvprintw(this->_hud.getMapOffsetY(), i, "-");
		mvprintw(_hud.mapY, i, "-");
	}
	for (int i = this->_hud.getMapOffsetY(); i < (this->_hud.getMapOffsetY() + _hud.mapY); i++) {
		mvprintw(i, this->_hud.minX, "|");
		mvprintw(i, this->_hud.minX + this->_hud.mapX, "|");
	}
}

void			Env::_timeHandler(void) const {
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
			bullet->setMaxMinXY(_hud.maxX, _hud.maxY, _hud.minX, _hud.minY);
			addBullet(*bullet);
			this->_player->shoots++;
		}
		else if (ch == ECHAP)
			return (-1);
	}
	return (0);
}

const int		Env::_fps = 1000000 / 60;
