#include "../include/cub3d.h"

void	sprite_sort(t_pos *pos)
{
	int	i;
	int	j;
	t_sprite tmp;

	i = 0;
	while (i < pos->cub.sprite_num)
		pos->cub.sprite[i++].dist = \
		pow((pos->posX - (double)pos->cub.sprite[i].x), 2.0) \
		+ pow((pos->posY - (double)pos->cub.sprite[i].y), 2.0);
	i = 0;
	j = 0;
	while(i < pos->cub.sprite_num)
	{
		while (j < pos->cub.sprite_num)
		{
			if (pos->cub.sprite[i].dist > pos->cub.sprite[j].dist)
			{
				tmp = pos->cub.sprite[i];
				pos->cub.sprite[i] = pos->cub.sprite[j];
				pos->cub.sprite[j] = tmp;
			}
			j++;
		}
		j = i + 1;
		i++;
	}
}
