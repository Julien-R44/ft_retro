/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bonus.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 08:07:10 by jripoute          #+#    #+#             */
/*   Updated: 2015/11/08 11:49:47 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_CLASS_HPP
# define BONUS_CLASS_HPP

# include <curses.h>
# include "GameEntity.class.hpp"
# include "Timer.class.hpp"

class Bonus : public GameEntity {

public:
	Bonus(int posx, int posy, int type);
	Bonus(Bonus const & src);
	~Bonus(void);

	Bonus &	operator=(Bonus const & src);

	virtual void	draw(void) const;
	static int		getNbInstance(void);
	int				getBonusType(void) const;

private:
	int				_bonusType;
	static int		_nbInstance;
};

typedef enum	e_bonus_type
{
	B_LIFE = 1,
	B_HEAL,
	B_MONEY
}				t_bonus_type;



#endif
