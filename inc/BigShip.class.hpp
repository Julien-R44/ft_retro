/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigShip.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 08:23:26 by jripoute          #+#    #+#             */
/*   Updated: 2015/11/08 08:58:57 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIG_SHIP_CLASS_HPP
# define BIG_SHIP_CLASS_HPP

# include "Enemy.class.hpp"

class BigShip : public Enemy {

public:
	BigShip( int x, int maxRandY );
	BigShip(BigShip const & src);
	~BigShip( void );

	BigShip &		operator=(BigShip const & src);

	virtual void	draw(void) const;

};


#endif
