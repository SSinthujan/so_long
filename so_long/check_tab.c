/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 07:15:39 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/02/11 18:51:13 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(t_game *game)
{
	size_t	longueur;
	int		i;

	i = 0;
	longueur = ft_strlen(game->map[i]);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != longueur)
		{
			return (ft_printf("Error: Map not a rectangle\n"), 1);
		}
		i++;
	}
	game->map_size.largeur = i;
	game->map_size.longueur = longueur;
	return (0);
}

int	check_border(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_size.largeur)
	{
		x = 0;
		while (x < game->map_size.longueur)
		{
			if (y == 0 || y == game->map_size.largeur - 1)
			{
				if (game->map[y][x] != '1')
					return (ft_printf("Error: Map border\n"), 1);
			}
			else if (x == 0 || x == game->map_size.longueur - 1)
				if (game->map[y][x] != '1')
					return (ft_printf("Error: Map border\n"), 1);
			x++;
		}
		y++;
	}
	return (0);
}

int	flood_fill(t_game *game)
{
	take_pos(game);
	fill(game, game->coord.x, game->coord.y);
	if (!check_flood_fill(game->copy_map))
		return (0);
	return (ft_printf("Error: Map unwinnable\n"), 1);
}
