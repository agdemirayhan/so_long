/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:54:07 by aagdemir          #+#    #+#             */
/*   Updated: 2024/07/06 11:54:24 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # define RED "\033[1m\033[31m"
// # define GREEN "\033[1m\033[32m"
// # define ENDC "\033[0m"
// # define BOLDRED "\033[31m"
// # define UP 13
// # define DOWN 1
// # define LEFT 0
// # define RIGHT 2
// # define ESC 53
// # define SIZE 48

typedef struct s_assets
{
	mlx_image_t	*hut;
	mlx_image_t	*lumberjack;
	mlx_image_t	*wall;
	mlx_image_t	*tree;
	mlx_image_t	*terrain;
} t_assets;

typedef struct s_game
{
	mlx_t		*mlx;
	t_assets	assets;
}				t_game;

#endif