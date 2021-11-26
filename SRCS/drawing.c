/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:41:11 by aachbaro          #+#    #+#             */
/*   Updated: 2021/08/31 16:41:32 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x < img->size_x && x > 0 && y > 0 && y < img->size_y)
	{
		i = img->bpp - 8;
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		while (i >= 0)
		{
			if (img->endian != 0)
				*pixel++ = (color >> i) & 0xFF;
			else
				*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
			i -= 8;
		}
	}
}

void	line_exissup(t_img *img, t_line line, int color)
{
	int	i;

	i = 0;
	while (i <= line.stable_ex)
	{
		img_pix_put(img, line.x1, line.y1, color);
		i++;
		line.x1 += line.incr_x;
		line.ex -= line.dir_y;
		if (line.ex < 0)
		{
			line.y1 += line.incr_y;
			line.ex += line.dir_x;
		}
	}
}

void	line_eyissup(t_img *img, t_line line, int color)
{
	int	i;

	i = 0;
	while (i <= line.stable_ey)
	{
		img_pix_put(img, line.x1, line.y1, color);
		i++;
		line.y1 += line.incr_y;
		line.ey -= line.dir_x;
		if (line.ey < 0)
		{
			line.x1 += line.incr_x;
			line.ey += line.dir_y;
		}
	}
}

void	draw_line(t_img *img, t_line *line, int color)
{
	line->ex = abs(line->x2 - line->x1);
	line->ey = abs(line->y2 - line->y1);
	line->dir_x = 2 * line->ex;
	line->dir_y = 2 * line->ey;
	line->stable_ex = line->ex;
	line->stable_ey = line->ey;
	line->incr_x = 1;
	line->incr_y = 1;
	if (line->x1 > line->x2)
		line->incr_x = -1;
	if (line->y1 > line->y2)
		line->incr_y = -1;
	if (line->stable_ex > line->stable_ey)
		line_exissup(img, *line, color);
	else
		line_eyissup(img, *line, color);
}
