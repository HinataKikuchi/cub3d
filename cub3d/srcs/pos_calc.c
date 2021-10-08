#include "../include/cub3d.h"

void	calc_pos_ini_val(t_map *map, t_pos *pos, int i)
{
	map->cameraX = 2 * i / (double)(pos->cub.R_x) - 1;
	map->rayDirX = pos->dirX + pos->planeX * map->cameraX ;
	map->rayDirY = pos->dirY + pos->planeY * map->cameraX;

	map->mapX = (int)pos->posX;
	map->mapY = (int)pos->posY;

	map->deltaDistX = fabs(1 / map->rayDirX);
	map->deltaDistY = fabs(1 / map->rayDirY);
}

void	calc_step(t_map *map, t_pos *pos)
{
	if (map->rayDirX < 0)
	{
		map->stepX = -1;
		map->sideDistX = (pos->posX - map->mapX) * map->deltaDistX;
	}
	else
	{
		map->stepX = 1;
		map->sideDistX = (map->mapX + 1.0 - pos->posX) * map->deltaDistX;
	}
	if (map->rayDirY < 0)
	{
		map->stepY = -1;
		map->sideDistY = (pos->posY - map->mapY) * map->deltaDistY;
	}
	else
	{
		map->stepY = 1;
		map->sideDistY = (map->mapY + 1.0 - pos->posY) * map->deltaDistY;
	}
}

int	calc_hit(t_map *map, t_pos *pos, int *side)
{
	if (map->sideDistX < map-> sideDistY)
	{
		map->sideDistX += map->deltaDistX;
		map->mapX += map->stepX;
		*side = 0;
	}
	else
	{
		map->sideDistY += map->deltaDistY;
		map->mapY += map->stepY;
		*side = 1;
	}
	if (pos->cub.map[map->mapX][map->mapY] == '1' || pos->cub.map[map->mapX][map->mapY] == '2')
		return (1);
	else
		return (0);
}

void	calc_drawES(t_map *map, t_pos *pos, int side)
{
	if (side == 0)
		map->perpWallDist = (map->mapX - pos->posX + (1 - map->stepX) / 2) / map->rayDirX;
	else
		map->perpWallDist = (map->mapY - pos->posY + (1 - map->stepY) / 2) / map->rayDirY;
	map->lineHeight = (int)(pos->cub.R_y / map->perpWallDist);

	map->drawStart = - map->lineHeight / 2 + pos->cub.R_y / 2;
	if (map->drawStart < 0)
		map->drawStart = 0;
	map->drawEnd = map->lineHeight / 2 + pos->cub.R_y / 2;
	if (map->drawEnd >= pos->cub.R_y)
		map->drawEnd = pos->cub.R_y - 1;
	// if (map->stepY > 0 && map->stepX > 0)
	// 	map->tex_num = 0;
	// else if (map->stepY < 0 && map->stepX < 0)
	// 	map->tex_num = 1;
	// else if (map->stepX > 0 && map->stepY < 0)
	// 	map->tex_num = 2;
	// else
	// 	map->tex_num = 3;
}

void	calc_texX(t_map *map, t_pos *pos, int side)
{
	double wallX;

	if (side == 0)
		wallX = pos->posY + map->perpWallDist * map->rayDirY;
	else
		wallX = pos->posX + map->perpWallDist * map->rayDirX;
	wallX -= floor(wallX);
	map->texX = (int)(wallX * (double)texWidth);
	if (side == 0 && map->rayDirX > 0)
		map->texX = texWidth - map->texX - 1;
	if (side == 0 && map->rayDirY < 0)
		map->texX = texWidth - map->texX - 1;
}

void	calc_texture(t_map *map, t_pos *pos, int x, int side)
{
	int		y;
	int		color;

	map->step = 1.0 * texHeight / map->lineHeight;
	map->texPos = (map->drawStart - (pos->cub.R_y / 2) + (map->lineHeight / 2)) * map->step;
	y = 0;
	while (y < map->drawStart)
	{
		pos->cub.buf[y][x] = create_trgb(1, pos->cub.C[0], pos->cub.C[1], pos->cub.C[2]);
		y++;
	}
	while (y < map->drawEnd)
	{
		map->texY = (int)map->texPos & (texHeight - 1);
		map->texPos += map->step;
		color = pos->cub.texture[map->tex_num][texHeight * map->texY + map->texX];
		if (side == 1)
			color = (color >> 1) & 8355711;
		pos->cub.buf[y][x] = color;
		y++;
	}
	while (y < pos->cub.R_y)
	{
		pos->cub.buf[y][x] = create_trgb(1, pos->cub.F[0], pos->cub.F[1], pos->cub.F[2]);
		y++;
	}
}