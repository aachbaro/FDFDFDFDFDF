/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:43:04 by aachbaro          #+#    #+#             */
/*   Updated: 2021/09/24 17:18:06 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	get_map_size(t_mlxdt *data, char *line)
{
	char	**tab;
	int		i;

	i = 0;
	get_next_line(data->fd, &line);
	tab = ft_split(line, ' ');
	while (tab[i])
		free(tab[i++]);
	free(line);
	free(tab);
	data->map.w = i;
	data->map.h = 1;
	while (get_next_line(data->fd, &line))
	{
		data->map.h++;
		free(line);
	}
	if (line)
		free(line);
}

int	mall_ptstab(t_mlxdt *data)
{
	int	i;

	i = 0;
	data->map.pts = malloc(sizeof(int *) * data->map.h);
	if (!data->map.pts)
		return (-1);
	while (i < data->map.h)
	{
		data->map.pts[i] = malloc(sizeof(int) * data->map.w);
		if (!data->map.pts[i])
			return (-1);
		i++;
	}
	return (0);
}

void	fill_tab(t_mlxdt *data, char *line)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	while (i < data->map.h)
	{
		get_next_line(data->fd, &line);
		tab = ft_split(line, ' ');
		j = 0;
		while (tab[j])
		{
			data->map.pts[i][j] = ft_atoi(tab[j]);
			j++;
		}
		j = 0;
		while (tab[j])
			free(tab[j++]);
		free(tab);
		free(line);
		i++;
	}
}

int	get_map(t_mlxdt *data)
{
	char	*line;

	line = NULL;
	data->fd = open(data->file, O_RDONLY);
	get_map_size(data, line);
	mall_ptstab(data);
	close(data->fd);
	data->fd = open(data->file, O_RDONLY);
	fill_tab(data, line);
	close(data->fd);
	return (0);
}
