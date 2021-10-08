#include "../../include/cub3d.h"

static void	check_texture_time(char *prefix, t_cub *cub)
{
	size_t	pref_len;

	pref_len = ft_strlen(prefix);
	if (ft_strnstr(prefix, "NO", pref_len) && cub->NO != NULL)
		write_error(NO_VALUE_EXIST_TWICE, "NO_VALUE_EXIST_TWICE");
	else if (ft_strnstr(prefix, "SO", pref_len) && cub->SO!= NULL)
		write_error(SO_VALUE_EXIST_TWICE, "SO_VALUE_EXIST_TWICE");
	else if (ft_strnstr(prefix, "WE", pref_len) && cub->WE != NULL)
		write_error(WE_VALUE_EXIST_TWICE, "WE_VALUE_EXIST_TWICE");
	else if (ft_strnstr(prefix, "EA", pref_len) && cub->EA != NULL)
		write_error(EA_VALUE_EXIST_TWICE, "EA_VALUE_EXIST_TWICE");
	else if (ft_strnstr(prefix, "S", pref_len) && cub->Sprite != NULL)
		write_error(SPRITE_EXIST_TWICE, "SPRITE_EXIST_TWICE");
}

char	*get_pure_texture(char *s, char *prefix, t_cub *cub)
{
	size_t	s_len;
	size_t	p_len;
	size_t	i;
	char	*tmp_1;
	char	*tmp_2;

	i = 0;
	check_texture_time(prefix, cub);
	s_len = ft_strlen(s);
	p_len = ft_strlen(prefix);
	if (s_len < p_len)
		write_error(TEXTURE_ERROR, "TEXTURE_ERROR");
	tmp_1 = ft_substr(s, p_len + 1, s_len - (p_len + 1));
	tmp_2 = ft_strtrim(tmp_1, " \t");
	free(tmp_1);
	return (tmp_2);
}

void	flood_fill(t_cub *cub, int x, int y, char **tmp_map)
{
	if (x <= 0 || y <= 0 || x >= cub->map_row - 1 || y >= cub->map_col - 1)
		free_cub_exit(INV_MAP, "INV_MAP", cub);

	if(cub->map[x][y] == '2' && tmp_map[x][y] != 'x')
	{
		printf("cub->sprite_num = %d\n", cub->sprite_num);
		printf("x = %d, y = %d\n",x, y);
		cub->sprite[cub->sprite_num].x = x;
		cub->sprite[cub->sprite_num].y = y;
		cub->sprite_num++;
	}
	tmp_map[x][y] = 'x';
	if (x < cub->map_row - 1 && tmp_map[x + 1][y] != 'x' && cub->map[x + 1][y] != '1')
		flood_fill(cub, x + 1, y, tmp_map);
	if (y < cub->map_col - 1 && tmp_map[x][y + 1] != 'x' && cub->map[x][y + 1] != '1')
		flood_fill(cub, x, y + 1, tmp_map);
	if (x > 0 && tmp_map[x - 1][y] != 'x' && cub->map[x - 1][y] != '1')
		flood_fill(cub, x - 1, y, tmp_map);
	if (y > 0 && tmp_map[x][y - 1] != 'x' && cub->map[x][y - 1] != '1')
		flood_fill(cub, x, y - 1, tmp_map);
}