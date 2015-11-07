/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 06:39:04 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/07 08:05:14 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

# include "GameEntity.class.hpp"

class Player: public GameEntity {

public:
	Player( int x, int y );
	Player(Player const & src);
	~Player( void );

	void			incAmmo(int amount);
	int				getAmmo(void) const;

	Player &		operator=( Player const & src );

	int			shoots;
	int			kills;
	int			ammo;

private:

};

#endif
