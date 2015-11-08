/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 18:01:40 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/08 00:37:59 by jripoute         ###   ########.fr       */
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


int			main(void) {
	Env		env;

	while (77) {
		if (env.updateAll() == -1)
			break ;
	}
	return (0);

  return 0;
}
