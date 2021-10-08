#include "../include/cub3d.h"

static void	key_Up(t_pos *pos)
{
	if (pos->cub.map[(int)(pos->posX + pos->dirX * pos->moveSpeed)][(int)pos->posY] == '0')
		pos->posX += pos->dirX * pos->moveSpeed;
	if (pos->cub.map[(int)pos->posX][(int)(pos->posY + pos->dirY * pos->moveSpeed)] == '0')
		pos->posY += pos->dirY * pos->moveSpeed;
}

static void	key_Down(t_pos *pos)
{
	if (pos->cub.map[(int)(pos->posX - pos->dirX * pos->moveSpeed)][(int)(pos->posY)] == '0')
		pos->posX -= pos->dirX * pos->moveSpeed;
	if (pos->cub.map[(int)pos->posX][(int)(pos->posX - pos->dirX * pos->moveSpeed)] == '0')
		pos->posY -= pos->dirY * pos->moveSpeed;

}

static void	key_Right(t_pos *pos)
{
	double oldDirX = pos->dirX;
	pos->dirX = pos->dirX * cos(-pos->rotSpeed) - pos->dirY * sin(-pos->rotSpeed);
	pos->dirY = oldDirX * sin(-pos->rotSpeed) + pos->dirY * cos(-pos->rotSpeed);
	double oldplaneX = pos->planeX;
	pos->planeX = pos->planeX * cos(-pos->rotSpeed) - pos->planeY * sin(-pos->rotSpeed);
	pos->planeY = oldplaneX * sin(-pos->rotSpeed) + pos->planeY * cos(-pos->rotSpeed);
}

static void	key_Left(t_pos *pos)
{
	double oldDirX;
	double oldplaneX;

	oldDirX = pos->dirX;
	pos->dirX = pos->dirX * cos(pos->rotSpeed) - pos->dirY * sin(pos->rotSpeed);
	pos->dirY = oldDirX * sin(pos->rotSpeed) + pos->dirY * cos(pos->rotSpeed);
	oldplaneX = pos->planeX;
	pos->planeX = pos->planeX * cos(pos->rotSpeed) - pos->planeY * sin(pos->rotSpeed);
	pos->planeY = oldplaneX * sin(pos->rotSpeed) + pos->planeY * cos(pos->rotSpeed);
}

int		key_press(int key_code, t_pos *pos)
{
	if (key_code == UP || key_code == W)
		key_Up(pos);
	if (key_code == DOWN || key_code == S)
		key_Down(pos);
	if (key_code == RIGHT || key_code == D)
		key_Right(pos);
	if (key_code == LEFT || key_code == A)
		key_Left(pos);
	if (key_code == ESC)
		exit(0);
	return (0);
}