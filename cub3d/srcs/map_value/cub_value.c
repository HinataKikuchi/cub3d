#include "../../include/cub3d.h"

static void	get_R_value(char *buf, t_cub *cub)
{
	int		i;
	char	**res;

	if (cub->R_x != -1)
		write_error(R_VALUE_EXIST_TWICE, "R_VALUE_EXIST_TWICE");
	if (ft_strchr(buf, '\t'))
		res = ft_split(buf, '\t');
	else
		res = ft_split(buf, ' ');
	if (!res)
		write_error(MALLOC_ERROR, "MALLOC_ERROR");
	if (!check_row(res, 3))
	{
		free_double_pointer(res);
		write_error(MAP_VALUE_ERROR, "R_INFO_ERROR");
	}
	cub->R_x = ft_atoi(res[1]);
	cub->R_y = ft_atoi(res[2]);
	free_double_pointer(res);
}

static char	**get_FC_value(char *buf, t_cub *cub)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	i = 0;
	k = 0;
	tmp = malloc(sizeof(char *) * 4);
	if (!tmp)
		write_error(MALLOC_ERROR, "MALLOC_ERROR");
	while (buf[i] != '\0')
	{
		if (ft_isdigit(buf[i]))
		{
			j = 0;
			while ((buf[i + j] != ',' && buf[i + j] != ' ' \
			&& buf[i + j] != '\t') && buf[i + j] != '\0')
				j++;
			tmp[k++] = ft_substr(buf, i, j);
			i = i + j;
		}
		if (k > 4)
			write_error(TOO_MANY_ARGS_IN_F_C, "TOO_MANY_ARGS_IN_F_C");
		i++;
	}
	tmp[k] = NULL;
	return (tmp);
}

static void	get_rfc_value(char *buf, t_cub *cub)
{
	size_t	buf_len;
	char	**tmp;
	int		i;

	buf_len = ft_strlen(buf);
	if (ft_strnstr(buf, "R", buf_len))
		get_R_value(buf, cub);
	else if (ft_strnstr(buf, "F", buf_len))
	{
		if (cub->F[0] != -1)
			write_error(F_VALUE_EXIST_TWICE, "F_VALUE_EXIST_TWICE");
		tmp = get_FC_value(buf, cub);
		if (!check_row(tmp, 3))
		{
			free_double_pointer(tmp);
			write_error(MAP_VALUE_ERROR, "MAP_VALUE_ERROR");
		}
		i = 0;
		while (i < 3)
			cub->F[i++] = ft_atoi(tmp[i]);
		free_double_pointer(tmp);
	}
	else if (ft_strnstr(buf, "C", buf_len))
	{
		if (cub->C[0] != -1)
			write_error(C_VALUE_EXIST_TWICE, "C_VALUE_EXIST_TWICE");
		tmp = get_FC_value(buf, cub);
		if (!check_row(tmp, 3))
		{
			free_double_pointer(tmp);
			write_error(MAP_VALUE_ERROR, "MAP_VALUE_ERROR");
		}
		i = 0;
		while (i < 3)
			cub->C[i++] = ft_atoi(tmp[i]);
		free_double_pointer(tmp);
	}
}

static void	judge_value(char *buf, t_cub *cub)
{
	size_t	buf_len;
	int		res;

	res = 1;
	buf_len = ft_strlen(buf);
	if (ft_strnstr(buf, "R", buf_len) || \
	ft_strnstr(buf, "F", buf_len) || ft_strnstr(buf, "C", buf_len))
		get_rfc_value(buf, cub);
	else if (ft_strnstr(buf, "NO", buf_len))
		cub->NO = get_pure_texture(buf, "NO", cub);
	else if (ft_strnstr(buf, "SO", buf_len))
		cub->SO = get_pure_texture(buf, "SO", cub);
	else if (ft_strnstr(buf, "WE", buf_len))
		cub->WE = get_pure_texture(buf, "WE", cub);
	else if (ft_strnstr(buf, "EA", buf_len))
		cub->EA = get_pure_texture(buf, "EA", cub);
	else if (buf[0] == 'S')
		cub->Sprite = get_pure_texture(buf, "S", cub);
	else if (judge_map(buf))
		cub->map_row++;
	free(buf);
}

int	get_cub_value(char *file_name, int argc, t_cub *cub, t_vars *var)
{
	int		res;
	char	*buf;
	size_t	buf_len;
	int		fd;

	check_file(file_name, argc);
	fd = open(file_name, O_RDONLY);
	res = get_next_line(fd, &buf);
	cub->map_row = 0;
	while (res)
	{
		judge_value(buf, cub);
		if (res == (-1))
			write_error(GNL_ERROR, "GNL_ERROR");
		res = get_next_line(fd, &buf);
	}
	judge_value(buf, cub);
	close(fd);
	get_screen_size(cub, var);
	get_map(file_name, cub);
	check_map(cub);
	check_texture_xpm(cub);
	return (res);
}
