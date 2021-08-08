/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_cop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdominqu <sdominqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:59:13 by sdominqu          #+#    #+#             */
/*   Updated: 2021/07/27 18:59:15 by sdominqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_cop_realization(t_data *main, int x, int y)
{
	t_xy	xy;

	xy.x = x;
	xy.y = y;
	if (main->map_array[main->cop_position->x_pos_hero + x]
		[main->cop_position->y_pos_hero + y] != WALL)
	{
		if (main->map_array[main->cop_position->x_pos_hero]
			[main->cop_position->y_pos_hero] == COP_ON_DOOR)
			ft_move_cop_realization1(main, &xy);
		else if (main->map_array[main->cop_position->x_pos_hero]
			[main->cop_position->y_pos_hero] == COP_ON_COIN)
			ft_move_cop_realization2(main, &xy);
		else if (main->map_array[main->cop_position->x_pos_hero]
			[main->cop_position->y_pos_hero] == COP_ON_DOOR_O)
			ft_move_cop_realization3(main, &xy);
		else if (main->map_array[main->cop_position->x_pos_hero]
			[main->cop_position->y_pos_hero] == COP_ON_DEAD)
			ft_move_cop_realization4(main, &xy);
		else
			ft_move_cop_realization5(main, &xy);
	}
	return (0);
}

void	ft_move_cop_realization1(t_data *main, t_xy *xy)
{
	if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == DOOR_CLOSE)
		ft_move_cop_helper(main, xy, DOOR_CLOSE, COP_ON_DOOR);
	else if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == EMPTY)
		ft_move_cop_helper(main, xy, DOOR_CLOSE, COP);
	else if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == COIN)
		ft_move_cop_helper(main, xy, DOOR_CLOSE, COP_ON_COIN);
	else if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == HERO)
		ft_move_cop_helper(main, xy, DOOR_CLOSE, COP_ON_DEAD);
}

void	ft_move_cop_realization2(t_data *main, t_xy *xy)
{
	if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == DOOR_CLOSE)
		ft_move_cop_helper(main, xy, COIN, COP_ON_DOOR);
	else if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == EMPTY)
		ft_move_cop_helper(main, xy, COIN, COP);
	else if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == COIN)
		ft_move_cop_helper(main, xy, COIN, COP_ON_COIN);
	else if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == DOOR_OPEN)
		ft_move_cop_helper(main, xy, COIN, COP_ON_DOOR_O);
	else if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == HERO)
		ft_move_cop_helper(main, xy, COIN, COP_ON_DEAD);
}

void	ft_move_cop_realization3(t_data *main, t_xy *xy)
{
	if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == EMPTY)
		ft_move_cop_helper(main, xy, DOOR_OPEN, COP);
	else if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == COIN)
		ft_move_cop_helper(main, xy, DOOR_OPEN, COP_ON_COIN);
	else if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == DOOR_OPEN)
		ft_move_cop_helper(main, xy, DOOR_OPEN, COP_ON_DOOR_O);
	else if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == HERO)
		ft_move_cop_helper(main, xy, DOOR_OPEN, COP_ON_DEAD);
}

void	ft_move_cop_realization4(t_data *main, t_xy *xy)
{
	if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == EMPTY)
		ft_move_cop_helper(main, xy, DEAD, COP);
	else if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == COIN)
		ft_move_cop_helper(main, xy, DEAD, COP_ON_COIN);
	else if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == DOOR_OPEN)
		ft_move_cop_helper(main, xy, DEAD, COP_ON_DOOR_O);
	else if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == HERO)
		ft_move_cop_helper(main, xy, DEAD, COP_ON_DEAD);
	else if (main->map_array[main->cop_position->x_pos_hero + xy->x]
		[main->cop_position->y_pos_hero + xy->y] == DOOR_CLOSE)
		ft_move_cop_helper(main, xy, DEAD, COP_ON_DOOR);
}
