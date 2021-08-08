/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdominqu <sdominqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:58:53 by sdominqu          #+#    #+#             */
/*   Updated: 2021/07/27 18:58:55 by sdominqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_handler(int key, t_data *main)
{
	if (key == 53)
	{
		ft_free_all(main);
		exit(1);
	}
	if (key == 13)
		ft_move_up(main);
	if (key == 1)
		ft_move_down(main);
	if (key == 2)
	{
		ft_move_right(main);
		main->hero_xpm = main->hero1_xpm;
	}
	if (key == 0)
	{
		ft_move_left(main);
		main->hero_xpm = main->hero2_xpm;
	}
	return (0);
}

int	ft_move_up(t_data *main)
{
	ft_moves(main, -1, 0);
	main->time += 12;
	return (0);
}

int	ft_move_down(t_data *main)
{
	ft_moves(main, 1, 0);
	main->time += 1;
	return (0);
}

int	ft_move_right(t_data *main)
{
	ft_moves(main, 0, 1);
	main->time += 4;
	return (0);
}

int	ft_move_left(t_data *main)
{
	ft_moves(main, 0, -1);
	main->time += 7;
	return (0);
}
