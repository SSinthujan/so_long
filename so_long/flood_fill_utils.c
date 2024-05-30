/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:42:31 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/02/10 08:01:20 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	take_pos(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'P')
			{
				game->coord.x = x;
				game->coord.y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	fill(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map_size.largeur || y < 0
		|| y >= game->map_size.longueur || game->copy_map[x][y] == '1')
		return ;
	if (game->copy_map[x][y] == 'E')
	{
		game->copy_map[x][y] = '1';
		return ;
	}
	game->copy_map[x][y] = '1';
	fill(game, x - 1, y);
	fill(game, x + 1, y);
	fill(game, x, y - 1);
	fill(game, x, y + 1);
}

int	check_flood_fill(char **copy_map)
{
	int	x;
	int	y;

	x = 0;
	while (copy_map[x])
	{
		y = 0;
		while (copy_map[x][y])
		{
			if (copy_map[x][y] != '1' && copy_map[x][y] != '0')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}
