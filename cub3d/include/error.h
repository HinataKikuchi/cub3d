/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:36:23 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/05/20 13:09:15 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# define LESS_ARGS 2
# define INV_FILE 3
# define MLX_WIN_ERROR 4
# define MALLOC_ERROR 5
# define MAP_VALUE_ERROR 6
# define TOO_MANY_ARGS_IN_F_C 7
# define GNL_ERROR 8
# define INV_MAP 9
# define NO_START_POS 10
# define MLX_INIT_ERROR 11
# define MAP_MALLOC_ERROR 12
# define NO_TEXTURE_ERROR 13
# define SO_TEXTURE_ERROR 14
# define WE_TEXTURE_ERROR 15
# define EA_TEXTURE_ERROR 16
# define TEXTURE_ERROR 17
# define POS_TEX_MALLOC_ERROR 18
# define CANNOT_OPEN_XPM 19
# define OVER_TEX_SIZE 20
# define SOMME_STARTS_ARE_EXIST 21
# define OPEN_ERROR 22
# define R_VALUE_EXIST_TWICE 23
# define F_VALUE_EXIST_TWICE 24
# define C_VALUE_EXIST_TWICE 25
# define NO_VALUE_EXIST_TWICE 26
# define SO_VALUE_EXIST_TWICE 27
# define EA_VALUE_EXIST_TWICE 28
# define WE_VALUE_EXIST_TWICE 29
# define SPRITE_EXIST_TWICE 30




void	write_error(int error_num, char *message);
void	check_file(char *s, int file_num);
int	check_extention(char *s, char *ext);


#endif
