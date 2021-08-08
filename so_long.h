/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdominqu <sdominqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:59:55 by sdominqu          #+#    #+#             */
/*   Updated: 2021/07/27 19:04:48 by sdominqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>

# define PIXELS 64
# define INFO_WIN 32
# define WALL '1'
# define EMPTY '0'
# define DOOR_CLOSE 'E'
# define DOOR_OPEN 'O'
# define HERO 'P'
# define COIN 'C'
# define HERO_ON_DOOR 'D'
# define COP 'X'
# define COP_ON_DOOR 'Y'
# define COP_ON_DOOR_O 'A'
# define COP_ON_COIN 'Z'
# define DEAD 'R'
# define COP_ON_DEAD 'B'

typedef struct s_xpm
{
	void	*img_ptr_xpm;
	int		width_img;
	int		height_img;
}			t_xpm;

typedef struct s_size_map
{
	int	width;
	int	height;
}		t_size_map;

typedef struct s_position_hero
{
	int	x_pos_hero;
	int	y_pos_hero;
}		t_position_hero;

typedef struct s_xy
{
	int	x;
	int	y;
}		t_xy;

typedef struct s_data
{
	void			*img;
	void			*mlx;
	void			*mlx_win;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;

	t_size_map		*sizemap;
	t_position_hero	*position_hero;
	t_position_hero	*cop_position;
	char			**map_array;

	int				flag;
	int				score;
	int				steps;
	int				coins;
	int				start_position;
	int				exit_game;

	t_xpm			dragon;
	t_xpm			wall_xpm;
	t_xpm			empty_xpm;
	t_xpm			door_close_xpm;
	t_xpm			door_open_xpm;
	t_xpm			hero_xpm;
	t_xpm			hero1_xpm;
	t_xpm			hero2_xpm;
	t_xpm			coin_xpm;
	t_xpm			explosion1;
	t_xpm			explosion2;
	t_xpm			explosion3;
	t_xpm			explosion4;
	t_xpm			explosion5;
	t_xpm			explosion6;
	t_xpm			explosion7;
	t_xpm			explosion8;
	t_xpm			explosion9;
	t_xpm			cop_xpm;
	t_xpm			cop1_xpm;
	t_xpm			cop2_xpm;
	t_xpm			dead_xpm;
	long			time;
	long			for_ex;
}					t_data;

void	ft_move_cop_helper(t_data *main, t_xy *xy, char a, char b);
void	ft_move_hero_helper(t_data *main, t_xy *xy, char a, char b);
int		ft_key_handler(int key, t_data *main);
void	ft_start_game(t_data *main);
t_data	*ft_creat_struct(void);
char	**init_map_array(char *filename, t_data *main);
char	**ft_filing_map_array(char *filename, t_data *main);
void	ft_free_all(t_data *main);
char	**ft_check_map_array(t_data *main);
void	ft_creat_xpm_img(t_data *main);
int		ft_game(t_data *main);
void	ft_put_img_main(t_data *main, int x, int y);
int		ft_move_up(t_data *main);
int		ft_move_down(t_data *main);
int		ft_move_right(t_data *main);
int		ft_move_left(t_data *main);
int		ft_open_doors(t_data *main);
int		ft_moves(t_data *main, int x, int y);
void	ft_put_string(t_data *main);
void	ft_put_explosion(t_data *main, int x, int y);
void	ft_init_cop_position(t_data *main);
int		ft_mlx_close(t_data *main);
int		ft_move_cop_realization(t_data *main, int x, int y);
void	ft_move_cops(t_data *main);
void	ft_chek_all_cops_position(t_data *main);
void	ft_qw_cops(t_data *main, int *cops, int i, int k);
void	ft_move_cop_realization1(t_data *main, t_xy *xy);
void	ft_move_cop_realization2(t_data *main, t_xy *xy);
void	ft_move_cop_realization3(t_data *main, t_xy *xy);
void	ft_move_cop_realization4(t_data *main, t_xy *xy);
void	ft_move_cop_realization5(t_data *main, t_xy *xy);
void	ft_creat_xpm_img1(t_data *main);
void	ft_creat_xpm_img2(t_data *main);
void	ft_put_img_main1(t_data *main, int x, int y);
void	ft_put_img_main2(t_data *main, int x, int y);
void	ft_put_img_main3(t_data *main, int x, int y);
void	ft_put_explosion1(t_data *main, int x, int y, int *temp);
void	ft_put_explosion2(t_data *main, int x, int y, int *temp);
void	ft_put_explosion3(t_data *main, int x, int y, int *temp);
int		ft_qw_line(t_data *main, int fd);
char	*ft_check_map_array1(t_data *main, int i, int k, int *one_zero);
char	*ft_check_map_array2(t_data *main);
void	ft_moves1(t_data *main, t_xy *xy);
void	ft_moves2(t_data *main, t_xy *xy);
#endif