/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:27:25 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/02/11 19:08:55 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(int keycode, t_game *game)
{
	if (keycode == 119 || keycode == 65362)
	{
		if (game->map[game->coord.x - 1][game->coord.y] != '1')
		{
			if (game->map[game->coord.x - 1][game->coord.y] == 'C')
				game->count.count_c--;
			if (game->map[game->coord.x - 1][game->coord.y] != 'E')
			{
				game->map[game->coord.x--][game->coord.y] = '0';
				game->count_move++;
				ft_printf("Move count: %d\n", game->count_move);
			}
			if (game->map[game->coord.x - 1][game->coord.y] == 'E'
				&& !game->count.count_c)
			{
				game->count_move++;
				ft_printf("Move count: %d\n", game->count_move);
				mlx_loop_end(game->mlx.mlx);
				ft_printf("You have won\n");
			}
		}
		game->map[game->coord.x][game->coord.y] = 'P';
		put_img_screen(game);
	}
}

void	move_down(int keycode, t_game *game)
{
	if (keycode == 115 || keycode == 65364)
	{
		if (game->map[game->coord.x + 1][game->coord.y] != '1')
		{
			if (game->map[game->coord.x + 1][game->coord.y] == 'C')
				game->count.count_c--;
			if (game->map[game->coord.x + 1][game->coord.y] != 'E')
			{
				game->map[game->coord.x++][game->coord.y] = '0';
				game->count_move++;
				ft_printf("Move count: %d\n", game->count_move);
			}
			if (game->map[game->coord.x + 1][game->coord.y] == 'E'
				&& !game->count.count_c)
			{
				game->count_move++;
				ft_printf("Move count: %d\n", game->count_move);
				mlx_loop_end(game->mlx.mlx);
				ft_printf("You have won\n");
			}
		}
	}
	game->map[game->coord.x][game->coord.y] = 'P';
	put_img_screen(game);
}

void	move_left(int keycode, t_game *game)
{
	if (keycode == 97 || keycode == 65361)
	{
		if (game->map[game->coord.x][game->coord.y - 1] != '1')
		{
			if (game->map[game->coord.x][game->coord.y - 1] == 'C')
				game->count.count_c--;
			if (game->map[game->coord.x][game->coord.y - 1] != 'E')
			{
				game->map[game->coord.x][game->coord.y--] = '0';
				game->count_move++;
				ft_printf("Move count: %d\n", game->count_move);
			}
			if (game->map[game->coord.x][game->coord.y - 1] == 'E'
				&& !game->count.count_c)
			{
				game->count_move++;
				ft_printf("Move count: %d\n", game->count_move);
				mlx_loop_end(game->mlx.mlx);
				ft_printf("You have won\n");
			}
		}
	}
	game->map[game->coord.x][game->coord.y] = 'P';
	put_img_screen(game);
}

void	move_right(int keycode, t_game *game)
{
	if (keycode == 100 || keycode == 65363)
	{
		if (game->map[game->coord.x][game->coord.y + 1] != '1')
		{
			if (game->map[game->coord.x][game->coord.y + 1] == 'C')
				game->count.count_c--;
			if (game->map[game->coord.x][game->coord.y + 1] != 'E')
			{
				game->map[game->coord.x][game->coord.y++] = '0';
				game->count_move++;
				ft_printf("Move count: %d\n", game->count_move);
			}
			if (game->map[game->coord.x][game->coord.y + 1] == 'E'
				&& !game->count.count_c)
			{
				game->count_move++;
				ft_printf("Move count: %d\n", game->count_move);
				mlx_loop_end(game->mlx.mlx);
				ft_printf("You have won\n");
			}
		}
	}
	game->map[game->coord.x][game->coord.y] = 'P';
	put_img_screen(game);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		return (mlx_loop_end(game->mlx.mlx), 0);
	else if (keycode == 115 || keycode == 65364)
		move_down(keycode, game);
	else if (keycode == 119 || keycode == 65362)
		move_up(keycode, game);
	else if (keycode == 97 || keycode == 65361)
		move_left(keycode, game);
	else if (keycode == 100 || keycode == 65363)
		move_right(keycode, game);
	return (0);
}
