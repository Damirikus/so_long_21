/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_map_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdominqu <sdominqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:58:12 by sdominqu          #+#    #+#             */
/*   Updated: 2021/07/27 18:58:14 by sdominqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_check_map_array(t_data *main)
{
	int	i;
	int	k;
	int	one_zero;

	one_zero = 0;
	if (ft_check_map_array2(main) == NULL)
		return (NULL);
	i = 1;
	while (i < main->sizemap->height - 1)
	{
		if (main->map_array[i][0] != '1' ||
			main->map_array[i][main->sizemap->width - 1] != '1')
			return (NULL);
		k = 1;
		while (k < main->sizemap->width - 1)
		{
			if (ft_check_map_array1(main, i, k, &one_zero) == NULL)
				return (NULL);
			k++;
		}
		i++;
	}
	if (main->coins == 0 || main->start_position != 1 || main->exit_game == 0)
		return (NULL);
	return (main->map_array);
}

char	*ft_check_map_array1(t_data *main, int i, int k, int *one_zero)
{
	if (main->map_array[i][k] == 'C')
		main->coins++;
	else if (main->map_array[i][k] == 'P')
	{
		main->position_hero->x_pos_hero = i;
		main->position_hero->y_pos_hero = k;
		main->start_position++;
	}
	else if (main->map_array[i][k] == 'E')
		main->exit_game++;
	else if (main->map_array[i][k] == '1' ||
			 main->map_array[i][k] == '0')
		(*one_zero)++;
	else
		return (NULL);
	return ("OK");
}

char	*ft_check_map_array2(t_data *main)
{
	int	i;

	i = 0;
	while (i < main->sizemap->width)
	{
		if (main->map_array[0][i] != '1' ||
			main->map_array[main->sizemap->height - 1][i] != '1')
			return (NULL);
		i++;
	}
	return ("OK");
}
