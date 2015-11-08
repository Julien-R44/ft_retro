/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 06:39:04 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/08 06:19:31 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

# include <iostream>
# include <curses.h>
# include "GameEntity.class.hpp"

class Player: public GameEntity {

public:
	Player( int x, int y );
	Player(Player const & src);
	~Player( void );

	void			getKilled(void);
	void			incAmmo(int amount);
	int				getAmmo(void) const;

	Player &		operator=( Player const & src );

	int			health;
	int			life;
	int			shoots;
	int			kills;
	int			ammo;

private:
	int			_respawnX;
	int			_respawnY;
};

#endif
