#include "../include/cub3d.h"

void	draw_img(t_pos *pos)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < pos->cub.R_y)
	{
		while (j < pos->cub.R_x)
		{
			pos->img.val[i * pos->cub.R_x + j]  = pos->cub.buf[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(pos->vars.mlx, pos->vars.win, pos->img.img, 0, 0);
}
