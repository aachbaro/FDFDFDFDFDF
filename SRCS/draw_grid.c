/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:37:56 by aachbaro          #+#    #+#             */
/*   Updated: 2021/09/24 17:17:30 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_lines(t_mlxdt *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->map.h)
	{
		i = 0;
		while (i < data->map.w - 1)
		{
			if (is_in(*data, i, j) || is_in(*data, i + 1, j))
			{
				data->line.x1 = get_abs(*data, i, j);
				data->line.x2 = get_abs(*data, i + 1, j);
				data->line.y1 = get_ord(*data, i, j);
				data->line.y2 = get_ord(*data, i + 1, j);
				draw_line(&data->img, &data->line,
					data->val.color);
			}
			i++;
		}
		j++;
	}
}

void	draw_column(t_mlxdt *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.w)
	{
		j = 0;
		while (j < data->map.h - 1)
		{
			if (is_in(*data, i, j) || is_in(*data, i, j + 1))
			{
				data->line.x1 = get_abs(*data, i, j);
				data->line.x2 = get_abs(*data, i, j + 1);
				data->line.y1 = get_ord(*data, i, j);
				data->line.y2 = get_ord(*data, i, j + 1);
				draw_line(&data->img, &data->line,
					data->val.color);
			}
			j++;
		}
		i++;
	}
}

void	draw_grid(t_mlxdt *data)
{
	move(data);
	init_back_black(data);
	draw_lines(data);
	draw_column(data);
}
