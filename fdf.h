/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:50:39 by aachbaro          #+#    #+#             */
/*   Updated: 2021/09/24 17:21:27 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "LIBFT/libft.h"
# include "MLX/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# define K_ESCAPE 65307
# define K_UP 119
# define K_LEFT 97
# define K_DOWN 115
# define K_RIGHT 100
# define K_ZOOM 65362
# define K_UNZOOM 65364

typedef struct s_img
{
	void	*p_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		size_x;
	int		size_y;
}		t_img;

typedef struct s_map
{
	int	**pts;
	int	w;
	int	h;
}		t_map;

typedef struct s_line
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	ex;
	int	ey;
	int	dir_x;
	int	dir_y;
	int	stable_ex;
	int	stable_ey;
	int	incr_x;
	int	incr_y;
}		t_line;

typedef struct s_grid
{
	int	vect_x;
	int	vect_y;
	int	size;
	int	init_x;
	int	init_y;
	int	color;
	int	up;
	int	left;
	int	down;
	int	right;
	int	zoom;
	int	unzoom;
}		t_grid;

typedef struct s_mlxdt
{
	void	*m_ptr;
	void	*m_win;
	int		fd;
	char	*file;
	t_img	img;
	t_map	map;
	t_line	line;
	t_grid	val;
	int		screen_x;
	int		screen_y;
}		t_mlxdt;

void	img_pix_put(t_img *img, int x, int y, int color);
void	line_exissup(t_img *img, t_line line, int color);
void	line_eyissup(t_img *img, t_line line, int color);
void	draw_line(t_img *img, t_line *line, int color);
int		count_nbr(char *line);
void	get_map_size(t_mlxdt *data, char *line);
int		mall_ptstab(t_mlxdt *data);
int		get_map(t_mlxdt *data);
int		window(t_mlxdt *data);
void	init_back_black(t_mlxdt *data);
void	set_points(t_mlxdt *data);
void	draw_grid(t_mlxdt *data);
void	free_everything(t_mlxdt *data);
void	init_val(t_mlxdt *data);
int		key_press(int keysym, t_mlxdt *data);
int		key_release(int keysym, t_mlxdt *data);
void	move(t_mlxdt *data);
int		get_high(t_mlxdt data, int i, int j);
int		check_error(int ac, char **av);
int		get_abs(t_mlxdt data, int x, int y);
int		get_ord(t_mlxdt data, int x, int y);
int		is_in(t_mlxdt data, int abs, int ord);

#endif
