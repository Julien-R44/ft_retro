/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HUD.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 06:52:10 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/07 08:03:18 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_CLASS_HPP
# define HUD_CLASS_HPP

# include "Player.class.hpp"

# include <curses.h>

class HUD {

public:
	HUD(int mapX, int mapY);
	HUD(HUD const & src);
	~HUD();

	void	displayInfo(Player & player) const;
	int		getMapOffsetX(void) const;
	int		getMapOffsetY(void) const;

	HUD &		operator=( HUD const & src );

	int		maxX;
	int		maxY;
	int		minX;
	int		minY;
	int		mapX;
	int		mapY;

private:
	int		_mapOffsetX;
	int		_mapOffsetY;

	int		_tabOffsetX;
	int		_tabOffsetY;

	int		_tabSizeX;
	int		_tabSizeY;

};


#endif
