/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:18:28 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/02/21 21:20:36 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	import_xpm(t_game *game)
// {
// 	int		i;
// 	int		j;
// 	void	*tab[5];

// 	static char *path[5] = {
// 		"assets/player.xpm",
// 		"assets/exit.xpm",
// 		"assets/collectibles.xpm",
// 		"assets/wall.xpm",
// 		"assets/ground.xpm",
// 	};
// 	while (i < 5)
// 		tab[i++] = mlx_xpm_file_to_image(game->mlx.mlx, path[i], &j, &j);
// }

int	import_xpm(t_game *game)
{
	int	i;
	int	j;

	game->xpm.player = mlx_xpm_file_to_image(game->mlx.mlx, "assets/player.xpm",
			&i, &j);
	game->xpm.exit = mlx_xpm_file_to_image(game->mlx.mlx, "assets/exit.xpm", &i,
			&j);
	game->xpm.collectibles = mlx_xpm_file_to_image(game->mlx.mlx,
			"assets/collectibles.xpm", &i, &j);
	game->xpm.wall = mlx_xpm_file_to_image(game->mlx.mlx, "assets/wall.xpm", &i,
			&j);
	game->xpm.ground = mlx_xpm_file_to_image(game->mlx.mlx, "assets/ground.xpm",
			&i, &j);
	return (!game->xpm.player || !game->xpm.exit || !game->xpm.collectibles
		|| !game->xpm.wall || !game->xpm.ground);
}

int	check_xpm(t_game *game, int i)
{
	(void)i;
	if (!i)
		return (0);
	if (game->xpm.player)
		mlx_destroy_image(game->mlx.mlx, game->xpm.player);
	if (game->xpm.exit)
		mlx_destroy_image(game->mlx.mlx, game->xpm.exit);
	if (game->xpm.collectibles)
		mlx_destroy_image(game->mlx.mlx, game->xpm.collectibles);
	if (game->xpm.ground)
		mlx_destroy_image(game->mlx.mlx, game->xpm.ground);
	if (game->xpm.wall)
		mlx_destroy_image(game->mlx.mlx, game->xpm.wall);
	free_tab(game->map);
	free_tab(game->copy_map);
	return (ft_printf("Error: XPM\n"), 1);
}

void	put_img_window(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->xpm.ground,
			x * 40, y * 40);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->xpm.wall, x
			* 40, y * 40);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->xpm.collectibles, x * 40, y * 40);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->xpm.exit, x
			* 40, y * 40);
}

void	put_img_screen(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
			put_img_window(game, y++, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->xpm.player,
		game->coord.y * 40, game->coord.x * 40);
}
