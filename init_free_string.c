/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdominqu <sdominqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:06:27 by sdominqu          #+#    #+#             */
/*   Updated: 2021/07/27 19:06:30 by sdominqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_string(t_data *main)
{
	char	*str;
	char	*str2;

	str = ft_itoa(main->score);
	str2 = ft_itoa(main->steps);
	mlx_string_put(main->mlx, main->mlx_win, 40, 21, 0xFFFFFF, "SCORE: ");
	mlx_string_put(main->mlx, main->mlx_win, 115, 21, 0xFFFFFF, "STEPS: ");
	mlx_string_put(main->mlx, main->mlx_win, 85, 21, 0xFFFFFF, str);
	mlx_string_put(main->mlx, main->mlx_win, 160, 21, 0xFFFFFF, str2);
	free(str);
	free(str2);
}

void	ft_free_all(t_data *main)
{
	int	i;

	i = 0;
	while (i < main->sizemap->height)
	{
		free(main->map_array[i]);
		i++;
	}
	free(main->map_array);
	free(main->sizemap);
	free(main->position_hero);
	free(main->cop_position);
	free(main);
}

t_data	*ft_creat_struct(void)
{
	t_data	*main;

	main = malloc(sizeof(t_data));
	main->sizemap = malloc(sizeof(t_size_map));
	main->position_hero = malloc(sizeof(t_position_hero));
	main->cop_position = malloc(sizeof(t_position_hero));
	main->position_hero->x_pos_hero = 0;
	main->position_hero->y_pos_hero = 0;
	main->sizemap->width = 0;
	main->sizemap->height = 0;
	main->coins = 0;
	main->exit_game = 0;
	main->start_position = 0;
	main->score = 0;
	main->steps = 0;
	main->flag = 1;
	main->time = 0;
	main->for_ex = 0;
	return (main);
}
