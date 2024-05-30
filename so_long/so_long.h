/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:23:28 by ssitchsa          #+#    #+#             */
/*   Updated: 2024/02/11 03:35:20 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "libft/printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <fcntl.h>

typedef struct s_count
{
	int			count_p;
	int			count_e;
	int			count_c;
}				t_count;

typedef struct s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct s_map_size
{
	int			longueur;
	int			largeur;
}				t_map_size;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct s_xpm
{
	void		*player;
	void		*exit;
	void		*collectibles;
	void		*wall;
	void		*ground;
}				t_xpm;

typedef struct s_game
{
	char		**map;
	char		**copy_map;
	t_count		count;
	int			count_move;
	t_map_size	map_size;
	t_coord		coord;
	t_mlx		mlx;
	t_xpm		xpm;
}				t_game;

int				ft_strcmp(const char *s1, const char *s2);
int				check_ber(char *mapname);
int				check_double(char *str);
int				check_char(t_game *game, char *str);
int				str_to_tab(t_game *game, char *str);
int				check_rectangle(t_game *game);
void			free_tab(char **tab);
void			take_pos(t_game *game);
int				flood_fill(t_game *game);
void			display_tab(char **tab);
void			fill(t_game *game, int x, int y);
int				check_flood_fill(char **copy_map);
int				check_border(t_game *game);
int				check_all(t_game *game, char **av);
int				import_xpm(t_game *game);
int				check_xpm(t_game *game, int i);
void			put_img_window(t_game *game, int x, int y);
void			put_img_screen(t_game *game);
int				key_hook(int keycode, t_game *game);

#endif