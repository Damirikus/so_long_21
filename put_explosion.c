/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_explosion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdominqu <sdominqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:59:28 by sdominqu          #+#    #+#             */
/*   Updated: 2021/07/27 18:59:30 by sdominqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_explosion(t_data *main, int x, int y)
{
	static int	temp = 0;

	if (main->map_array[y][x] == DOOR_OPEN && main->flag == 0
		&& main->for_ex % 20 == 1)
	{
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->explosion1.img_ptr_xpm, x * PIXELS, y * PIXELS + INFO_WIN);
		temp++;
	}
	else
		ft_put_explosion1(main, x, y, &temp);
	if (temp == 9)
		main->coins += 1;
}

void	ft_put_explosion1(t_data *main, int x, int y, int *temp)
{
	if (main->map_array[y][x] == DOOR_OPEN && main->flag == 0
		&& main->for_ex % 20 == 3)
	{
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->explosion2.img_ptr_xpm, x * PIXELS, y * PIXELS + INFO_WIN);
		(*temp)++;
	}
	else if (main->map_array[y][x] == DOOR_OPEN && main->flag == 0
			 && main->for_ex % 20 == 5 )
	{
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->explosion3.img_ptr_xpm, x * PIXELS, y * PIXELS + INFO_WIN);
		(*temp)++;
	}
	else if (main->map_array[y][x] == DOOR_OPEN && main->flag == 0
			 && main->for_ex % 20 == 7 )
	{
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->explosion4.img_ptr_xpm, x * PIXELS, y * PIXELS + INFO_WIN);
		(*temp)++;
	}
	else
		ft_put_explosion2(main, x, y, temp);
}

void	ft_put_explosion2(t_data *main, int x, int y, int *temp)
{
	if (main->map_array[y][x] == DOOR_OPEN && main->flag == 0
		&& main->for_ex % 20 == 9 )
	{
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->explosion5.img_ptr_xpm, x * PIXELS, y * PIXELS + INFO_WIN);
		(*temp)++;
	}
	else if (main->map_array[y][x] == DOOR_OPEN && main->flag == 0
		&& main->for_ex % 20 == 11 )
	{
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->explosion6.img_ptr_xpm, x * PIXELS, y * PIXELS + INFO_WIN);
		(*temp)++;
	}
	else if (main->map_array[y][x] == DOOR_OPEN && main->flag == 0
		&& main->for_ex % 20 == 13)
	{
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->explosion7.img_ptr_xpm, x * PIXELS, y * PIXELS + INFO_WIN);
		(*temp)++;
	}
	else
		ft_put_explosion3(main, x, y, temp);
}

void	ft_put_explosion3(t_data *main, int x, int y, int *temp)
{
	if (main->map_array[y][x] == DOOR_OPEN && main->flag == 0
		&& main->for_ex % 20 == 15)
	{
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->explosion8.img_ptr_xpm, x * PIXELS, y * PIXELS + INFO_WIN);
		(*temp)++;
	}
	else if (main->map_array[y][x] == DOOR_OPEN && main->flag == 0
		&& main->for_ex % 20 == 17)
	{
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->explosion9.img_ptr_xpm, x * PIXELS, y * PIXELS + INFO_WIN);
		(*temp)++;
	}
}
