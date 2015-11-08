/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 04:16:46 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/08 08:35:59 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

# include <math.h>
# include <stdlib.h>
# include "GameEntity.class.hpp"

class Enemy : public GameEntity {

public:
	// First params is X = position pop, and y = max height
	Enemy(int x, int y);
	Enemy(Enemy const & src);
	~Enemy();

	// return a bullet
	GameEntity &	shoot(int maxX, int maxY, int minX, int minY) const;

	bool 			reload( void );

	Enemy &		operator=( Enemy const & src );

private:
	static const int	_reloadTime;
	int					_reloading;

};


#endif
