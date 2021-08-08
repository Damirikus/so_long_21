/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdominqu <sdominqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:58:21 by sdominqu          #+#    #+#             */
/*   Updated: 2021/07/27 18:58:23 by sdominqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_creat_xpm_img(t_data *main)
{
	ft_creat_xpm_img1(main);
	ft_creat_xpm_img2(main);
	main->explosion5.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/explosion/explosion5.xpm",
			&main->explosion5.width_img, &main->explosion5.height_img);
	main->explosion6.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/explosion/explosion6.xpm",
			&main->explosion6.width_img, &main->explosion6.height_img);
	main->explosion7.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/explosion/explosion7.xpm",
			&main->explosion7.width_img, &main->explosion7.height_img);
	main->explosion8.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/explosion/explosion8.xpm",
			 &main->explosion8.width_img, &main->explosion8.height_img);
	main->explosion9.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/explosion/explosion9.xpm",
			 &main->explosion9.width_img, &main->explosion9.height_img);
}

void	ft_creat_xpm_img1(t_data *main)
{
	main->wall_xpm.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/wall.xpm", &main->wall_xpm.width_img,
			&main->wall_xpm.height_img);
	main->empty_xpm.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/empty.xpm", &main->empty_xpm.width_img,
			&main->empty_xpm.height_img);
	main->door_close_xpm.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/door_close.xpm", &main->door_close_xpm.width_img,
			&main->door_close_xpm.height_img);
	main->door_open_xpm.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/door_open.xpm", &main->door_open_xpm.width_img,
			&main->door_open_xpm.height_img);
	main->hero1_xpm.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/mouse1.xpm", &main->hero1_xpm.width_img,
			&main->hero1_xpm.height_img);
	main->hero2_xpm.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/mouse2.xpm", &main->hero2_xpm.width_img,
			&main->hero2_xpm.height_img);
	main->coin_xpm.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/coin.xpm", &main->coin_xpm.width_img,
			&main->coin_xpm.height_img);
	main->cop1_xpm.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/cat1.xpm", &main->cop1_xpm.width_img,
			&main->cop1_xpm.height_img);
}

void	ft_creat_xpm_img2(t_data *main)
{
	main->cop2_xpm.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/cat2.xpm", &main->cop2_xpm.width_img,
			&main->cop2_xpm.height_img);
	main->dead_xpm.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/rip.xpm", &main->dead_xpm.width_img,
			&main->dead_xpm.height_img);
	main->explosion1.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/explosion/explosion1.xpm",
			&main->explosion1.width_img, &main->explosion1.height_img);
	main->explosion2.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/explosion/explosion2.xpm",
			&main->explosion2.width_img, &main->explosion2.height_img);
	main->explosion3.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/explosion/explosion3.xpm",
			 &main->explosion3.width_img, &main->explosion3.height_img);
	main->explosion4.img_ptr_xpm = mlx_xpm_file_to_image(main->mlx,
			"./xpm/explosion/explosion4.xpm",
			&main->explosion4.width_img, &main->explosion4.height_img);
}
