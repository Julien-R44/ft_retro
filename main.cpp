/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 18:01:40 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/07 02:36:58 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include "Env.class.hpp"
#include "GameEntity.class.hpp"

int			main(void) {
	Env		env;
	GameEntity one(env.getSizeX() / 2, env.getSizeY() - 5);
	one.setMaxXY(env.getSizeX(), env.getSizeY());

	env.addPlayer(one);

	while (77) {
		if (env.updateAll() == -1)
			break ;
	}
	return (0);
}
