/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:02:18 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/05/20 17:28:09 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stddef.h>
/*
** LIBS HEADER
*/
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../gnl/get_next_line.h"
/*
** MY FUNCS HEADER
*/
# include "error.h"
# include "cub_value.h"
# include "cub_calc.h"
# include "cub_key.h"
# include "cub_utils.h"
/*
** DEFINE VALUES
*/
# define texHeight 64
# define texWidth 64
# define texNUM 4
# define spriteNUM 1

typedef struct s_map
{
	double	cameraX;

	double	rayDirX;
	double	rayDirY;

	int		mapX;
	int		mapY;

	int		stepX;
	int		stepY;

	double	sideDistX;
	double	sideDistY;

	double	deltaDistX;
	double	deltaDistY;

	double	perpWallDist;

	int		lineHeight;

	int		drawStart;
	int		drawEnd;

	double	step;
	double	texPos;
	int		tex_num;

	int		texX;
	int		texY;
}				t_map;

/*
** SAVE TEXTURE VALUES
*/
typedef struct	s_data
{
	void	*img;
	int		*val;

	int		line_length;
	int		bits_per_pixel;
	int		endian;
	int		img_width;
	int		img_height;

	char	*addr;
}				t_data;

/*
** TO GET SCREEN SIZE
*/
typedef struct	s_win
{
	int	size_x;
	int	size_y;
}				t_win;

/*
** SAVE MLX VALUES
*/
typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

/*
** SPRITE INFOMATION
*/
typedef struct	s_sprite
{
	int	x;
	int	y;
	double	dist;
}				t_sprite;

/*
** SAVE CUB FILE'S VALUES
*/
typedef struct s_cub
{
	int		R_x;
	int		R_y;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;

	char	*Sprite;
	int		F[3];
	int		C[3];

	char	**map;
	int		map_row;
	int		map_col;
	int		**texture;
	int		**buf;
	int		position[2];
	int		sprite_num;
	t_sprite	*sprite;
}				t_cub;

/*
** SAVE POSITION VALUES
*/
typedef struct	s_pos
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	moveSpeed;
	double	rotSpeed;
	double	*zBuffer;
	t_vars	vars;
	t_cub	cub;
	t_data	img;
}				t_pos;

/*
** INITIARIZE VALUES FUNCTION
*/
void	pos_initialize(t_pos *pos);
t_cub	cub_initialize(void);

/*
** FREE STRUCT FUNCTION
*/
void	free_cub_struct(int error_num, t_cub *cub);
void	free_pos_struct(int error_num, t_pos *pos);
void	free_cub_exit(int error_num, char *message, t_cub *cub);
void	free_pos_exit(int error_num, char *message, t_pos *pos);
void	free_struct(t_cub *cub);

/*
** GET STRUCT VALUES
*/
int		get_cub_value(char *file_name, int argc, t_cub *cub, t_vars *var);
void	get_map(char *file_path, t_cub *cub);
void	pos_set_value(t_pos *pos);
char	*get_pure_texture(char *s, char *prefix, t_cub *cub);
void	get_screen_size(t_cub *cub, t_vars *vars);

/*
** CHECK VALUES
*/
int		judge_map(char *buf);
void	check_map(t_cub *cub);
int		count_all_sprite(char **map);
void	check_texture_xpm(t_cub *cub);
void	flood_fill(t_cub *cub, int x, int y, char **tmp_map);

/*
** KEY ACTION
*/
int	key_press(int key_code, t_pos *pos);
int	key_hook(int keycode, t_vars *vars);
int	x_button(t_vars *vars);

/*
** CALC POSITION
*/
int	main_loop(t_pos *pos);
void	write_page(t_pos *pos);
void	calc_pos_ini_val(t_map *map, t_pos *pos, int i);
void	calc_step(t_map *map, t_pos *pos);
int		calc_hit(t_map *map, t_pos *pos, int *side);
void	calc_drawES(t_map *map, t_pos *pos, int side);
void	calc_texX(t_map *map, t_pos *pos, int side);
void	calc_texture(t_map *map, t_pos *pos, int x, int side);

/*
** CALC SPRITE
*/
void	sprite_sort(t_pos *pos);


/*
** UTILS
*/
int		create_trgb(int t, int r, int g, int b);
double	cub_abs(double n);


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	screen();
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	verLine(t_pos *pos/*, t_data *data */,int x, int y1, int y2, int color);
void	draw_img(t_pos *pos);
t_map	initial_map_data(t_pos pos, int x);
void	set_step(t_map *map, t_pos pos);
int	get_hit(t_map *map, t_pos pos, int *side);
void	judge_side(t_map *map, t_pos pos, int side);
void	get_drawStart_drawEnd(t_map *map, t_pos pos);
void	write_texture(t_map *map, t_pos *pos, int i, int tex_n, int side);
void	get_texX(t_map *map, t_pos pos, int side);





#endif