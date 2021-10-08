/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:42:40 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/05/20 17:39:13 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/cub_calc.h"

static t_map	map_initial_value(void)
{
	t_map res;

	res.cameraX = 0.;
	res.rayDirX = 0.5;
	res.rayDirY = 0.5;
	res.mapX = 0;
	res.mapY = 0;
	res.stepX = 0;
	res.stepY = 0;
	res.sideDistX = 0;
	res.sideDistY = 0;
	res.deltaDistX = 0;
	res.deltaDistY = 0;
	res.perpWallDist = 0;
	res.lineHeight = 0;
	res.drawStart = 0;
	res.drawEnd = 0;
	res.step = 0;
	res.texPos = 0;
	res.tex_num = 0;
	res.texX = 0;
	res.texY = 0;
	return (res);
}

void	write_page(t_pos *pos)
{
	int		i;
	int		hit;
	int		side;
	t_map	map;

	i = 0;
	map = map_initial_value();
	while (i < pos->cub.R_x)
	{
		calc_pos_ini_val(&map, pos, i);
		hit = 0;
		calc_step(&map, pos);
		while (hit == 0)
			hit = calc_hit(&map, pos, &side);
		calc_drawES(&map, pos, side);
		calc_texX(&map, pos, side);
		calc_texture(&map, pos, i, side);
		pos->zBuffer[i] = map.perpWallDist;
		i++;
	}
}

int	main_loop(t_pos *pos)
{
	write_page(pos);
	draw_img(pos);
	return (0);
}

