/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_hero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdominqu <sdominqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:59:20 by sdominqu          #+#    #+#             */
/*   Updated: 2021/07/27 18:59:22 by sdominqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_moves(t_data *main, int x, int y)
{
	t_xy	xy;

	xy.x = x;
	xy.y = y;
	if (main->map_array[main->position_hero->x_pos_hero + x]
		[main->position_hero->y_pos_hero + y] != WALL
		&& main->map_array[main->position_hero->x_pos_hero]
		[main->position_hero->y_pos_hero] != DEAD
		&& main->map_array[main->position_hero->x_pos_hero]
		[main->position_hero->y_pos_hero] != COP_ON_DEAD)
	{
		if (main->map_array[main->position_hero->x_pos_hero]
			[main->position_hero->y_pos_hero] == HERO_ON_DOOR)
			ft_moves1(main, &xy);
		else
		{
			ft_moves2(main, &xy);
			main->steps++;
		}
	}
	return (0);
}

void	ft_moves1(t_data *main, t_xy *xy)
{
	if (main->map_array[main->position_hero->x_pos_hero + xy->x]
		[main->position_hero->y_pos_hero + xy->y] == DOOR_CLOSE)
		ft_move_hero_helper(main, xy, DOOR_CLOSE, HERO_ON_DOOR);
	else if (main->map_array[main->position_hero->x_pos_hero + xy->x]
		[main->position_hero->y_pos_hero + xy->y] == EMPTY)
		ft_move_hero_helper(main, xy, DOOR_CLOSE, HERO);
	else if (main->map_array[main->position_hero->x_pos_hero + xy->x]
		[main->position_hero->y_pos_hero + xy->y] == COIN)
	{
		ft_move_hero_helper(main, xy, DOOR_CLOSE, HERO);
		main->coins--;
		main->score++;
	}
	else if (main->map_array[main->position_hero->x_pos_hero + xy->x]
		[main->position_hero->y_pos_hero + xy->y] == COP
		|| main->map_array[main->position_hero->x_pos_hero + xy->x]
		[main->position_hero->y_pos_hero + xy->y] == COP_ON_COIN
		|| main->map_array[main->position_hero->x_pos_hero + xy->x]
		[main->position_hero->y_pos_hero + xy->y] == COP_ON_DOOR)
		ft_move_hero_helper(main, xy, DOOR_CLOSE, DEAD);
}

void	ft_moves2(t_data *main, t_xy *xy)
{
	if (main->map_array[main->position_hero->x_pos_hero + xy->x]
		[main->position_hero->y_pos_hero + xy->y] == DOOR_CLOSE)
		ft_move_hero_helper(main, xy, EMPTY, HERO_ON_DOOR);
	else if (main->map_array[main->position_hero->x_pos_hero + xy->x]
		[main->position_hero->y_pos_hero + xy->y] == EMPTY)
		ft_move_hero_helper(main, xy, EMPTY, HERO);
	else if (main->map_array[main->position_hero->x_pos_hero + xy->x]
		[main->position_hero->y_pos_hero + xy->y] == COIN)
	{
		ft_move_hero_helper(main, xy, EMPTY, HERO);
		main->coins--;
		main->score++;
	}
	else if (main->map_array[main->position_hero->x_pos_hero + xy->x]
		[main->position_hero->y_pos_hero + xy->y] == COP
		|| main->map_array[main->position_hero->x_pos_hero + xy->x]
		[main->position_hero->y_pos_hero + xy->y] == COP_ON_COIN
		|| main->map_array[main->position_hero->x_pos_hero + xy->x]
		[main->position_hero->y_pos_hero + xy->y] == COP_ON_DOOR)
		ft_move_hero_helper(main, xy, EMPTY, DEAD);
	else if (main->map_array[main->position_hero->x_pos_hero + xy->x]
		[main->position_hero->y_pos_hero + xy->y] == DOOR_OPEN)
		exit(1);
}

void	ft_move_hero_helper(t_data *main, t_xy *xy, char a, char b)
{
	main->map_array[main->position_hero->x_pos_hero]
	[main->position_hero->y_pos_hero] = a;
	main->position_hero->x_pos_hero += xy->x;
	main->position_hero->y_pos_hero += xy->y;
	main->map_array[main->position_hero->x_pos_hero]
	[main->position_hero->y_pos_hero] = b;
}
