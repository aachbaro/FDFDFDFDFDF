/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:33:19 by aachbaro          #+#    #+#             */
/*   Updated: 2021/08/31 16:47:35 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	render(t_mlxdt *data)
{
	draw_grid(data);
	mlx_put_image_to_window(data->m_ptr, data->m_win, data->img.p_img, 0, 0);
	return (0);
}

int	window(t_mlxdt *data)
{
	data->m_ptr = mlx_init();
	mlx_get_screen_size(data->m_ptr, &data->screen_x, &data->screen_y);
	data->m_win = mlx_new_window(data->m_ptr, data->screen_x, data->screen_y,
			"FdF");
	data->img.p_img = mlx_new_image(data->m_ptr, data->screen_x,
			data->screen_y);
	data->img.addr = mlx_get_data_addr(data->img.p_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	data->img.size_x = data->screen_x;
	data->img.size_y = data->screen_y;
	init_val(data);
	mlx_hook(data->m_win, 2, (1L << 0), &key_press, data);
	mlx_hook(data->m_win, 3, (1L << 1), &key_release, data);
	mlx_loop_hook(data->m_ptr, &render, data);
	mlx_loop(data->m_ptr);
	return (0);
}
