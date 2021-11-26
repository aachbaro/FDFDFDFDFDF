/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:45:01 by aachbaro          #+#    #+#             */
/*   Updated: 2021/09/24 17:19:15 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	check_error(int ac, char **av)
{
	int	i;

	if (ac != 2)
	{
		printf("Wrong number of parameters\n");
		return (-1);
	}
	i = ft_strlen(av[1]) - 4;
	if (i <= 0 || ft_strncmp(av[1] + i, ".fdf", 4) != 0)
	{
		printf("Wrong file name\n");
		return (-1);
	}
	i = open(av[1], O_RDONLY);
	if (i == -1)
	{
		printf("%s cant be read\n", av[1]);
		return (-1);
	}
	close(i);
	return (0);
}

int	get_abs(t_mlxdt data, int x, int y)
{
	int	ret;

	ret = data.val.init_x + x * data.val.vect_x * data.val.size - y
		* data.val.vect_x * data.val.size;
	return (ret);
}

int	get_ord(t_mlxdt data, int x, int y)
{
	int	ret;

	ret = data.val.init_y + x * data.val.vect_y * data.val.size + y
		* data.val.vect_y * data.val.size;
	return (ret - get_high(data, x, y));
}

int	is_in(t_mlxdt data, int abs, int ord)
{
	int	x;
	int	y;

	x = get_abs(data, abs, ord);
	y = get_ord(data, abs, ord);
	if (x < 0 || y < 0)
		return (0);
	if (x > data.screen_x || y > data.screen_y)
		return (0);
	return (1);
}
