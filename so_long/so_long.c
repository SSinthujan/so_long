/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:56:11 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/02/22 19:11:33 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ta_mere_la_norminette(t_game *game)
{
	mlx_hook(game->mlx.win, 0, 1L << 0, key_hook, game);
	mlx_key_hook(game->mlx.win, key_hook, game);
	mlx_hook(game->mlx.win, 17, 0, mlx_loop_end, game->mlx.mlx);
}

int	quit(t_game *game)
{
	mlx_destroy_image(game->mlx.mlx, game->xpm.collectibles);
	mlx_destroy_image(game->mlx.mlx, game->xpm.player);
	mlx_destroy_image(game->mlx.mlx, game->xpm.exit);
	mlx_destroy_image(game->mlx.mlx, game->xpm.ground);
	mlx_destroy_image(game->mlx.mlx, game->xpm.wall);
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	mlx_destroy_display(game->mlx.mlx);
	free(game->mlx.mlx);
	free_tab(game->map);
	free_tab(game->copy_map);
	exit(0);
	return (0);
}

int	check_win(t_game *game)
{
	int	x;
	int	y;

	game->mlx.win = mlx_new_window(game->mlx.mlx, game->map_size.longueur * 40,
			game->map_size.largeur * 40, "so_long");
	if (!game->mlx.win)
		return (free(game->mlx.mlx), ft_printf("Error: MLX"), 1);
	mlx_get_screen_size(game->mlx.mlx, &x, &y);
	if (game->map_size.largeur * 40 > y || game->map_size.longueur * 40 > x)
	{
		free_tab(game->map);
		free_tab(game->copy_map);
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
		mlx_destroy_display(game->mlx.mlx);
		return (free(game->mlx.mlx),
			ft_printf("Error: Map bigger than screensize\n"), 1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_printf("Error: arguments\n"), 1);
	if (!check_ber(av[1]) && !check_all(&game, av))
	{
		game.count_move = 0;
		game.mlx.mlx = mlx_init();
		if (!game.mlx.mlx)
			return (ft_printf("Error: MLX"), 1);
		if (check_win(&game))
			return (1);
		if (check_xpm(&game, import_xpm(&game)))
		{
			mlx_destroy_window(game.mlx.mlx, game.mlx.win);
			mlx_destroy_display(game.mlx.mlx);
			return (free(game.mlx.mlx), 1);
		}
		put_img_screen(&game);
		ta_mere_la_norminette(&game);
		mlx_loop(game.mlx.mlx);
		quit(&game);
		return (1);
	}
	return (1);
}
