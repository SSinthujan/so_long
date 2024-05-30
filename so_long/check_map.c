/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:29:02 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/02/10 08:00:11 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *mapname)
{
	int	c;

	c = ft_strcmp(ft_strchr(mapname, '.'), ".ber");
	if (c)
	{
		ft_printf("Error: Map name\n");
		return (c);
	}
	return (0);
}

char	*map_to_str(char *map)
{
	int		fd;
	char	*str;
	char	*line;

	str = NULL;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error: Map inexistante\n"), NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		str = ft_strjoin(str, line);
		free(line);
	}
	close(fd);
	return (str);
}

int	str_to_tab(t_game *game, char *str)
{
	game->map = ft_split(str, '\n');
	if (!game->map)
	{
		free(str);
		return (ft_printf("Error: String to array\n"), 1);
	}
	game->copy_map = ft_split(str, '\n');
	if (!game->copy_map)
	{
		free(str);
		free_tab(game->map);
		return (ft_printf("Error: String to array copy\n"), 1);
	}
	free(str);
	return (0);
}

int	check_all(t_game *game, char **av)
{
	char	*str;

	str = map_to_str(av[1]);
	if (!str)
		return (1);
	if (check_double(str))
		return (free(str), 1);
	if (check_char(game, str))
		return (free(str), 1);
	str_to_tab(game, str);
	if (check_rectangle(game))
		return (free_tab(game->copy_map), free_tab(game->map), 1);
	if (check_border(game))
		return (free_tab(game->copy_map), free_tab(game->map), 1);
	if (flood_fill(game))
		return (free_tab(game->copy_map), free_tab(game->map), 1);
	return (0);
}
