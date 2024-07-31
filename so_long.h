/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:54:07 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/31 22:17:26 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"

# ifndef TILESIZE
#  define TILESIZE 60
# endif

typedef struct s_assets
{
	mlx_image_t	*hut;
	mlx_image_t	*lumberjack;
	mlx_image_t	*wall;
	mlx_image_t	*tree;
	mlx_image_t	*terrain;
}				t_assets;

typedef struct s_game
{
	mlx_t		*mlx;
	t_assets	assets;
	int			mapheight;
	int			mapwidth;
	int			posx;
	int			posy;
	char		**map;
	int			movecount;
	int			status;
	int			coll;
}				t_game;

typedef enum e_state
{
	INIT = 0,
	INGAME = 1,
	END = 2,
}				t_state;

void			move_up(t_game *game);
void			move_down(t_game *game);
void			move_left(t_game *game);
void			move_right(t_game *game);
void			error_handling(char *str);
int				check_accessible(char **map, int i, int j);
int				count_chars(char **map, int *p, int *e, int width);
int				check_chars(char **map, int width);
int				check_args(int argc, char **argv);
int				check_borders(int fd, t_game *game);
void			image_to_window(t_game *game, int x, int y);
void			clean_old_assets(t_game *game);
void			load_assets(t_game *game);
void			put_image_in_map(t_game *game);
mlx_image_t		*ft_asset_to_image(mlx_t *mlx, char *img_path);
void			get_player_pos(char **map, int *i, int *j, t_game *game);
void			get_map_height_and_width(t_game *game, int fd);
char			**open_map(char **argv, int height);
void			check_map(int argc, char **argv, t_game *game);
char			**get_map(int argc, char **argv, t_game *game);
void			ft_hook(void *param);
void			my_keyhook(mlx_key_data_t keydata, void *param);
void			accessibility(char **map, t_game *game, char **argv);
void			free_map(char **map);
void			check_leaks(void);
void			move(t_game *game, int dy, int dx);

# ifndef LEAKS
#  define LEAKS 0
# endif

#endif