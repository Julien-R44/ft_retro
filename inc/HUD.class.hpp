/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HUD.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 06:52:10 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/08 02:17:12 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_CLASS_HPP
# define HUD_CLASS_HPP

# include "Player.class.hpp"
# include "Timer.class.hpp"
# include <iostream>
# include <curses.h>

class HUD {

public:
	HUD(int mapX, int mapY);
	HUD(HUD const & src);
	~HUD();

	int				getMapOffsetX(void) const;
	int				getMapOffsetY(void) const;
	void			displayHUD( Player & player ) const;

	HUD &			operator=( HUD const & src );

	int				maxX;
	int				maxY;
	int				minX;
	int				minY;
	int				mapX;
	int				mapY;

private:
	void			_drawSquare(int x, int y, int offx, int offy) const;
	void			_displayInfo(Player & player) const;
	void			_displayBar(Player & player) const;


	Timer			_timer;

	int				_mapOffsetX;
	int				_mapOffsetY;


	// TAB
	int				_tabOffsetX;
	int				_tabOffsetY;

	int				_tabSizeX;
	int				_tabSizeY;


	// BAR
	int				_barOffsetX;
	int				_barOffsetY;

	int				_barSizeX;
	int				_barSizeY;

};


#endif
