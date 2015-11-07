/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 04:16:46 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/07 05:55:21 by y0ja             ###   ########.fr       */
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

	Enemy &		operator=( Enemy const & src );

};

#endif
