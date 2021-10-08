/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_hundling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:28:31 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/05/20 13:29:35 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../include/error.h"

void	write_error(int error_num, char *message)
{
	if (error_num == 1)
		return ;
	printf("ERROR : %s\n",message);
	exit(0);
}

void	free_cub_exit(int error_num, char *message, t_cub *cub)
{
	free_cub_struct(error_num, cub);
	write_error(error_num, message);
}

void	free_pos_exit(int error_num, char *message, t_pos *pos)
{
	free_pos_struct(error_num, pos);
	write_error(error_num, message);
}

void	check_file(char *s, int file_num)
{
	if (file_num > 3 || file_num <= 1)
		write_error(LESS_ARGS, "LESS_ARGS");
	if (check_extention(s, ".cub") == INV_FILE)
		write_error(INV_FILE, "INV_FILE");
}