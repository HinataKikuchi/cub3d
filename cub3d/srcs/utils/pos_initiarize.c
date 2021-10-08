#include "../../include/cub3d.h"

static void	load_image(t_pos *pos, int *texture, char *path, t_data *img)
{
	int i;
	int j;

	i = 0;
	j = 0;
	img->img = mlx_xpm_file_to_image(pos->vars.mlx, path, &img->img_width, &img->img_height);
	if (img->img_height > texHeight || img->img_width > texWidth)
		free_pos_exit(OVER_TEX_SIZE, "OVER_TEX_SIZE", pos);
	img->val = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	while (i < img->img_height)
	{
		while(j < img->img_width)
		{
			texture[img->img_width * i + j] = img->val[img->img_width * i + j];
			j++;
		}
		j = 0;
		i++;
	}
	mlx_destroy_image(pos->vars.mlx, img->img);
}

static int check_path(char *path, t_pos *pos)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		free_pos_exit(OPEN_ERROR, "OPEN_ERROR", pos);
	else
		close(fd);
	return (1);
}

static void	load_texture(t_pos *pos)
{
	t_data	data;

	if (check_path(pos->cub.NO, pos))
		load_image(pos, pos->cub.texture[0], pos->cub.NO, &data);
	if (check_path(pos->cub.SO, pos))
		load_image(pos, pos->cub.texture[1], pos->cub.SO, &data);
	if (check_path(pos->cub.EA, pos))
		load_image(pos, pos->cub.texture[2], pos->cub.EA, &data);
	if (check_path(pos->cub.WE, pos))
		load_image(pos, pos->cub.texture[3], pos->cub.WE, &data);
	if (check_path(pos->cub.Sprite, pos))
		load_image(pos, pos->cub.texture[4], pos->cub.Sprite, &data);
}

void	pos_set_value(t_pos *pos)
{
	pos->posX = pos->cub.position[0];
	pos->posY = pos->cub.position[1];
	pos->dirX = -1.0;
	pos->dirY = 0.0;
	pos->planeX = 0.0;
	pos->planeY = 0.66;
	pos->moveSpeed = 0.1;
	pos->rotSpeed = 0.1;
}

static void	pos_buf_malloc(t_pos *pos)
{
	int	i;

	i = 0;
	pos->cub.buf = ft_calloc(sizeof(int *), pos->cub.R_x);
	if (!pos->cub.buf)
		free_cub_exit(MALLOC_ERROR, "MALLOC_ERROR", &pos->cub);
	while (i < pos->cub.R_y)
	{
		pos->cub.buf[i] = ft_calloc(sizeof(int *), pos->cub.R_y);
		if (!pos->cub.buf[i])
			free_cub_exit(MALLOC_ERROR, "MALLOC_ERROR", &pos->cub);
		i++;
	}
}

static void	pos_tex_malloc(t_pos *pos)
{
	int	i;

	i = 0;
	pos->cub.texture = ft_calloc(texNUM + spriteNUM, sizeof(int *));
	if(!pos->cub.texture)
		free_pos_exit(POS_TEX_MALLOC_ERROR, "POS_TEXTURE_MALLOC_ERROR", pos);
	while (i < (texNUM + spriteNUM))
	{
		pos->cub.texture[i] = (int *)ft_calloc((texWidth * texHeight), sizeof(int));
		if(!pos->cub.texture[i])
			free_pos_exit(POS_TEX_MALLOC_ERROR, "POS_TEXTURE_MALLOC_ERROR", pos);
		i++;
	}
}

void	pos_initialize(t_pos *pos)
{
	pos_buf_malloc(pos);
	pos_tex_malloc(pos);
	pos->zBuffer = ft_calloc(pos->cub.R_x, sizeof(double));
	if (!pos->zBuffer)
		free_pos_exit(MALLOC_ERROR, "MALLOC_ERROR", pos);
	pos_set_value(pos);
	load_texture(pos);
	pos->img.img = mlx_new_image(pos->vars.mlx, pos->cub.R_x, pos->cub.R_y);
	pos->img.val = (int *)mlx_get_data_addr(pos->img.img, &pos->img.bits_per_pixel, &pos->img.line_length, &pos->img.endian);
}