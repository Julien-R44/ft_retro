/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Env.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 18:01:39 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/07 06:22:14 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CLASS_HPP
# define MAP_CLASS_HPP

# include <iostream>
# include <curses.h>
# include "Logger.class.hpp"
# include "GameEntity.class.hpp"
# include "Enemy.class.hpp"

# define MAX_ENTITIES 512
# define MAX_ENEMIES 64

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


	void			addEnemy( Enemy & enemy );
	void			addPlayer( GameEntity & entity );
	void			addEntity( GameEntity & entity );
	int				updateAll( void );

	// Getters
	int				getSizeX( void ) const ;
	int				getSizeY( void ) const ;

	Env &			operator=( Env const & src );

private:
	GameEntity		*_player;
	GameEntity		*_entities[MAX_ENTITIES];
	Enemy			*_enemies[MAX_ENEMIES];
	Logger			_logger;
	int				_mapSizeX;
	int				_mapSizeY;
	clock_t			_oldTime;
	clock_t			_newTime;
	static const int _fps;

	// Update
	void			_updateEntities( void );
	void			_updateEnemies( void );
	void			_updateSize( void );


	// Draw
	void			_drawEntities( void ) const;
	void			_drawCorners( void ) const;
	void			_timeHandler( void ) const;

	void			_genEnemy( void );
	int				_keyHook( void );
};



#endif
