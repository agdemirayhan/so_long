/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:25:08 by aagdemir          #+#    #+#             */
/*   Updated: 2024/06/30 12:00:33 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
int	main(void)
{
	void *mlx;
	void *mlx_win;
	t_data img;
	int i;
	int j;

	i = 0;
	j=0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while(i<50)
	{
		j = 0;
		while(j<50)
		{
		my_mlx_pixel_put(&img, 50+j, 50+i, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		j++;
		}
	i++;
	}
	mlx_loop(mlx);
}