/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdominqu <sdominqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:59:34 by sdominqu          #+#    #+#             */
/*   Updated: 2021/07/27 18:59:35 by sdominqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img_main(t_data *main, int x, int y)
{
	ft_put_img_main1(main, x, y);
	ft_put_img_main2(main, x, y);
	if (main->map_array[y][x] == COP_ON_COIN)
	{
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->coin_xpm.img_ptr_xpm, x * PIXELS,
			y * PIXELS + INFO_WIN);
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->cop_xpm.img_ptr_xpm, x * PIXELS,
			y * PIXELS + INFO_WIN);
	}
	if (main->map_array[y][x] == COP_ON_DOOR)
	{
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->door_close_xpm.img_ptr_xpm, x * PIXELS,
			y * PIXELS + INFO_WIN);
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->cop_xpm.img_ptr_xpm, x * PIXELS,
			y * PIXELS + INFO_WIN);
	}
	ft_put_img_main3(main, x, y);
}

void	ft_put_img_main1(t_data *main, int x, int y)
{
	mlx_put_image_to_window(main->mlx, main->mlx_win,
		main->empty_xpm.img_ptr_xpm, x * PIXELS, y * PIXELS + INFO_WIN);
	if (main->map_array[y][x] == WALL)
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->wall_xpm.img_ptr_xpm, x * PIXELS, y * PIXELS + INFO_WIN);
	if (main->map_array[y][x] == DOOR_CLOSE)
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->door_close_xpm.img_ptr_xpm, x * PIXELS,
			y * PIXELS + INFO_WIN);
	if (main->map_array[y][x] == DOOR_OPEN)
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->door_open_xpm.img_ptr_xpm, x * PIXELS, y * PIXELS + INFO_WIN);
	if (main->map_array[y][x] == HERO)
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->hero_xpm.img_ptr_xpm, x * PIXELS, y * PIXELS + INFO_WIN);
	if (main->map_array[y][x] == COIN)
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->coin_xpm.img_ptr_xpm, x * PIXELS, y * PIXELS + INFO_WIN);
}

void	ft_put_img_main2(t_data *main, int x, int y)
{
	if (main->map_array[y][x] == HERO_ON_DOOR)
	{
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->door_close_xpm.img_ptr_xpm, x * PIXELS,
			y * PIXELS + INFO_WIN);
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->hero_xpm.img_ptr_xpm, x * PIXELS, y * PIXELS + INFO_WIN);
	}
	mlx_put_image_to_window(main->mlx, main->mlx_win, main->img, 0, 0);
	if (main->map_array[y][x] == COP)
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->cop_xpm.img_ptr_xpm, x * PIXELS,
			y * PIXELS + INFO_WIN);
	if (main->map_array[y][x] == DEAD)
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->dead_xpm.img_ptr_xpm, x * PIXELS,
			y * PIXELS + INFO_WIN);
}

void	ft_put_img_main3(t_data *main, int x, int y)
{
	if (main->map_array[y][x] == COP_ON_DOOR_O)
	{
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->door_open_xpm.img_ptr_xpm, x * PIXELS,
			y * PIXELS + INFO_WIN);
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->cop_xpm.img_ptr_xpm, x * PIXELS,
			y * PIXELS + INFO_WIN);
	}
	if (main->map_array[y][x] == COP_ON_DEAD)
	{
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->dead_xpm.img_ptr_xpm, x * PIXELS,
			y * PIXELS + INFO_WIN);
		mlx_put_image_to_window(main->mlx, main->mlx_win,
			main->cop_xpm.img_ptr_xpm, x * PIXELS,
			y * PIXELS + INFO_WIN);
	}
	if (main->coins == 0)
		ft_put_explosion(main, x, y);
}
