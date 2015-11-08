/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Env.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 18:01:14 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/08 04:50:48 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>
#include "Env.class.hpp"

Env::Env(void) : _hud(100, 10) {
	_initCurses();
	// Arrays inits
	for (int i = 0; i < MAX_ENEMIES; i++) { this->_enemies[i] = 0; }
	for (int i = 0; i < MAX_BULLETS; i++) { this->_bullets[i] = 0; }
	// ADD PLAYER
	Player *player = new Player(_hud.minX + 4, _hud.maxY / 2);
	player->setMaxMinXY(_hud.maxX, _hud.maxY, _hud.minX, _hud.minY);
	this->addPlayer(*player);
	return ;
}

Env::Env(Env const & src) : _hud(50, 20) {
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

void			Env::_initCurses(void) {
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	srand(time(NULL));
	// Colors
	start_color();
	init_pair(1, 0, COLOR_WHITE);
	init_pair(2, COLOR_MAGENTA, 0);
	init_pair(3, COLOR_RED, 0);
	init_pair(4, 0, COLOR_WHITE);
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
	this->_hud.displayHUD(*this->_player);
	this->_genEnemy();
	this->_updateEntities();
	this->_updateEnemies();
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

	for (int i = 0, j = 0; _bullets[i]; i++) {

		// If bullet in the wall, then delete it and shift array
		if (_bullets[i]->incPosXY(1, 0) == -1) {
			delete _bullets[i];
			_bullets[i] = NULL;
			for (j = i; _bullets[j+1]; j++) { _bullets[j] = _bullets[j+1]; }
			_bullets[j] = NULL;
			return ;
		}

		// Check collision
		for (int k = 0, l = 0; _enemies[k]; k++) {
			if (_bullets[i]->getPosX() == _enemies[k]->getPosX()
			&& _bullets[i]->getPosY() == _enemies[k]->getPosY())
			{
				delete _enemies[k];
				_enemies[k] = NULL;
				for (l = k; _enemies[l+1]; l++) {
					_enemies[l] = _enemies[l+1];
				}
				_enemies[l] = NULL;
				_player->kills++;
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

		if (this->_enemies[i]->getPosX() == this->_player->getPosX() && this->_enemies[i]->getPosY() == this->_player->getPosY())
				this->_player->getKilled();

		if (this->_enemies[i]->incPosXY(vecx, 0) == -1) {
			delete this->_enemies[i];
			this->_enemies[i] = NULL;
			for (j = i; this->_enemies[j+1]; j++) {
				this->_enemies[j] = this->_enemies[j+1];
			}
			this->_enemies[j] = NULL;
		}

	}

	if (frame == 6)
	{
		frame = 0;
		vecx = 0;
	}
}

void			Env::_genEnemy( void ) {
	static int frame = 0;
	frame++;

	if (frame == 10) {
		Enemy *enemy = new Enemy(_hud.maxX+1, _hud.maxY+1);
		enemy->setMaxMinXY(_hud.maxX, _hud.maxY, _hud.minX, _hud.minY);
		addEnemy(*enemy);
		frame = 0;
	}
}

void			Env::_drawEntities( void ) const {
	int i;

	attron(COLOR_PAIR(2));
	mvprintw(this->_player->getPosY(), this->_player->getPosX(), ">");
	attroff(COLOR_PAIR(2));
	for (i = 0; this->_bullets[i]; i++)
		mvprintw(this->_bullets[i]->getPosY(), this->_bullets[i]->getPosX(), "-");
	attron(COLOR_PAIR(3));
	for (i = 0; this->_enemies[i]; i++)
		mvprintw(this->_enemies[i]->getPosY(), this->_enemies[i]->getPosX(), "<");
	attroff(COLOR_PAIR(3));
}

void			Env::_timeHandler(void) const {
	int delta = clock() - this->_oldTime;
	if (delta < Env::_fps)
		usleep(Env::_fps - delta);
}

int				Env::_keyHook(void) {
	int		ch;
	int moved = 0;

	while ((ch = getch())) {
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
