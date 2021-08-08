/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_cop_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdominqu <sdominqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:59:04 by sdominqu          #+#    #+#             */
/*   Updated: 2021/07/27 18:59:06 by sdominqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_cop_realization5(t_data *main, t_xy *xy)
{
	if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == DOOR_CLOSE)
		ft_move_cop_helper(main, xy, EMPTY, COP_ON_DOOR);
	else if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == EMPTY)
		ft_move_cop_helper(main, xy, EMPTY, COP);
	else if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == COIN)
		ft_move_cop_helper(main, xy, EMPTY, COP_ON_COIN);
	else if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == DOOR_OPEN)
		ft_move_cop_helper(main, xy, EMPTY, COP_ON_DOOR_O);
	else if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == HERO)
		ft_move_cop_helper(main, xy, EMPTY, COP_ON_DEAD);
}

void	ft_move_cop_helper(t_data *main, t_xy *xy, char a, char b)
{
	main->map_array[main->cop_position->x_pos_hero]
	[main->cop_position->y_pos_hero] = a;
	main->cop_position->x_pos_hero += xy->x;
	main->cop_position->y_pos_hero += xy->y;
	main->map_array[main->cop_position->x_pos_hero]
	[main->cop_position->y_pos_hero] = b;
}
