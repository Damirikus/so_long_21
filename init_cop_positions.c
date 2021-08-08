/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cop_positions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdominqu <sdominqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:06:10 by sdominqu          #+#    #+#             */
/*   Updated: 2021/07/27 19:06:12 by sdominqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_chek_all_cops_position(t_data *main)
{
	int	i;
	int	k;

	i = 1;
	while (i < main->sizemap->height - 1)
	{
		k = 1;
		while (k < main->sizemap->width - 1)
		{
			if (main->map_array[i][k] == COP ||
				main->map_array[i][k] == COP_ON_COIN
				|| main->map_array[i][k] == COP_ON_DEAD
				|| main->map_array[i][k] == COP_ON_DOOR
				|| main->map_array[i][k] == COP_ON_DOOR_O)
			{
				main->cop_position->x_pos_hero = i;
				main->cop_position->y_pos_hero = k;
				ft_move_cops(main);
				main->time++;
			}
			k++;
		}
		i++;
	}
}

void	ft_init_cop_position(t_data *main)
{
	int	cops;
	int	i;
	int	k;

	if ((main->sizemap->height > 3 && main->sizemap->height < 6)
		|| (main->sizemap->width > 4 && main->sizemap->width < 11))
		cops = 1;
	else
		cops = 2;
	i = main->sizemap->height / 2;
	while (i < main->sizemap->height - 1 && cops > 0)
	{
		k = main->sizemap->width / 2 - 1;
		while (k < main->sizemap->width - 2 && cops > 0)
		{
			ft_qw_cops(main, &cops, i, k);
			k++;
		}
		i++;
	}
}

void	ft_qw_cops(t_data *main, int *cops, int i, int k)
{
	if (main->map_array[i][k] == EMPTY &&
		main->map_array[i][k - 1] == EMPTY &&
		main->map_array[i][k + 1] == EMPTY &&
		main->map_array[i][k - 2] != HERO &&
		main->map_array[i][k + 2] != HERO &&
		main->map_array[i - 1][k] != HERO &&
		main->map_array[i + 1][k] != HERO &&
		main->map_array[i + 1][k + 1] != HERO &&
		main->map_array[i + 1][k - 1] != HERO &&
		main->map_array[i - 1][k + 1] != HERO &&
		main->map_array[i - 1][k - 1] != HERO)
	{
		main->map_array[i][k] = COP;
		(*cops)--;
	}
}

void	ft_move_cops(t_data *main)
{
	if (main->time % 100 == 15 || main->time % 100 == 50)
	{
		ft_move_cop_realization(main, 0, 1);
		main->cop_xpm = main->cop2_xpm;
	}
	if (main->time % 100 == 30 || main->time % 100 == 90)
	{
		ft_move_cop_realization(main, 0, -1);
		main->cop_xpm = main->cop1_xpm;
	}
	if (main->time % 100 == 70)
		ft_move_cop_realization(main, -1, 0);
	if (main->time % 100 == 1)
		ft_move_cop_realization(main, 1, 0);
}
