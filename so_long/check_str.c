/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:15:33 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/02/10 06:32:10 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_double(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (ft_printf("Error: Double line break\n"), 1);
		i++;
	}
	return (0);
}

int	check_char(t_game *game, char *str)
{
	int	i;

	i = 0;
	game->count.count_p = 0;
	game->count.count_e = 0;
	game->count.count_c = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			game->count.count_p++;
		else if (str[i] == 'E')
			game->count.count_e++;
		else if (str[i] == 'C')
			game->count.count_c++;
		else if (str[i] != '0' && str[i] != '1' && str[i] != '\n')
			return (ft_printf("Error: Undesired char\n"), 1);
		i++;
	}
	if (game->count.count_p == 1 && game->count.count_e == 1
		&& game->count.count_c > 0)
		return (0);
	return (ft_printf("Error: Missing char or more char than expected\n"), 1);
}
