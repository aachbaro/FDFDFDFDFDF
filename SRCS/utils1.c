/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:45:01 by aachbaro          #+#    #+#             */
/*   Updated: 2021/09/24 17:18:27 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	count_nbr(char *line)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (line[i])
	{
		while ((ft_isdigit(line[i]) || line[i] == '-') && line[i])
			i++;
		while (line[i] == ' ' && line[i])
			i++;
		nbr++;
	}
	if (line[i - 1] == ' ')
		nbr--;
	return (nbr);
}

void	free_everything(t_mlxdt *data)
{
	int	i;

	i = 0;
	free(data->file);
	while (i < data->map.h)
		free(data->map.pts[i++]);
	free(data->map.pts);
	mlx_destroy_image(data->m_ptr, data->img.p_img);
	mlx_destroy_window(data->m_ptr, data->m_win);
	mlx_destroy_display(data->m_ptr);
	free(data->m_ptr);
}

void	init_back_black(t_mlxdt *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->screen_y)
	{
		j = 0;
		while (j < data->screen_x)
		{
			img_pix_put(&data->img, j, i, 0x00000000);
			j++;
		}
		i++;
	}
}

void	init_val(t_mlxdt *data)
{
	data->val.vect_x = 2;
	data->val.vect_y = 1;
	data->val.size = 1;
	data->val.init_x = data->screen_x / 2;
	data->val.init_y = data->screen_y / 5;
	data->val.color = 0x006F3F00;
	data->val.up = 0;
	data->val.down = 0;
	data->val.left = 0;
	data->val.right = 0;
	data->val.zoom = 0;
	data->val.unzoom = 0;
}

int	get_high(t_mlxdt data, int i, int j)
{
	int	ret;

	data.val.size *= 100;
	ret = data.val.size * data.map.pts[j][i];
	ret /= 1000;
	return (ret);
}
