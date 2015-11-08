/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 18:01:40 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/08 13:27:25 by jripoute         ###   ########.fr       */
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
		mvprintw(offy, i, " ");
		mvprintw(offy + y, i, " ");
	}
	for (int i = offy; i < (offy + y + 1); i++) {
		mvprintw(i, offx, " ");
		mvprintw(i, offx + x, " ");
	}
}


void		principalMenu(void) {
	int x, y, ch;

	getmaxyx(stdscr, x, y);

	drawSquare(x, y, 1, 1);
	while ((ch = getch()) == ERR) ;
}

int			main(void) {
	Env		env;

	// principalMenu();
	while (77) {
		if (env.updateAll() == -1)
			break ;
	}
	return (0);

  return 0;
}
