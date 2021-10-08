#include "../../include/cub3d.h"
#include "../../include/error.h"

int	check_extention(char *s, char *ext)
{
	size_t	s_len;
	size_t	ext_len;
	size_t	i;
	char	*prefix;

	ext_len = ft_strlen(ext);
	s_len = ft_strlen(s);
	if (s_len <= ext_len)
		return (INV_FILE);
	i = 0;
	while (s[s_len - ext_len + i] == ext[i] && i < ext_len)
		i++;
	if (i == ext_len)
		return (1);
	else
		return (INV_FILE);
}

void	check_texture_xpm(t_cub *cub)
{
	char	*ext;

	ext = ".xpm";
	if (check_extention(cub->NO, ext) == INV_FILE)
		write_error(NO_TEXTURE_ERROR, "NO_TEXTURE_ERROR");
	if (check_extention(cub->SO, ext) == INV_FILE)
		write_error(SO_TEXTURE_ERROR, "SO_TEXTURE_ERROR");
	if (check_extention(cub->WE, ext) == INV_FILE)
		write_error(WE_TEXTURE_ERROR, "WE_TEXTURE_ERROR");
	if (check_extention(cub->EA, ext) == INV_FILE)
		write_error(EA_TEXTURE_ERROR, "EA_TEXTURE_ERROR");
}

static char	**get_map_start(t_cub *cub, int *count)
{
	char	**tmp;
	int	i;
	int	j;

	i = 0;
	j = 0;

	tmp = malloc(sizeof(char *) * cub->map_row + 1);
	while (cub->map[i])
	{
		tmp[i] = ft_strdup(cub->map[i]);
		while (j < ft_strlen(cub->map[i]))
		{
			if (ft_strchr("SNWE", cub->map[i][j]))
			{
				cub->position[0] = i;
				cub->position[1] = j;
				(*count)++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

void	check_map(t_cub *cub)
{
	char	**tmp;
	int		count;
	int		cub_num;

	count = 0;
	tmp = get_map_start(cub, &count);
	cub_num = count_all_sprite(cub->map);
	cub->sprite = malloc(sizeof(t_sprite) * (cub_num + 1));
	if (!cub->position[0] && !cub->position[1])
		free_cub_exit(NO_START_POS, "NO_START_POS",cub);
	if (count > 1)
		free_cub_exit(SOMME_STARTS_ARE_EXIST, "SOMME_STARTS_ARE_EXIST", cub);
	flood_fill(cub, cub->position[0], cub->position[1], tmp);\
	printf("x=%dy=%d\n",cub->sprite[0].x, cub->sprite[0].y);
	free_double_pointer(tmp);
}
