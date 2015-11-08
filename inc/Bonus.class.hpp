/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bonus.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 08:07:10 by jripoute          #+#    #+#             */
/*   Updated: 2015/11/08 08:18:29 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_CLASS_HPP
# define BONUS_CLASS_HPP

# include "GameEntity.class.hpp"

class Bonus : public GameEntity {

public:
	Bonus(int posx, int posy);
	Bonus(Bonus const & src);
	~Bonus(void);

	Bonus &	operator=(Bonus const & src);
};

#endif
