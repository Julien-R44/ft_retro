/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 18:01:40 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/08 13:48:07 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <curses.h>
#include "Env.class.hpp"
#include "GameEntity.class.hpp"
#include "Enemy.class.hpp"
#include "Player.class.hpp"
#include "HUD.class.hpp"
#include "Timer.class.hpp"
#include <time.h>
#include <sys/time.h>

void			drawSquare(int x, int y, int offx, int offy) {
	for (int i = offx; i < (offx + x); i++) {
		mvprintw(offy, i, "-");
		mvprintw(offy + y, i, "-");
	}
	for (int i = offy; i < (offy + y + 1); i++) {
		mvprintw(i, offx, "|");
		mvprintw(i, offx + x, "|");
	}
}

void		drawLogo(void) {
	attron(COLOR_PAIR(3));
	mvprintw(0+1, 40, " _____  ______      ____     ___ ______  ____   ___  ");
	mvprintw(0+2, 40, "|     ||      |    |    \\   /  _]      ||    \\ /   \\ ");
	mvprintw(0+3, 40, "|   __||      |    |  D  ) /  [_|      ||  D  )     |");
	mvprintw(0+4, 40, "|  |_  |_|  |_|    |    / |    _]_|  |_||    /|  O  |");
	mvprintw(0+5, 40, "|   _]   |  |      |    \\ |   [_  |  |  |    \\|     |");
	mvprintw(0+6, 40, "|  |     |  |      |  .  \\|     | |  |  |  .  \\     |");
	mvprintw(0+7, 40, "|__|     |__|      |__|\\_||_____| |__|  |__|\\_|\\___/ ");
	attroff(COLOR_PAIR(3));

	mvprintw(0+9, 60, "Press a key to play.");
}

void		principalMenu(void) {
	int x, y, ch;

	getmaxyx(stdscr, y, x);
	drawSquare(x-1, y-1, 0, 0);
	drawLogo();
	while ((ch = getch()) == ERR) {

	}
}

int			main(void) {
	Env		env;

	principalMenu();
	while (77) {
		if (env.updateAll() == -1)
			break ;
	}
	return (0);

  return 0;
}
