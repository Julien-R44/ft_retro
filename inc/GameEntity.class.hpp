/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 19:16:47 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/08 08:57:06 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENTITY_CLASS_HPP
# define GAME_ENTITY_CLASS_HPP

# include <string>
# include <curses.h>

class GameEntity {

public:
	GameEntity( int posx, int posy );
	GameEntity( GameEntity const & src );
	~GameEntity( void );


	void			setMaxMinXY( int maxx, int maxy, int minx, int miny );
	void			setDirXY( int x, int y );

	int				incPosXY( int x, int y );
	int				setPosXY( int x, int y );

	int				getPosX( void ) const ;
	int				getPosY( void ) const ;

	int				getDirX( void ) const ;
	int				getDirY( void ) const ;

	std::string 	getDraw( void ) const ;
	virtual void 	draw(void) const;

	GameEntity &	operator=( GameEntity const & src );

protected:
	// string printed for this
	std::string	_draw;

	// Actual pos
	int			_posX;
	int			_posY;

	// Min Coords Allowed
	int			_minX;
	int			_minY;

	// Max Coords Allowed
	int			_maxX;
	int			_maxY;

	// Deplacement Vector2d
	int			_dirX;
	int			_dirY;

};

#endif
