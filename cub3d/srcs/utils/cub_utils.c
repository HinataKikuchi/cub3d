#include "../../include/cub3d.h"

void	safe_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

int	check_row(char **s, int n)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (i != n)
		return (0);
}

void	free_double_pointer(char **s)
{
	int i;

	i = 0;
	while (s[i])
		safe_free(s[i++]);
	free(s);
	s = NULL;
}

void	free_cub_struct(int error_num, t_cub *cub)
{
	free(cub->NO);
	free(cub->SO);
	free(cub->WE);
	free(cub->EA);
	free(cub->Sprite);
	if (error_num != MAP_MALLOC_ERROR && error_num != OPEN_ERROR\
	&& error_num != GNL_ERROR && error_num != INV_FILE)
		safe_free(cub->map);
}

void	free_pos_struct(int error_num, t_pos *pos)
{
	int i;
	free_cub_struct(error_num, &pos->cub);
	i = 0;
	while (pos->cub.buf[i])
		safe_free(pos->cub.buf[i++]);
	safe_free(pos->cub.buf);
	i = 0;
	if (error_num != POS_TEX_MALLOC_ERROR && error_num < 26 && 30 < error_num)
	{
		while (pos->cub.texture[i])
			safe_free(pos->cub.texture[i++]);
		safe_free(pos->cub.texture);
	}
}

int		count_all_sprite(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j]=='2')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}