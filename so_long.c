/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdominqu <sdominqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:59:47 by sdominqu          #+#    #+#             */
/*   Updated: 2021/07/27 18:59:49 by sdominqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*main;

	main = ft_creat_struct();
	if (argc != 2)
	{
		printf("Error: ./so_long <filename>\n");
		return (0);
	}
	main->map_array = init_map_array(argv[1], main);
	if (!main->map_array)
	{
		printf("Error: Bad map!\n");
		return (0);
	}
	ft_start_game(main);
	ft_free_all(main);
}

void	ft_start_game(t_data *main)
{
	main->mlx = mlx_init();
	ft_creat_xpm_img(main);
	ft_init_cop_position(main);
	main->hero_xpm = main->hero1_xpm;
	main->cop_xpm = main->cop1_xpm;
	main->mlx_win = mlx_new_window(main->mlx, main->sizemap->width * PIXELS,
			main->sizemap->height * PIXELS + INFO_WIN, "SO LONG");
	main->img = mlx_new_image(main->mlx,
			main->sizemap->width * PIXELS, INFO_WIN);
	main->addr = (int *) mlx_get_data_addr(main->img, &main->bits_per_pixel,
			&main->line_length, &main->endian);
	mlx_hook(main->mlx_win, 2, 1L << 0, ft_key_handler, main);
	mlx_hook(main->mlx_win, 17, 1L << 17, ft_mlx_close, main);
	mlx_loop_hook(main->mlx, ft_game, main);
	mlx_loop(main->mlx);
}

int	ft_mlx_close(t_data *main)
{
	mlx_destroy_window(main->mlx, main->mlx_win);
	ft_free_all(main);
	exit(0);
}

int	ft_game(t_data *main)
{
	int	i;
	int	k;

	i = 0;
	if (main->coins == 0 && main->flag == 1)
		main->flag = 0;
	while (i < main->sizemap->height)
	{
		k = 0;
		while (k < main->sizemap->width)
		{
			ft_put_img_main(main, k, i);
			k++;
		}
		i++;
	}
	if (main->coins == 0)
		ft_open_doors(main);
	main->time++;
	main->for_ex++;
	ft_put_string(main);
	ft_chek_all_cops_position(main);
	return (0);
}

int	ft_open_doors(t_data *main)
{
	int	i;
	int	k;

	i = 1;
	while (i < main->sizemap->height - 1)
	{
		k = 1;
		while (k < main->sizemap->width - 1)
		{
			if (main->map_array[i][k] == DOOR_CLOSE)
				main->map_array[i][k] = DOOR_OPEN;
			k++;
		}
		i++;
	}
	return (0);
}
