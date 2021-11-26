/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:42:26 by aachbaro          #+#    #+#             */
/*   Updated: 2021/08/31 16:42:41 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int ac, char **av)
{
	t_mlxdt	data;

	if (check_error(ac, av) == -1)
		return (-1);
	data.file = ft_strdup(av[ac - 1]);
	get_map(&data);
	window(&data);
	return (0);
}
