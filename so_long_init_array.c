/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdominqu <sdominqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:59:41 by sdominqu          #+#    #+#             */
/*   Updated: 2021/07/27 19:23:29 by sdominqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**init_map_array(char *filename, t_data *main)
{
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	i = ft_qw_line(main, fd);
	close(fd);
	main->sizemap->height = i;
	main->map_array = malloc(sizeof(char *) * (main->sizemap->height + 1));
	main->map_array[i] = 0;
	i = 0;
	while (i < main->sizemap->height)
	{
		main->map_array[i] = malloc(main->sizemap->width + 1);
		main->map_array[i][main->sizemap->width] = '\0';
		i++;
	}
	main->map_array = ft_filing_map_array(filename, main);
	if (main->sizemap->height < 3 || main->sizemap->width < 5)
		return (NULL);
	return (main->map_array);
}

int	ft_qw_line(t_data *main, int fd)
{
	int		i;
	char	*str;

	i = 0;
	while (get_next_line(fd, &str))
	{
		main->sizemap->width = ft_strlen(str);
		free(str);
		i++;
	}
	free(str);
	return (i);
}

char	**ft_filing_map_array(char *filename, t_data *main)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < main->sizemap->height)
	{
		get_next_line(fd, &str);
		if (ft_strlen(str) != main->sizemap->width)
			return (NULL);
		ft_strlcpy(main->map_array[i], str, main->sizemap->width + 1);
		free(str);
		i++;
	}
	close(fd);
	main->map_array = ft_check_map_array(main);
	return (main->map_array);
}
