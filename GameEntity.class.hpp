/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 19:16:47 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/07 02:24:22 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENTITY_CLASS_HPP
# define GAME_ENTITY_CLASS_HPP

class GameEntity {

public:
	GameEntity( int posx, int posy , int maxX, int maxY);
	GameEntity( GameEntity const & src );
	~GameEntity( void );

	void			setMaxXY( int x, int y );

	void			incPosXY( int x, int y );
	void			setPosXY( int x, int y );

	int				getPosX( void ) const ;
	int				getPosY( void ) const ;

	GameEntity &	operator=( GameEntity const & src );

private:
	int			_posX;
	int			_posY;
	int			_maxX;
	int			_maxY;

};

#endif
