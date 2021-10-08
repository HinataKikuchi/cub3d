/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HINATA <HINATA@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:24:38 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/10/01 12:07:04 by HINATA           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../gnl/get_next_line.h"
// #include "../include/cub_key.h"
// #include "../include/cub_calc.h"
// #include "../include/cub_value.h"


int	main(int argc, char **argv)
{
	t_pos pos;
	int		i = 0;

	pos.cub = cub_initialize();
	pos.vars.mlx = mlx_init();
	if (!pos.vars.mlx)
		write_error(MLX_INIT_ERROR, "MLX_INIT_ERROR");
	printf("%d\n",get_cub_value(argv[1], argc, &(pos.cub), &(pos.vars)));
	
// // printf("R %d %d\n",pos.cub.R_x, pos.cub.R_y);
	// printf("NO %s\nSO %s\nWE %s\nEA %s\n",pos.cub.NO, pos.cub.SO, pos.cub.WE, pos.cub.EA);
	// printf("S %s\n",pos.cub.Sprite);
	// printf("F %d,%d,%d\n",pos.cub.F[0],pos.cub.F[1], pos.cub.F[2]);
	// printf("C %d,%d,%d\n",pos.cub.C[0], pos.cub.C[1], pos.cub.C[2]);
	// while (pos.cub.map[i])
	// 	printf("%s\n",pos.cub.map[i++]);
	// i = 0;
	// printf("sprit are %d", pos.cub.sprite_num);
	// printf("map_col = %d, map_low = %d\n",pos.cub.map_col,pos.cub.map_row);
	// i = 0;
	pos.vars.win = mlx_new_window(pos.vars.mlx, pos.cub.R_x, pos.cub.R_y, "mlx");
	if (!pos.vars.mlx || !pos.vars.win)
		free_cub_exit(MLX_WIN_ERROR, "MLX_WIN_ERROR", &pos.cub);
	pos_initialize(&pos);
	pos.cub.map[pos.cub.position[0]][pos.cub.position[1]] = '0';
	// while (i < pos.cub.sprite_num){
	// 	printf("sprite[%d] at x = %d, y = %d\n", i, pos.cub.sprite[i].x, pos.cub.sprite[i].y);
	// 	i++;
	// }
	// sprite_sort(&pos);
	// // i = 0;
	// printf("sorted \n");
	// while (i<pos.cub.sprite_num){
	// 	printf("sprite[%d] at x = %d, y = %d\n", i, pos.cub.sprite[i].x, pos.cub.sprite[i].y);
	// 	i++;
	// }
	// exit(0);
	// write_page(&pos);
	mlx_loop_hook(pos.vars.mlx, &main_loop, &pos);
	mlx_hook(pos.vars.win, 33, 1L<<17, &x_button, &pos.vars);
	mlx_hook(pos.vars.win, 2, 1L<<0, &key_hook, &pos.vars);
	mlx_hook(pos.vars.win,2, 1L<<0, &key_press, &pos);
	mlx_loop(pos.vars.mlx);
}