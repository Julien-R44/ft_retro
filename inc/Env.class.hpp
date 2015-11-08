/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Env.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 18:01:39 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/08 11:45:47 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CLASS_HPP
# define MAP_CLASS_HPP

# include <iostream>
# include <curses.h>
# include "GameEntity.class.hpp"
# include "Enemy.class.hpp"
# include "HUD.class.hpp"
# include "Player.class.hpp"
# include "Bonus.class.hpp"
# include "BigShip.class.hpp"

// LIMITS
# define MAX_BULLETS 512
# define MAX_ENEMIES 64
# define MAX_BONUS 64
# define MAP_LIMITS _hud.maxX, _hud.maxY+1, _hud.minX, _hud.minY

// TIMERS
# define REP_BONUS 500
# define REP_ENEMY 10

class Env {

	typedef enum	e_keys {
		ECHAP = 27,
		K_SPACE = 32,
		K_RIGHT = 261,
		K_LEFT = 260,
		K_UP = 259,
		K_DOWN = 258,
		K_ONE = 49,
		K_TWO = 50,
		K_THREE = 51
	}				t_keys;

public:
	Env( void );
	Env( Env const & src );
	~Env( void );


	void				addBonus( Bonus & bonus );
	void				addEnemy( Enemy & enemy );
	void				addBullet( GameEntity & entity );
	int					updateAll( void );

	Env &			operator=( Env const & src );

private:
	HUD					_hud;
	Player				*_player;
	Bonus				*_bonus[MAX_BONUS];
	GameEntity			*_bullets[MAX_BULLETS];
	Enemy				*_enemies[MAX_ENEMIES];
	clock_t				_oldTime;
	clock_t				_newTime;
	static const int 	_fps;

	// Init
	void				_initCurses( void );

	// Update
	void				_collisionsBonus( void );
	void				_updateEntities( void );
	void				_updateEnemies( void );

	// Draw
	void				_drawEntities( void ) const;
	void				_timeHandler( void ) const;

	void				_genBonus( void );
	void				_genEnemy( void );
	int					_keyHook( void );
};



#endif
